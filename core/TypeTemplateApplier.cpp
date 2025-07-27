#include "TypeTemplateApplier.hpp"

#include "TypeTemplate.hpp"
#include "TypeTemplateValue.hpp"
#include "TypeTemplateError.hpp"
#include "TypeTemplateContext.hpp"

#include "Lookup.hpp"
#include "Database.hpp"
#include "Mods.hpp"
#include "Localization.hpp"
#include "Locale.hpp"
#include "TypeTemplateValidator.hpp"
#include "Artifacts.hpp"

using namespace nejlika;

TypeTemplateApplier::TypeTemplateApplier() {
    m_ExtentionFunctions = {};
}

TypeTemplateError nejlika::TypeTemplateApplier::Apply(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object& json,
    const TypeTemplate& typeTemplate,
    const std::unordered_map<std::string,TypeTemplateValue>& parameters,
    const std::function<void(const TypeTemplateError&)>& onFinished) const
{
    std::string action;

    if (!json.contains("action"))
    {
        // Pick the first action if none is specified
        action = typeTemplate.GetActions().begin()->first;
    }
    else
    {
        action = json.at("action").as_string().c_str();
    }

    const auto& actions = typeTemplate.GetActions();

    if (!actions.contains(action))
    {
        std::stringstream ss;
        ss << "TypeTemplateApplier::Apply: Action '" << action << "' not found in template '" << typeTemplate.GetName() << "'.";

        return TypeTemplateError(ss.str());
    }

    const auto& actionTemplate = actions.at(action);

    const auto& prepareActions = actionTemplate->GetPrepareOperations();

    for (const auto& prepareAction : prepareActions)
    {
        const auto error = ApplyOperation(context, prepareAction, json, typeTemplate, parameters);

        if (!error.IsSuccess())
        {
            return error;
        }
    }

    const auto dependencies = typeTemplate.GetDependencies(context->GetContext().templates, json);

    context->GetContext().lookup->AwaitValues(dependencies, [
        this, &actionTemplate, &context, &json, &typeTemplate, &parameters, onFinished
    ]() {
        const auto& applyOperations = actionTemplate->GetApplyOperations();

        for (const auto& applyOperation : applyOperations)
        {
            TypeTemplateError error = TypeTemplateError::Success;

            try
            {
                error = ApplyOperation(context, applyOperation, json, typeTemplate, parameters);
            }
            catch (const std::exception& e)
            {
                //error = ApplyOperation(context, applyOperation, json, typeTemplate, parameters);

                std::stringstream ss;

                ss << "Failed to apply operation: " << e.what();

                ss << " in template '" << typeTemplate.GetName() << "', action '" << actionTemplate->GetName() << "'.";

                ss << " Operation: " << boost::json::serialize(applyOperation);

                error = TypeTemplateError(ss.str());
            }

            if (!error.IsSuccess())
            {
                onFinished(error);
                return;
            }
        }

        context->GetContext().mods->AddAppliedMod(
            json.at("name").as_string().c_str(),
            typeTemplate.GetName()
        );
    });

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyOperation(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    if (!operation.contains("type"))
    {
        return TypeTemplateError("Missing 'type' field.");
    }

    const std::string type = operation.at("type").as_string().c_str();

    if (type == "generate-id")
    {
        return ApplyGenerateOperation(context, operation, json, typeTemplate, parameters);
    }
    if (type == "insert")
    {
        return ApplyInsertOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "update")
    {
        return ApplyUpdateOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "delete")
    {
        return ApplyDeleteOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "select")
    {
        return ApplySelectOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "for-each")
    {
        return ApplyForEachOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "locale")
    {
        return ApplyLocaleOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "cascade")
    {
        return ApplyCascadeOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "assign")
    {
        return ApplyAssignOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "concat")
    {
        return ApplyConcatOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "pop")
    {
        return ApplyPopOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "sql")
    {
        return ApplySQLOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "file-copy")
    {
        return ApplyFileCopyOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "directory-copy")
    {
        return ApplyDirectoryCopyOperation(context, operation, json, typeTemplate, parameters);
    }
    else if (type == "and")
    {
        const auto& operations = operation.at("operations").as_array();

        for (const auto& op : operations)
        {
            const auto error = ApplyOperation(context, op.as_object(), json, typeTemplate, parameters);

            if (!error.IsSuccess())
            {
                return error;
            }
        }

        return TypeTemplateError::Success;
    }
    else
    {
        if (m_ExtentionFunctions.contains(type))
        {
            return m_ExtentionFunctions.at(type)(context, operation, json, typeTemplate, parameters);
        }

        std::stringstream ss;

        ss << "Unknown operation type: " << type;

        return TypeTemplateError(ss.str());
    }
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyGenerateOperation(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const auto& name = json.at("name").as_string().c_str();

    if (operation.contains("require-core-symbol") && operation.at("require-core-symbol").as_bool())
    {
        if (!context->GetContext().lookup->IsCoreSymbol(name))
        {
            std::stringstream ss;

            ss << "Core symbol required for operation this action";

            return TypeTemplateError(ss.str());
        }

        return TypeTemplateError::Success;
    }

    // Get table, column, and variable from operation
    const std::string table = operation.at("table").as_string().c_str();
    const std::string column = operation.at("column").as_string().c_str();
    
    const bool sync = operation.contains("sync") ? operation.at("sync").as_bool() : true;

    id id;

    if (sync && TryResolveName(context->GetContext(), json, id))
    {
        context->GetContext().lookup->Register(name, id);

        if (json.contains("aliases")) {
            const auto& aliases = json.at("aliases");

            if (aliases.is_array())
            {
                for (const auto& alias : aliases.as_array())
                {
                    context->GetContext().lookup->Register(alias.as_string().c_str(), id);
                }
            }
        }

        if (operation.contains("variable")) {
            context->SetVariable(operation.at("variable").as_string().c_str(), boost::json::value(id));
        } else {
            context->SetVariable("id", boost::json::value(id));
        }

        return TypeTemplateError::Success;
    }

    std::stringstream ss;

    /*
    SELECT MIN(t1.id + 1) AS first_gap
    FROM Objects t1
    LEFT JOIN Objects t2
    ON t1.id + 1 = t2.id
    WHERE t2.id IS NULL;
    */
    //ss << "SELECT MIN(t1." << column << " + 1) AS first_gap FROM " << table << " t1 LEFT JOIN " << table << " t2 ON t1." << column << " + 1 = t2." << column << " WHERE t2." << column << " IS NULL;";
    ss << "SELECT MAX(" << column << ") FROM " << table << ";";

    auto stmt = context->GetContext().database->Prepare(ss.str());

    auto result = stmt.execQuery();

    if (result.eof())
    {
        ss.str("");

        ss << "Failed to get max id from table: " << table;

        return TypeTemplateError(ss.str());
    }

    id = result.getIntField(0) + 1;

    while (context->GetContext().lookup->Exists(id))
    {
        id++;
    }

    if (operation.contains("variable")) {
        context->SetVariable(operation.at("variable").as_string().c_str(), boost::json::value(id));
    } else {
        context->SetVariable("id", boost::json::value(id));
    }

    if (sync) {
        context->GetContext().lookup->Register(name, id);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyInsertOperation(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const std::string table = operation.at("table").as_string().c_str();

    const auto& columns = operation.at("columns").as_object();

    std::stringstream ss;

    ss << "INSERT INTO " << table << " (";

    for (const auto& [key, value] : columns)
    {
        ss << key << ", ";
    }

    ss.seekp(-2, std::ios_base::end);

    ss << ") VALUES (";

    for (const auto& column : columns)
    {
        ss << "?, ";
    }

    ss.seekp(-2, std::ios_base::end);

    ss << ");";

    auto stmt = context->GetContext().database->Prepare(ss.str());

    int index = 1;

    for (const auto& [key, value] : columns)
    {
        if (value.is_object())
        {
            const auto& obj = value.as_object();

            const auto& val = obj.at("value");

            const auto& extra = obj.contains("extra") ? obj.at("extra").as_object() : boost::json::object();

            try
            {
                const auto& resolved = context->FindValue(val, TypeTemplateQueryOptions::Full);

                if (resolved.is_null() && obj.contains("nullable") && !obj.at("nullable").as_bool())
                {
                    if (obj.contains("default"))
                    {
                        BindValue(stmt, index, obj.at("default"), extra);

                        index++;

                        continue;
                    }
                    else
                    {
                        throw std::runtime_error("Non-nullable value without default.");
                    }
                }

                BindValue(stmt, index, resolved, extra);
            }
            catch (const std::runtime_error& e)
            {
                if (obj.contains("default"))
                {
                    BindValue(stmt, index, obj.at("default"), extra);
                }
                else
                {
                    std::stringstream ss;

                    ss << "Missing required value for column '" << key << "'.";

                    return TypeTemplateError(ss.str());
                }
            }

            index++;

            continue;
        }
        
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        BindValue(stmt, index, resolved);

        index++;
    }

    stmt.execDML();

    stmt.finalize();

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyUpdateOperation(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const std::string table = operation.at("table").as_string().c_str();

    const auto& columns = operation.at("columns").as_object();

    if (columns.empty())
    {
        return TypeTemplateError("At least one column is required for update operation.");
    }

    const auto& keys = operation.at("keys").as_object();

    if (keys.empty())
    {
        return TypeTemplateError("At least one key is required for update operation.");
    }

    std::unordered_map<std::string, boost::json::value> defaults;

    // Select from the table where the keys match
    std::stringstream ss;

    ss << "SELECT ";

    for (const auto& [key, value] : columns)
    {
        ss << key << ", ";
    }

    ss.seekp(-2, std::ios_base::end);

    ss << " FROM " << table << " WHERE ";

    for (const auto& [key, value] : keys)
    {
        ss << key << " = ? AND ";
    }

    ss.seekp(-5, std::ios_base::end);

    ss << ";";

    auto stmt = context->GetContext().database->Prepare(ss.str());

    int index = 1;

    for (const auto& [key, value] : keys)
    {
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        BindValue(stmt, index, resolved);

        index++;
    }

    auto result = stmt.execQuery();

    if (result.eof())
    {
        return TypeTemplateError("No rows found for update operation.");
    }

    // Fill in the defaults
    for (const auto& [key, value] : columns)
    {
        std::string str = std::string(key);

        const auto index = result.fieldIndex(str.c_str());

        const auto type = result.fieldDataType(index);

        if (type == SQLITE_NULL)
        {
            defaults[key] = nullptr;
        }
        else if (type == SQLITE_INTEGER)
        {
            defaults[key] = result.getIntField(index);
        }
        else if (type == SQLITE_FLOAT)
        {
            defaults[key] = result.getFloatField(index);
        }
        else if (type == SQLITE_TEXT)
        {
            defaults[key] = result.getStringField(index);
        }
        else if (type == SQLITE_BLOB)
        {
            throw std::runtime_error("Unsupported data type.");
        }
    }

    // Update the values
    ss.str("");

    ss << "UPDATE " << table << " SET ";

    int count = 0;
    for (const auto& [key, value] : columns)
    {
        ss << key << " = ?";
        if (count < columns.size() - 1)
        {
            ss << ", ";
        }
        count++;
    }

    ss << " WHERE ";

    count = 0;
    for (const auto& [key, value] : keys)
    {
        ss << key << " = ?";
        if (count < keys.size() - 1)
        {
            ss << " AND ";
        }
        count++;
    }

    ss << ";";

    auto updateStmt = context->GetContext().database->Prepare(ss.str());

    index = 1;

    for (const auto& [key, value] : columns)
    {
        try
        {
            const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

            BindValue(updateStmt, index, resolved);
        }
        catch (const std::runtime_error& e)
        {
            BindValue(updateStmt, index, defaults.at(key));
        }

        index++;
    }

    for (const auto& [key, value] : keys)
    {
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        BindValue(updateStmt, index, resolved);

        index++;
    }

    int affectedRows = updateStmt.execDML();

    if (affectedRows == 0)
    {
        return TypeTemplateError("No rows updated.");
    }

    updateStmt.finalize();

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyDeleteOperation(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const std::string table = operation.at("table").as_string().c_str();

    const auto& keys = operation.at("keys").as_object();

    if (keys.empty())
    {
        return TypeTemplateError("At least one key is required for delete operation.");
    }

    std::stringstream ss;

    ss << "DELETE FROM " << table << " WHERE ";

    for (const auto& [key, value] : keys)
    {
        ss << key << " = ? AND ";
    }

    ss.seekp(-5, std::ios_base::end);

    ss << ";";

    auto stmt = context->GetContext().database->Prepare(ss.str());

    int index = 1;

    for (const auto& [key, value] : keys)
    {
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        BindValue(stmt, index, resolved);

        index++;
    }

    stmt.execDML();

    stmt.finalize();

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplySelectOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const std::string table = operation.at("table").as_string().c_str();

    const auto& columns = operation.at("columns").as_object();

    std::stringstream ss;

    ss << "SELECT ";

    for (const auto& [key, value] : columns)
    {
        ss << key << ", ";
    }

    ss.seekp(-2, std::ios_base::end);

    ss << " FROM " << table << " WHERE ";

    const auto& keys = operation.at("keys").as_object();

    for (const auto& [key, value] : keys)
    {
        ss << key << " = ? AND ";
    }

    ss.seekp(-5, std::ios_base::end);

    ss << ";";

    auto stmt = context->GetContext().database->Prepare(ss.str());

    int index = 1;

    for (const auto& [key, value] : keys)
    {
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        BindValue(stmt, index, resolved);

        index++;
    }

    auto result = stmt.execQuery();

    if (result.eof())
    {
        // No rows found. Set to default if specified.
        for (const auto& [key, value] : columns)
        {
            if (value.is_object())
            {
                const auto& obj = value.as_object();

                if (obj.contains("default"))
                {
                    context->SetVariable(
                        obj.at("variable").as_string().c_str(),
                        context->FindValue(obj.at("default"), TypeTemplateQueryOptions::Full)
                    );
                }
            }
            else
            {
                stmt.finalize();

                throw std::runtime_error("Invalid column value.");
            }
        }

        stmt.finalize();

        return TypeTemplateError::Success;
    }

    for (const auto& [key, value] : columns)
    {
        std::string str = std::string(key);
        std::string variable;

        if (value.is_string())
        {
            variable = value.as_string().c_str();
        }
        else if (value.is_object())
        {
            variable = value.at("variable").as_string().c_str();
        }
        else
        {
            throw std::runtime_error("Invalid column value.");
        }

        const auto index = result.fieldIndex(str.c_str());

        const auto type = result.fieldDataType(index);

        if (type == SQLITE_NULL)
        {
            context->SetVariable(variable, nullptr);
        }
        else if (type == SQLITE_INTEGER)
        {
            context->SetVariable(variable, result.getIntField(index));
        }
        else if (type == SQLITE_FLOAT)
        {
            context->SetVariable(variable, result.getFloatField(index));
        }
        else if (type == SQLITE_TEXT)
        {
            context->SetVariable(variable, result.getStringField(index));
        }
        else if (type == SQLITE_BLOB)
        {
            stmt.finalize();

            throw std::runtime_error("Unsupported data type.");
        }
    }

    stmt.finalize();

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyForEachOperation(
    const std::shared_ptr<TypeTemplateContext> &context,
    const boost::json::object &operation,
    const boost::json::object &json,
    const TypeTemplate &typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    if (!operation.contains("value"))
    {
        return TypeTemplateError("Missing 'value' field.");
    }

    const auto variableName = operation.at("value");

    if (!variableName.is_array())
    {
        std::stringstream ss;

        ss << "Value '" << variableName << "' is not an array.";

        return TypeTemplateError(ss.str());
    }

    std::vector<std::string> parts;

    for (const auto& element : variableName.as_array())
    {
        parts.push_back(element.as_string().c_str());
    }

    const std::string iterName = operation.at("iterator").as_string().c_str();
    const auto nextOperation = operation.at("operation").as_object();

    boost::json::value variable;

    try
    {
        variable = context->FindValue(parts, TypeTemplateQueryOptions::Full);
    }
    catch (const std::exception& e)
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Value not found.");
    }

    if (variable.is_array())
    {
        const auto& array = variable.as_array();

        for (size_t i = 0; i < array.size(); i++)
        {
            const auto& element = array[i];

            context->SetVariable(iterName, element);

            context->SetVariable(iterName + ".indexer", boost::json::string("[" + std::to_string(i) + "]"));

            context->SetVariable(iterName + ".index", boost::json::value(i));

            const auto error = ApplyOperation(context, nextOperation, json, typeTemplate, parameters);

            if (!error.IsSuccess())
            {
                return error;
            }
        }
    }
    else if (variable.is_object())
    {
        const auto& obj = variable.as_object();

        for (const auto& [key, value] : obj)
        {
            context->SetVariable(iterName + ".key", boost::json::value(key));
            
            parts.push_back(key);

            const auto objectVariable = context->FindValue(parts, TypeTemplateQueryOptions::Full);

            context->SetVariable(iterName + ".value", objectVariable);

            const auto error = ApplyOperation(context, nextOperation, json, typeTemplate, parameters);

            if (!error.IsSuccess())
            {
                return error;
            }

            parts.pop_back();
        }
    }
    else if (variable.is_null())
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }
        
        std::stringstream ss;

        ss << "Value '" << variableName << "' is null.";

        return TypeTemplateError(ss.str());
    }
    else
    {
        std::stringstream ss;

        ss << "Value '" << variableName << "' is not an array or object, got: " << boost::json::serialize(variable);

        return TypeTemplateError(ss.str());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyLocaleOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const auto variableName = operation.at("value");

    boost::json::value variable;

    try
    {
        variable = context->FindValue(variableName, TypeTemplateQueryOptions::Full);
    }
    catch (const std::runtime_error& e)
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Value not found.");
    }

    if (variable.is_null())
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Value is null.");
    }

    const std::string prefix = context->FindValue(operation.at("prefix"), TypeTemplateQueryOptions::None).as_string().c_str();
    const std::string suffix = context->FindValue(operation.at("suffix"), TypeTemplateQueryOptions::None).as_string().c_str();

    const auto& keyVariable = operation.at("key");

    const std::string key = ValueToString(context->FindValue(keyVariable, TypeTemplateQueryOptions::Full));

    if (variable.is_string())
    {
        const auto& value = variable.as_string();

        Localization localization;
        
        localization.Set("en_US", value.c_str());
        localization.Set("en_GB", value.c_str());
        localization.Set("de_DE", value.c_str());

        context->GetContext().locale->Set(prefix + key + suffix, localization);

        return TypeTemplateError::Success;
    }

    if (!variable.is_object())
    {
        std::stringstream ss;

        ss << "Value '" << variableName << "' is not a locale entry (object).";

        return TypeTemplateError(ss.str());
    }

    const auto& obj = variable.as_object();

    Localization localization;

    for (const auto& [key, value] : obj)
    {
        localization.Set(key, value.as_string().c_str());
    }

    context->GetContext().locale->Set(prefix + key + suffix, localization);

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyCascadeOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const auto variableName = operation.at("value");

    try
    {
        TypeTemplateQueryOptions options = TypeTemplateQueryOptions::Full;

        if (operation.contains("identifiers-only") && operation.at("identifiers-only").as_bool())
        {
            options = TypeTemplateQueryOptions::Identifiers;
        }

        const auto& variable = context->FindValue(variableName, options);
    }
    catch (const std::runtime_error& e)
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Value not found.");
    }

    if (!operation.contains("operation"))
    {
        return TypeTemplateError::Success;
    }

    const auto nextOperation = operation.at("operation").as_object();

    const auto error = ApplyOperation(context, nextOperation, json, typeTemplate, parameters);

    if (!error.IsSuccess())
    {
        return error;
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyAssignOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const auto variableName = operation.at("variable");

    const bool nonNull = operation.contains("non-null") && operation.at("non-null").as_bool();

    if (operation.contains("options"))
    {
        const auto value = operation.at("options");

        // Pick the first defined value
        for (const auto& element : value.as_array())
        {
            try
            {
                const auto& resolved = context->FindValue(element, TypeTemplateQueryOptions::Full);

                if (resolved.is_null() && nonNull)
                {
                    continue;
                }

                context->SetVariable(variableName.as_string().c_str(), resolved);

                return TypeTemplateError::Success;
            }
            catch (const std::runtime_error& e)
            {
                continue;
            }
        }
    }

    const auto value = operation.at("value");

    // Error if no value is found
    try
    {
        const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

        if (resolved.is_null() && nonNull)
        {
            return TypeTemplateError("Value is null.");
        }

        context->SetVariable(variableName.as_string().c_str(), resolved);
    }
    catch (const std::runtime_error& e)
    {
        return TypeTemplateError("Value not found.");
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyConcatOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    // Concatenate a value to a variable. If it does not exist, start with an empty string.
    const std::string variableName = operation.at("variable").as_string().c_str();

    const auto value = operation.at("value");

    const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

    if (resolved.is_null())
    {
        return TypeTemplateError("Value is null.");
    }

    std::string str;

    if (context->HasVariable(variableName))
    {
        str = context->GetVariable(variableName).as_string().c_str();
    }

    if (resolved.is_string())
    {
        str += resolved.as_string().c_str();
    }
    else if (resolved.is_int64())
    {
        str += std::to_string(resolved.as_int64());
    }
    else if (resolved.is_uint64())
    {
        str += std::to_string(resolved.as_uint64());
    }
    else if (resolved.is_double())
    {
        str += std::to_string(resolved.as_double());
    }
    else if (resolved.is_bool())
    {
        str += resolved.as_bool() ? "true" : "false";
    }
    else
    {
        return TypeTemplateError("Unsupported value type.");
    }

    context->SetVariable(variableName, boost::json::value(str));

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyPopOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    // Pop the last character from a variable
    const std::string variableName = operation.at("variable").as_string().c_str();

    if (!context->HasVariable(variableName))
    {
        if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Variable not found.");
    }

    std::string str = context->GetVariable(variableName).as_string().c_str();

    // Pop the last character
    if (!str.empty())
    {
        str.pop_back();
    }

    context->SetVariable(variableName, boost::json::value(str));

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplySQLOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    const auto value = operation.at("value");

    const auto& resolved = context->FindValue(value, TypeTemplateQueryOptions::Full);

    if (!resolved.is_string())
    {
        return TypeTemplateError("Value is not a string.");
    }

    const std::string sql = resolved.as_string().c_str();

    try {
        auto stmt = context->GetContext().database->Prepare(sql);

        if (operation.contains("bind"))
        {
            try {
                const auto& bind = context->FindValue(operation.at("bind"), TypeTemplateQueryOptions::Full);

                if (!bind.is_array())
                {
                    return TypeTemplateError("Bind value is not an array.");
                }

                const auto& binds = bind.as_array();

                int index = 1;

                for (const auto& bindValue : binds)
                {
                    BindValue(stmt, index, bindValue);

                    index++;
                }
            }
            catch (const std::runtime_error& e)
            {
                if (operation.contains("allow-none") && operation.at("allow-none").as_bool())
                {
                    return TypeTemplateError::Success;
                }
            }
        }

        stmt.execDML();

        stmt.finalize();
    } catch (const std::exception& e) {
        return TypeTemplateError(e.what());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyFileCopyOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    auto& ctx = context->GetContext();

    const auto &ns = context->GetVariable("namespace").as_string().c_str();

    const bool isCoreSymbol = ns == Lookup::core_prefix;

    if (isCoreSymbol)
    {
        return TypeTemplateError("Cannot copy files from core namespace.");
    }

    const auto &mods = ctx.mods;

    if (!mods->HasModPack(ns))
    {
        return TypeTemplateError("Namespace '" + std::string(ns) + "' does not exist");
    }

    auto& pack = mods->GetModPack(ns);

    const auto& resources = pack.GetResources();

    const auto& source = resources.GetResourcePath(context->FindValue(operation.at("source"), TypeTemplateQueryOptions::Full).as_string().c_str());

    const std::string modRelative = source.lexically_relative(ctx.configuration->GetModsDirectory());

    const std::string destination = context->FindValue(operation.at("destination"), TypeTemplateQueryOptions::Full).as_string().c_str();

    //std::cout << "Symlinking " << modRelative << " to " << destination << std::endl;

    ctx.artifacts->Symlink(ctx, modRelative, destination);

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateApplier::ApplyDirectoryCopyOperation(const std::shared_ptr<TypeTemplateContext> &context, const boost::json::object &operation, const boost::json::object &json, const TypeTemplate &typeTemplate, const std::unordered_map<std::string, TypeTemplateValue> &parameters) const
{
    auto& ctx = context->GetContext();

    const auto &ns = context->GetVariable("namespace").as_string().c_str();

    const bool isCoreSymbol = ns == Lookup::core_prefix;

    if (isCoreSymbol)
    {
        return TypeTemplateError("Cannot copy files from core namespace.");
    }

    const auto &mods = ctx.mods;

    if (!mods->HasModPack(ns))
    {
        return TypeTemplateError("Namespace '" + std::string(ns) + "' does not exist");
    }

    auto& pack = mods->GetModPack(ns);

    const auto& resources = pack.GetResources();

    auto sourceDirectory = resources.GetPath().parent_path() / context->FindValue(operation.at("source"), TypeTemplateQueryOptions::Full).as_string().c_str();

    // Make sure it's a subdirectory of the resources directory
    auto sourceCheck = sourceDirectory;
    while (sourceCheck.parent_path() != resources.GetPath())
    {
        sourceCheck = sourceDirectory.parent_path();

        // Check if we've reached the root directory
        if (sourceDirectory == std::filesystem::path())
        {
            return TypeTemplateError("Directory is not a subdirectory of the resources directory");
        }
    }

    const auto& modRelative = sourceDirectory.lexically_relative(ctx.configuration->GetModsDirectory());

    const std::string destination = context->FindValue(operation.at("destination"), TypeTemplateQueryOptions::Full).as_string().c_str();

    // Symlink everything in the directory
    for (const auto& entry : std::filesystem::recursive_directory_iterator(sourceDirectory))
    {
        // Skip directories
        if (entry.is_directory())
        {
            continue;
        }

        // Skip json files
        if (entry.path().extension() == ".json")
        {
            continue;
        }

        const auto& relative = std::filesystem::relative(entry.path(), sourceDirectory);

        //std::cout << "Relative: " << relative << ", destination: " << destination << std::endl;

        const auto& destinationPath = destination / relative;

        //std::cout << "Symlinking " << modRelative / relative << " to " << destinationPath << std::endl;

        ctx.artifacts->Symlink(ctx, modRelative / relative, destinationPath);
    }

    return TypeTemplateError::Success;
}

void nejlika::TypeTemplateApplier::RegisterExtentionFunction(const std::string &name, const ApplyExtentionFunction &function)
{
    m_ExtentionFunctions.emplace(name, function);
}

void nejlika::TypeTemplateApplier::BindValue(
    CppSQLite3Statement &statement,
    int32_t index,
    const boost::json::value &value,
    const boost::json::object &extra) const
{
    if (extra.contains("type"))
    {
        const std::string type = extra.at("type").as_string().c_str();

        if (type == "integer")
        {
            if (value.is_int64())
            {
                statement.bind(index, static_cast<int32_t>(value.as_int64()));
            }
            else if (value.is_uint64())
            {
                statement.bind(index, static_cast<int32_t>(value.as_uint64()));
            }
            else if (value.is_double())
            {
                statement.bind(index, static_cast<int32_t>(value.as_double()));
            }
            else if (value.is_string())
            {
                statement.bind(index, std::stoi(value.as_string().c_str()));
            }
            else if (value.is_bool())
            {
                statement.bind(index, value.as_bool() ? 1 : 0);
            }
            else if (value.is_null())
            {
                statement.bindNull(index);
            }
            else
            {
                throw std::runtime_error("Unsupported value type.");
            }
        }
        else if (type == "real")
        {
            if (value.is_int64())
            {
                statement.bind(index, static_cast<double>(value.as_int64()));
            }
            else if (value.is_uint64())
            {
                statement.bind(index, static_cast<double>(value.as_uint64()));
            }
            else if (value.is_double())
            {
                statement.bind(index, value.as_double());
            }
            else if (value.is_string())
            {
                statement.bind(index, std::stod(value.as_string().c_str()));
            }
            else if (value.is_bool())
            {
                statement.bind(index, value.as_bool() ? 1.0 : 0.0);
            }
            else if (value.is_null())
            {
                statement.bindNull(index);
            }
            else
            {
                throw std::runtime_error("Unsupported value type.");
            }
        }
        else if (type == "text")
        {
            if (value.is_string())
            {
                statement.bind(index, value.as_string().c_str());
            }
            else if (value.is_int64())
            {
                statement.bind(index, std::to_string(value.as_int64()).c_str());
            }
            else if (value.is_uint64())
            {
                statement.bind(index, std::to_string(value.as_uint64()).c_str());
            }
            else if (value.is_double())
            {
                statement.bind(index, std::to_string(value.as_double()).c_str());
            }
            else if (value.is_bool())
            {
                statement.bind(index, value.as_bool() ? "true" : "false");
            }
            else if (value.is_null())
            {
                statement.bindNull(index);
            }
            else
            {
                throw std::runtime_error("Unsupported value type.");
            }
        }
        else if (type == "boolean")
        {
            if (value.is_bool())
            {
                statement.bind(index, value.as_bool());
            }
            else if (value.is_int64())
            {
                statement.bind(index, value.as_int64() != 0);
            }
            else if (value.is_uint64())
            {
                statement.bind(index, value.as_uint64() != 0);
            }
            else if (value.is_double())
            {
                statement.bind(index, value.as_double() != 0);
            }
            else if (value.is_string())
            {
                statement.bind(index, std::string(value.as_string().c_str()) == "true");
            }
            else if (value.is_null())
            {
                statement.bindNull(index);
            }
            else
            {
                throw std::runtime_error("Unsupported value type.");
            }
        }
        else if (type == "blob")
        {
            throw std::runtime_error("Unsupported value type.");
        }
        else
        {
            throw std::runtime_error("Unsupported value type.");
        }
    }

    if (value.is_string())
    {
        statement.bind(index, value.as_string().c_str());
    }
    else if (value.is_int64())
    {
        statement.bind(index, static_cast<int32_t>(value.as_int64()));
    }
    else if (value.is_uint64())
    {
        statement.bind(index, static_cast<int32_t>(value.as_uint64()));
    }
    else if (value.is_double())
    {
        statement.bind(index, value.as_double());
    }
    else if (value.is_bool())
    {
        statement.bind(index, value.as_bool());
    }
    else if (value.is_null())
    {
        statement.bindNull(index);
    }
    else if (value.is_array())
    {
        const std::string seperator = extra.contains("seperator") ? extra.at("seperator").as_string().c_str() : ",";

        std::stringstream ss;

        for (const auto& element : value.as_array())
        {
            if (element.is_string())
            {
                ss << element.as_string().c_str();
            }
            else if (element.is_int64())
            {
                ss << element.as_int64();
            }
            else if (element.is_uint64())
            {
                ss << element.as_uint64();
            }
            else if (element.is_double())
            {
                ss << element.as_double();
            }
            else
            {
                throw std::runtime_error("Unsupported value type.");
            }
            
            ss << seperator;
        }
        
        std::string str = ss.str();

        if (!value.as_array().empty())
        {
            for (size_t i = 0; i < seperator.size(); i++)
            {
                str.pop_back();
            }
        }

        statement.bind(index, str.c_str());
    }
    else
    {
        throw std::runtime_error("Unsupported value type.");
    }
}

std::string nejlika::TypeTemplateApplier::ValueToString(const boost::json::value &value) const
{
    if (value.is_string())
    {
        return value.as_string().c_str();
    }
    else if (value.is_int64())
    {
        return std::to_string(value.as_int64());
    }
    else if (value.is_uint64())
    {
        return std::to_string(value.as_uint64());
    }
    else if (value.is_double())
    {
        return std::to_string(value.as_double());
    }
    else if (value.is_bool())
    {
        return value.as_bool() ? "true" : "false";
    }
    else if (value.is_null())
    {
        return "null";
    }
    else
    {
        throw std::runtime_error("Unsupported value type for conversion.");
    }
}

bool nejlika::TypeTemplateApplier::TryResolveName(
    nejlika::Context &ctx,
    const boost::json::object &json,
    nejlika::id &result) const
{
    if (!json.contains("name"))
    {
        throw std::runtime_error("Missing required parameter: \"name\"");
    }

    if (json.contains("explicit-id"))
    {
        result = json.at("explicit-id").as_int64();

        return true;
    }

    const auto& name = json.at("name").as_string().c_str();

    if (ctx.lookup->Exists(name))
    {
        result = ctx.lookup->GetValue(name);

        return true;
    }

    if (json.contains("aliases"))
    {
        const auto& aliases = json.at("aliases").as_array();

        for (const auto& alias : aliases)
        {
            if (ctx.lookup->Exists(alias.as_string().c_str()))
            {
                result = ctx.lookup->GetValue(alias.as_string().c_str());

                return true;
            }
        }
    }

    return false;
}
