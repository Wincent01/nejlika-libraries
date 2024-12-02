#include "TypeTemplateValidator.hpp"

#include "TypeTemplateParameter.hpp"
#include "TypeTemplateScope.hpp"
#include "TypeTemplate.hpp"
#include "ModPack.hpp"
#include "Mods.hpp"
#include "nejlika.hpp"
#include "Lookup.hpp"
#include "ModResources.hpp"
#include "Configuration.hpp"
#include "TypeTemplateInterface.hpp"

#include <sstream>

using namespace nejlika;

TypeTemplateValidator::TypeTemplateValidator()
{
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateParameter(
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const std::string &prelKey,
    const std::shared_ptr<TypeTemplateScope> &object) const
{
    const auto &obj = object->GetValue();

    std::string key = prelKey;
    bool hasKey = obj.contains(key);

    if (!hasKey)
    {
        // Check for aliases
        if (parameter->GetAliases().size() > 0)
        {
            for (const auto &alias : parameter->GetAliases())
            {
                if (obj.contains(alias))
                {
                    key = alias;
                    hasKey = true;
                    break;
                }
            }
        }

        if (!hasKey && parameter->IsRequired())
        {
            std::stringstream ss;

            ss << "Parameter '" << key << "'";

            if (!parameter->GetAliases().empty())
            {
                ss << ", or one of its aliases (";

                for (const auto &alias : parameter->GetAliases())
                {
                    ss << "'" << alias << "', ";
                }

                ss.seekp(-2, std::ios_base::end);

                ss << ")";
            }

            ss << " is required";

            return TypeTemplateError(ss.str());
        }
    }

    if (!parameter->IsRequired() && !obj.contains(key))
    {
        return TypeTemplateError::Success;
    }

    const auto &value = obj.at(key);

    if (value.is_null() && !parameter->IsNullable())
    {
        return TypeTemplateError("Non-nullable parameter is null: " + key);
    }

    if (value.is_null() && parameter->IsNullable())
    {
        return TypeTemplateError::Success;
    }

    const auto &typeError = ValidateType(object, parameter, object->ResolveTypeArguments(prelKey), value);

    if (!typeError.IsSuccess())
    {
        return TypeTemplateError(
            "Parameter '" + key + "':",
            typeError);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateType(
    const std::shared_ptr<TypeTemplateScope> &parent,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const boost::json::value &value) const
{
    const auto &type = parameter->GetType();

    if (type == "string")
        return ValidateString(value);
    if (type == "number")
        return ValidateNumber(value);
    if (type == "integer")
        return ValidateInteger(value);
    if (type == "boolean")
        return ValidateBoolean(value);
    if (type == "object")
        return ValidateObject(parent, parameter, parameters, value);
    if (type == "array")
        return ValidateArray(parent, parameter, parameters, value);
    if (type == "enum")
        return ValidateEnum(parent, parameter, parameters, value);
    if (type == "id")
        return ValidateId(parent, parameter, parameters, value);
    if (type == "id-lax")
        return ValidateId(parent, parameter, parameters, value, true);
    if (type == "id-any")
        return ValidateId(parent, parameter, parameters, value, true, true);
    if (type == "locale")
        return ValidateLocale(value);
    if (type == "resource")
        return ValidateResource(parent, parameter, parameters, value);

    throw std::runtime_error("Unknown type: " + type);
}

const char *nejlika::TypeTemplateValidator::JsonTypeToString(const boost::json::value &value)
{
    const auto &type = value.kind();

    switch (type)
    {
    case boost::json::kind::string:
        return "string";
    case boost::json::kind::int64:
    case boost::json::kind::uint64:
    case boost::json::kind::double_:
        return "number";
    case boost::json::kind::bool_:
        return "boolean";
    case boost::json::kind::object:
        return "object";
    case boost::json::kind::array:
        return "array";
    case boost::json::kind::null:
        return "null";
    default:
        return "unknown";
    }
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateString(const boost::json::value &value) const
{
    if (!value.is_string() && !value.is_number())
    {
        std::stringstream ss;

        ss << "Expected string or number, got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateNumber(const boost::json::value &value) const
{
    if (value.is_string())
    {
        // Try to convert to number
        try
        {
            std::stod(value.as_string().c_str());
        }
        catch (const std::exception &)
        {
            std::stringstream ss;

            ss << "Unable to convert string to number: " << value.as_string().c_str();

            return TypeTemplateError(ss.str());
        }
    }

    if (!value.is_number())
    {
        std::stringstream ss;

        ss << "Expected number, got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateInteger(const boost::json::value &value) const
{
    if (value.is_string())
    {
        // Try to convert to number
        try
        {
            std::stoll(value.as_string().c_str());
        }
        catch (const std::exception &)
        {
            std::stringstream ss;

            ss << "Unable to convert string to integer: " << value.as_string().c_str();

            return TypeTemplateError(ss.str());
        }
    }

    if (value.is_int64() || value.is_uint64())
    {
        return TypeTemplateError::Success;
    }

    if (value.is_double())
    {
        const auto &doubleValue = value.as_double();

        // Check that it's a whole number
        if (doubleValue != static_cast<int64_t>(doubleValue))
        {
            return TypeTemplateError("Expected integer, got double");
        }

        return TypeTemplateError::Success;
    }

    std::stringstream ss;

    ss << "Expected integer, got " << JsonTypeToString(value);

    return TypeTemplateError(ss.str());
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateBoolean(const boost::json::value &value) const
{
    if (value.is_string())
    {
        if (value.as_string() != "true" && value.as_string() != "false")
        {
            std::stringstream ss;

            ss << "Expected boolean (interpretion from string \"false\"/\"true\"), got " << value.as_string().c_str();

            return TypeTemplateError(ss.str());
        }
    }

    if (value.is_number())
    {
        if (value.as_int64() != 0 && value.as_int64() != 1)
        {
            std::stringstream ss;

            ss << "Expected boolean (interpretion from number 0/1), got " << value.as_int64();

            return TypeTemplateError(ss.str());
        }
    }

    if (!value.is_bool())
    {
        std::stringstream ss;

        ss << "Expected boolean, got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateObject(
    const std::shared_ptr<TypeTemplateScope> &parent,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const boost::json::value &value) const
{
    if (!value.is_object())
    {
        std::stringstream ss;

        ss << "Expected object, got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    auto errors = std::vector<TypeTemplateError>();

    const auto parentParameters = parent->ResolveParameters();

    const auto &scope = std::make_shared<TypeTemplateScope>(
        parent->GetRoot(),
        parameter,
        parent,
        parentParameters,
        value.as_object());

    if (!parameter->GetObjectProperties().empty()) {
        for (const auto &property : parameter->GetObjectProperties())
        {
            const auto &parameterError = ValidateParameter(
                property,
                property->GetName(),
                scope);

            if (!parameterError.IsSuccess())
            {
                std::stringstream ss;

                ss << "Property '" << property->GetName() << "':";

                errors.push_back(
                    TypeTemplateError(
                        ss.str(),
                        parameterError));
            }
        }
    }
    else
    {
        const auto &arrayType = parameter->GetArrayType();

        for (const auto &[key, value] : value.as_object())
        {
            const auto &parameterError = ValidateType(
                parent,
                arrayType,
                parentParameters,
                value);

            if (!parameterError.IsSuccess())
            {
                std::stringstream ss;

                ss << "Property '" << key << "':";

                errors.push_back(
                    TypeTemplateError(
                        ss.str(),
                        parameterError));
            }
        }
    }

    if (errors.size() > 0)
    {
        return TypeTemplateError(
            "Object has invalid properties",
            errors);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateArray(
    const std::shared_ptr<TypeTemplateScope> &parent,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const boost::json::value &value) const
{
    if (!value.is_array())
    {
        std::stringstream ss;

        ss << "Expected array, got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    const auto &arrayType = parameter->GetArrayType();

    auto errors = std::vector<TypeTemplateError>();

    uint32_t index = 0;

    for (const auto &element : value.as_array())
    {
        if (element.is_object())
        {
            const auto &scope = std::make_shared<TypeTemplateScope>(
                parent->GetRoot(),
                arrayType,
                parent,
                parameters,
                element.as_object());

            const auto &scopeParameters = scope->ResolveParameters();

            const auto &typeError = ValidateType(
                parent,
                arrayType,
                scopeParameters,
                element);

            if (!typeError.IsSuccess())
            {
                errors.push_back(
                    TypeTemplateError(
                        "Array element at index [" + std::to_string(index++) + "]:",
                        typeError));
            }
        }
        else
        {
            const auto &typeError = ValidateType(
                parent,
                arrayType,
                {},
                element);

            if (!typeError.IsSuccess())
            {
                errors.push_back(
                    TypeTemplateError(
                        "Array element at index [" + std::to_string(index++) + "]:",
                        typeError));
            }
        }
    }

    if (errors.size() > 0)
    {
        return TypeTemplateError(
            "Array parameter has invalid elements",
            errors);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateEnum(const std::shared_ptr<TypeTemplateScope> &parent, const std::shared_ptr<TypeTemplateParameter> &parameter, const std::unordered_map<std::string, TypeTemplateValue> &parameters, const boost::json::value &value) const
{
    const auto &enumMap = parameter->GetEnumValues(); // string -> value

    if (value.is_number())
    {
        int64_t enumValue = value.is_double() ? static_cast<int64_t>(value.as_double()) : value.to_number<int64_t>();

        bool found = false;

        // Loop through the enum values to check if the value is valid
        for (const auto &[_, enumValueObject] : enumMap)
        {
            if (!enumValueObject.GetValue().is_number())
            {
                continue;
            }

            int64_t enumValueCheck =
                enumValueObject.GetValue().is_double() ? static_cast<int64_t>(enumValueObject.GetValue().as_double()) : enumValueObject.GetValue().to_number<int64_t>();

            if (enumValue == enumValueCheck)
            {
                found = true;
                break;
            }
        }

        if (found)
            return TypeTemplateError::Success;

        std::stringstream ss;

        ss << "Could not interpret enum value: '" << enumValue << "', expected one of: ";

        bool any = false;

        for (const auto &[_, enumValueObject] : enumMap)
        {
            if (!enumValueObject.GetValue().is_number())
            {
                continue;
            }

            int64_t enumValueCheck =
                enumValueObject.GetValue().is_double() ? static_cast<int64_t>(enumValueObject.GetValue().as_double()) : enumValueObject.GetValue().to_number<int64_t>();

            ss << "'" << enumValueCheck << "', ";

            any = true;
        }

        if (any)
        {
            ss.seekp(-2, std::ios_base::end);
        }
        else
        {
            ss << "none";
        }

        return TypeTemplateError(ss.str());
    }

    if (!value.is_string())
    {
        std::stringstream ss;

        ss << "Expected enum (string), got " << JsonTypeToString(value);

        return TypeTemplateError(ss.str());
    }

    const auto *enumValue = value.as_string().c_str();

    if (enumMap.find(enumValue) == enumMap.end())
    {
        std::stringstream ss;

        ss << "Invalid enum key: '" << enumValue << "', expected one of: ";

        for (const auto &[key, _] : enumMap)
        {
            ss << "'" << key << "', ";
        }

        ss.seekp(-2, std::ios_base::end);

        return TypeTemplateError(ss.str());
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateId(
    const std::shared_ptr<TypeTemplateScope> &parent,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const boost::json::value &value,
    bool lax,
    bool any
) const
{
    if (value.is_int64() || value.is_uint64())
    {
        return TypeTemplateError::Success;
    }

    if (value.is_bool())
    {
        if (lax)
        {
            return TypeTemplateError::Success;
        }

        return TypeTemplateError("Expected id, got boolean");
    }

    if (value.is_double())
    {
        if (lax)
        {
            return TypeTemplateError::Success;
        }

        // Check that the double is a whole number
        if (value.as_double() != value.as_int64())
        {
            return TypeTemplateError("Expected id (whole number), got double");
        }
    }

    if (value.is_string())
    {
        if (any) return TypeTemplateError::Success;

        // Search for a ':' in the id
        std::string id = value.as_string().c_str();

        if (id.find(':') == std::string::npos)
        {
            return TypeTemplateError("Invalid id format, expected 'namespace:name'");
        }

        if (id.find(Lookup::core_prefix) == 0)
        {
            nejlika::id coreValue;

            if (!parent->GetRoot()->GetContext().lookup->IsCoreSymbol(id, coreValue))
            {
                return TypeTemplateError("Invalid core symbol: '" + id + "'");
            }

            return TypeTemplateError::Success;
        }

        return TypeTemplateError::Success;
    }

    if (!value.is_object())
    {
        return TypeTemplateError("Expected id (string, integer, object), got " + std::string(JsonTypeToString(value)));
    }

    const auto &nestedInstance = value.as_object();

    // Check that the 'type' property exists and is a string
    if (!nestedInstance.contains("type"))
    {
        return TypeTemplateError("Invalid nested instance, missing 'type' property");
    }

    if (!nestedInstance.at("type").is_string())
    {
        return TypeTemplateError("Invalid nested instance, 'type' property is not a string");
    }

    // Check that the 'name' property exists and is a string
    if (!nestedInstance.contains("name"))
    {
        return TypeTemplateError("Invalid nested instance, missing 'name' property");
    }

    if (!nestedInstance.at("name").is_string())
    {
        return TypeTemplateError("Invalid nested instance, 'name' property is not a string");
    }

    const auto &nestedType = nestedInstance.at("type").as_string().c_str();

    const auto &validTypes = parameter->GetIdTypes();

    if (!validTypes.empty() && validTypes.find(nestedType) == validTypes.end())
    {
        std::stringstream ss;

        ss << "Invalid nested instance, type '" << nestedType << "' is not allowed, expected one of: ";

        for (const auto &validType : validTypes)
        {
            ss << "'" << validType << "', ";
        }

        ss.seekp(-2, std::ios_base::end);

        return TypeTemplateError(ss.str());
    }

    if (!parent->GetContext().templates->HasTemplate(nestedType))
    {
        std::stringstream ss;

        ss << "Invalid nested instance, type '" << nestedType << "' does not exist";

        return TypeTemplateError(ss.str());
    }

    const auto &typeTemplate = parent->GetContext().templates->GetTemplate(nestedType);

    const auto &nestedError = typeTemplate->Validate(
        parent->GetRoot()->GetContext(),
        nestedInstance,
        parameters,
        parent->GetRoot()
    );

    if (!nestedError.IsSuccess())
    {
        return TypeTemplateError("Invalid nested instance:", nestedError);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateLocale(const boost::json::value &value) const
{
    if (value.is_string())
    {
        return TypeTemplateError::Success;
    }

    // An object with <locale>:<value> pairs
    if (!value.is_object())
    {
        return TypeTemplateError("Expected locale (object, string), got " + std::string(JsonTypeToString(value)));
    }

    std::vector<TypeTemplateError> errors;

    for (const auto &[key, value] : value.as_object())
    {
        if (value.is_string()) continue;
        
        std::stringstream ss;

        ss << "Locale key '" << key << "': Expected string, got " << JsonTypeToString(value);

        errors.push_back(TypeTemplateError(ss.str()));
    }

    if (errors.size() > 0)
    {
        return TypeTemplateError("Invalid locale object", errors);
    }

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplateValidator::ValidateResource(const std::shared_ptr<TypeTemplateScope> &parent, const std::shared_ptr<TypeTemplateParameter> &parameter, const std::unordered_map<std::string, TypeTemplateValue> &parameters, const boost::json::value &value) const
{
    // Assert that the "prefix" and "type" parameters exist
    if (!parameters.contains("prefix"))
    {
        throw std::runtime_error("Resource parameter missing 'prefix' parameter");
    }

    if (!parameters.contains("type"))
    {
        throw std::runtime_error("Resource parameter missing 'type' parameter");
    }

    // Assert that the "prefix" and "type" parameters are strings
    if (!parameters.at("prefix").GetValue().is_string())
    {
        throw std::runtime_error("Resource parameter 'prefix' is not a string");
    }

    if (!parameters.at("type").GetValue().is_string())
    {
        throw std::runtime_error("Resource parameter 'type' is not a string");
    }

    // Check that the value is a string
    if (!value.is_string())
    {
        return TypeTemplateError("Expected resource (string), got " + std::string(JsonTypeToString(value)));
    }

    const std::filesystem::path resource = value.as_string().c_str();

    const std::string prefix = parameters.at("prefix").GetValue().as_string().c_str();
    const std::string type = parameters.at("type").GetValue().as_string().c_str();

    const auto &root = parent->GetRoot();

    const auto &ns = root->GetVariable("namespace").as_string().c_str();

    const bool isCoreSymbol = ns == Lookup::core_prefix;

    const auto &mods = root->GetContext().mods;

    if (!mods->HasModPack(ns) && !isCoreSymbol)
    {
        throw std::runtime_error("Namespace '" + std::string(ns) + "' does not exist");
    }

    std::filesystem::path withoutPrefix;

    if (ModResources::IsCoreResource(resource, withoutPrefix))
    {
        const auto rootPath = root->GetContext().configuration->GetClient() / "res";

        const auto path = rootPath / withoutPrefix;

        if (!std::filesystem::exists(path))
        {
            return TypeTemplateError("Resource '" + std::string(resource) + "' does not exist");
        }
        
        return TypeTemplateError::Success;
    }

    // Check for a namespace in the resource
    if (std::string(resource).find(':') == std::string::npos && isCoreSymbol)
    {
        return TypeTemplateError("Resource '" + std::string(resource) + "' does not contain a namespace delimiter ':'");
    }

    auto &package = mods->GetModPack(ns);

    std::filesystem::path sourcePath;

    const auto& resources = ModResources::FindResources(
        root->GetContext(),
        resource,
        package.GetResources(),
        sourcePath
    );

    if (!resources.HasResource(sourcePath))
    {
        return TypeTemplateError("Resource '" + std::string(resource) + "' does not exist");
    }

    const auto& source = resources.GetResourcePath(sourcePath);

    const auto& extension = source.extension().string().substr(1);
    
    // type is ; separated list of extensions
    if (std::string(type).find(';') != std::string::npos)
    {
        std::vector<std::string> extensions;

        std::string typeCopy = type;

        while (typeCopy.find(';') != std::string::npos)
        {
            extensions.push_back(typeCopy.substr(0, typeCopy.find(';')));

            typeCopy = typeCopy.substr(typeCopy.find(';') + 1);
        }

        extensions.push_back(typeCopy);

        if (std::find(extensions.begin(), extensions.end(), extension) == extensions.end())
        {
            std::stringstream ss;

            ss << "Resource '" << resource << "' has an invalid extension, expected one of: ";

            for (const auto &ext : extensions)
            {
                ss << "'" << ext << "', ";
            }

            ss.seekp(-2, std::ios_base::end);

            return TypeTemplateError(ss.str());
        }
    }
    else if (type != "*")
    {
        if (extension != type)
        {
            return TypeTemplateError("Resource '" + std::string(resource) + "' has an invalid extension, expected '" + std::string(type) + "'");
        }
    }

    return TypeTemplateError::Success;
}

std::unordered_set<std::string> nejlika::TypeTemplateValidator::FindDependencies(
    const std::unique_ptr<TypeTemplateInterface>& interface,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const boost::json::value &value,
    std::unordered_set<name>& nestedInstances
) const
{
    std::unordered_set<std::string> dependencies;

    FindDependenciesRecursive(interface, parameter, value, dependencies, nestedInstances);

    // dependencies \ nestedInstances
    for (const auto &nestedInstance : nestedInstances)
    {
        dependencies.erase(nestedInstance);
    }

    return dependencies;
}

void nejlika::TypeTemplateValidator::FindDependenciesRecursive(
    const std::unique_ptr<TypeTemplateInterface>& interface,
    const std::shared_ptr<TypeTemplateParameter> &parameter,
    const boost::json::value &value,
    std::unordered_set<std::string> &dependencies,
    std::unordered_set<std::string> &nestedInstances) const
{
    if (parameter->GetType() == "id" || parameter->GetType() == "id-lax" || parameter->GetType() == "id-any")
    {
        if (value.is_string())
        {
            const auto &id = value.as_string().c_str();

            if (std::string(id).find(':') != std::string::npos)
            {
                dependencies.insert(id);
            }
        }

        if (value.is_object())
        {
            const auto &nestedInstance = value.as_object();

            if (!nestedInstance.contains("type") || !nestedInstance.at("type").is_string())
            {
                throw std::runtime_error("Invalid nested instance, missing 'type' property or 'type' property is not a string");
            }

            if (!nestedInstance.contains("name") || !nestedInstance.at("name").is_string())
            {
                throw std::runtime_error("Invalid nested instance, missing 'name' property or 'name' property is not a string");
            }

            const auto &nestedType = nestedInstance.at("type").as_string().c_str();

            if (!interface->HasTemplate(nestedType))
            {
                throw std::runtime_error("Invalid nested instance, type '" + std::string(nestedType) + "' does not exist");
            }

            const auto &typeTemplate = interface->GetTemplate(nestedType);

            const auto &nestedDependencies = typeTemplate->GetDependencies(interface, nestedInstance, nestedInstances);

            dependencies.insert(nestedDependencies.begin(), nestedDependencies.end());

            const auto &nestedName = nestedInstance.at("name").as_string().c_str();

            nestedInstances.insert(nestedName);
        }
    }

    if (parameter->GetType() == "object")
    {
        if (value.is_object())
        {
            if (!parameter->GetObjectProperties().empty())
            {
                for (const auto &property : parameter->GetObjectProperties())
                {
                    if (value.as_object().contains(property->GetName()))
                    {
                        const auto &propertyDependencies = FindDependencies(interface, property, value.as_object().at(property->GetName()), nestedInstances);

                        dependencies.insert(propertyDependencies.begin(), propertyDependencies.end());
                    }
                }
            }
            else
            {
                const auto& arrayType = parameter->GetArrayType();

                for (const auto &[key, value] : value.as_object())
                {
                    const auto &propertyDependencies = FindDependencies(interface, arrayType, value, nestedInstances);

                    dependencies.insert(propertyDependencies.begin(), propertyDependencies.end());
                }
            }
        }
    }

    if (parameter->GetType() == "array")
    {
        if (value.is_array())
        {
            for (const auto &element : value.as_array())
            {
                const auto &elementDependencies = FindDependencies(interface, parameter->GetArrayType(), element, nestedInstances);

                dependencies.insert(elementDependencies.begin(), elementDependencies.end());
            }
        }
    }
}
