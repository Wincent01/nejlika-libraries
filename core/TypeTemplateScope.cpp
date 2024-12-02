#include "TypeTemplateScope.hpp"

#include <sstream>
#include "nejlika.hpp"
#include "Lookup.hpp"
#include "TypeTemplate.hpp"
#include "Mods.hpp"
#include "ModResources.hpp"
#include "Configuration.hpp"
#include "Artifacts.hpp"
#include "TypeTemplateInterface.hpp"

using namespace nejlika;

namespace {
    std::vector<TypeTemplateError> m_NestedErrors;
}

nejlika::TypeTemplateScope::TypeTemplateScope(
    const std::shared_ptr<TypeTemplateContext> &root,
    const std::shared_ptr<TypeTemplateParameter> &rule,
    const std::shared_ptr<TypeTemplateScope> &parent,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const boost::json::object &value)
{
    m_Root = root;
    m_Rule = rule;
    m_Parent = parent;
    m_Parameters = parameters;
    m_Value = value;
}

nejlika::TypeTemplateScope::TypeTemplateScope(const TypeTemplateScope &other)
{
    m_Root = other.m_Root;
    m_Rule = other.m_Rule;
    m_Parent = other.m_Parent;
    m_Parameters = other.m_Parameters;
    m_Value = other.m_Value;
}

const std::shared_ptr<TypeTemplateContext> &nejlika::TypeTemplateScope::GetRoot() const
{
    return m_Root;
}

nejlika::Context& nejlika::TypeTemplateScope::GetContext() const
{
    return m_Root->GetContext();
}

const std::shared_ptr<TypeTemplateParameter> &nejlika::TypeTemplateScope::GetRule() const
{
    return m_Rule;
}

const std::shared_ptr<TypeTemplateScope> &nejlika::TypeTemplateScope::GetParent() const
{
    return m_Parent;
}

const std::unordered_map<std::string, TypeTemplateValue> &nejlika::TypeTemplateScope::GetParameters() const
{
    return m_Parameters;
}

std::unordered_map<std::string, TypeTemplateValue> nejlika::TypeTemplateScope::ResolveParameters()
{
    std::unordered_map<std::string, TypeTemplateValue> resolved;

    for (const auto &[key, value] : m_Parameters)
    {
        resolved.emplace(key, FindValue(value, TypeTemplateQueryOptions::Identifiers));
    }

    return resolved;
}

std::unordered_map<std::string, TypeTemplateValue> nejlika::TypeTemplateScope::ResolveTypeArguments(const std::string &key)
{
    std::unordered_map<std::string, TypeTemplateValue> resolved;

    if (m_Rule == nullptr)
    {
        return resolved;
    }

    const auto &rule = m_Rule->FindObjectProperty(key);

    for (const auto &[jsonKey, value] : rule->GetTypeArguments())
    {
        resolved.emplace(jsonKey, FindValue(value, TypeTemplateQueryOptions::Identifiers));
    }

    return resolved;
}

const boost::json::object &nejlika::TypeTemplateScope::GetValue() const
{
    return m_Value;
}

boost::json::value nejlika::TypeTemplateScope::FindValue(const TypeTemplateValue &value, TypeTemplateQueryOptions options)
{
    const auto &core = value.GetValue();

    if (!core.is_array())
    {
        return core;
    }

    std::vector<std::string> parts;

    for (const auto &item : core.as_array())
    {
        if (!item.is_string())
        {
            throw std::runtime_error("Invalid path");
        }

        parts.push_back(item.as_string().c_str());
    }

    return InternalFindValue(parts, options);
}

std::vector<TypeTemplateError> nejlika::TypeTemplateScope::FetchAndClearNestedErrors()
{
    auto errors = m_NestedErrors;

    m_NestedErrors.clear();

    return errors;
}

boost::json::value nejlika::TypeTemplateScope::InternalFindValue(
    std::vector<std::string> parts,
    TypeTemplateQueryOptions options)
{
    if (parts.empty())
    {
        throw std::runtime_error("Invalid path");
    }

    auto key = parts.front();

    if (key.starts_with("$"))
    {
        key = m_Root->GetVariable(key.substr(1)).as_string().c_str();
    }

    if (m_Rule->HasObjectProperty(key))
    {
        const auto &rule = m_Rule == nullptr ? nullptr : m_Rule->FindObjectProperty(key);

        if (m_Value.contains(rule->GetName()))
        {
            return ProcessValue(m_Value.at(rule->GetName()), parts, rule, options);
        }

        for (const auto &alias : rule->GetAliases())
        {
            if (m_Value.contains(alias))
            {
                return ProcessValue(m_Value.at(alias), parts, rule, options);
            }
        }

        if (rule->IsRequired())
        {
            throw std::runtime_error("Required path part not found: " + key);
        }

        if (!rule->HasDefault())
        {
            throw std::runtime_error("Path part not found: " + key);
        }

        return rule->GetDefaultValue();
    }

    if (m_Rule->GetArrayType() != nullptr)
    {
        if (!m_Value.contains(key))
        {
            throw std::runtime_error("Map path part not found: " + key);
        }

        return ProcessValue(m_Value.at(key), parts, m_Rule->GetArrayType(), options);
    }

    if (key == "parent")
    {
        if (!m_Parent)
        {
            throw std::runtime_error("Invalid path, no parent");
        }

        parts.erase(parts.begin());

        return m_Parent->InternalFindValue(parts, options);
    }

    if (key == "root")
    {
        if (!m_Root)
        {
            throw std::runtime_error("Invalid path, no root");
        }

        parts.erase(parts.begin());

        return m_Root->FindValue(parts, options);
    }

    if (key == "parameters")
    {
        if (parts.size() < 2)
        {
            throw std::runtime_error("Invalid path");
        }

        parts.erase(parts.begin());

        const auto &parameter = m_Parameters.find(parts.front());

        if (parameter == m_Parameters.end())
        {
            throw std::runtime_error("Parameter not found: " + parts.front());
        }

        parts.erase(parts.begin());

        if (!parts.empty())
        {
            throw std::runtime_error("Invalid path");
        }

        return parameter->second.GetValue();
    }

    std::stringstream ss;

    ss << "Path part not found: " << key;

    throw std::runtime_error(ss.str());
}

boost::json::value nejlika::TypeTemplateScope::ProcessObject(
    const boost::json::object &value,
    std::vector<std::string> parts,
    const std::shared_ptr<TypeTemplateParameter> &rule,
    TypeTemplateQueryOptions options)
{
    const auto &child = value;
    parts.erase(parts.begin());

    if (parts.empty())
    {
        return value;
    }

    std::unordered_map<std::string, TypeTemplateValue> parameters;

    if (m_Rule != nullptr)
    {
        for (const auto &[key, value] : m_Rule->GetTypeArguments())
        {
            parameters.emplace(key, FindValue(value, options));
        }
    }

    const auto &nestedScope = std::make_shared<TypeTemplateScope>(
        m_Root,
        rule,
        shared_from_this(),
        parameters,
        child);

    return nestedScope->InternalFindValue(parts, options);
}

boost::json::value nejlika::TypeTemplateScope::ProcessValue(
    const boost::json::value &value,
    std::vector<std::string> parts,
    const std::shared_ptr<TypeTemplateParameter> &rule,
    TypeTemplateQueryOptions options)
{
    const auto type = rule == nullptr ? "" : rule->GetType();

    if (rule != nullptr && (type == "id" || type == "id-lax" || type == "id-any"))
    {
        const auto isLax = type == "id-lax" || type == "id-any";
        const auto isAny = type == "id-any";

        if (value.is_int64() || value.is_uint64())
        {
            return value;
        }

        if (value.is_double())
        {
            if (isLax)
            {
                return value;
            }

            if (value.as_double() == static_cast<int64_t>(value.as_double()))
            {
                return value;
            }

            throw std::runtime_error("Invalid id");
        }

        if (value.is_string())
        {
            std::string str = value.as_string().c_str();
            const auto& lookup = GetRoot()->GetContext().lookup;

            if (isAny && !lookup->Exists(str))
            {
                return value.as_string();
            }

            return lookup->GetValue(str);
        }


        if (value.is_bool())
        {
            if (isLax)
            {
                return value.as_bool() ? 1 : 0;
            }

            throw std::runtime_error("Invalid id");
        }

        if (value.is_object())
        {
            if (options == TypeTemplateQueryOptions::None)
                return 0;

            const auto &child = value.as_object();

            const std::string name = child.at("name").as_string().c_str();

            if (GetRoot()->GetContext().mods->HasAppliedMod(name))
            {
                if (!parts.empty() && parts.front() == "type")
                {
                    parts.erase(parts.begin());

                    return boost::json::string(
                        GetRoot()->GetContext().mods->GetAppliedModType(name));
                }

                auto& lookup = GetRoot()->GetContext().lookup;

                if (!lookup->Exists(name))
                {
                    return nullptr;
                }

                return GetRoot()->GetContext().lookup->GetValue(name);
            }

            std::unordered_map<std::string, TypeTemplateValue> parameters;

            for (const auto &[key, value] : rule->GetTypeArguments())
            {
                parameters.emplace(key, FindValue(value, options));
            }

            const auto &type = child.at("type").as_string().c_str();

            const auto &typeTemplate = GetContext().templates->GetTemplate(type);

            TypeTemplateError error = TypeTemplateError::Success;

            try
            {
                if (options == TypeTemplateQueryOptions::Identifiers) {
                    error = typeTemplate->Prepare(
                        GetRoot()->GetContext(),
                        child,
                        parameters,
                        GetRoot()
                    );
                }
                else {
                    error = typeTemplate->Apply(
                        GetRoot()->GetContext(),
                        child,
                        parameters,
                        GetRoot(),
                        [](const auto &error)
                        {
                            // TODO: Show to user
                            error.Print(0, std::cout);

                            m_NestedErrors.push_back(error);
                        }
                    );
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Failed to apply type template: " << e.what() << std::endl;

                error = TypeTemplateError("Failed to apply type template: " + std::string(e.what()));
            }

            if (!error.IsSuccess())
            {
                std::stringstream ss;

                ss << "Failed to apply type template: ";

                error.Print(0, ss);

                std::cout << ss.str() << std::endl;

                throw std::runtime_error(ss.str());
            }

            if (!parts.empty() && parts.front() == "type")
            {
                parts.erase(parts.begin());

                return boost::json::string(
                    GetRoot()->GetContext().mods->GetAppliedModType(name));
            }

            auto& lookup = GetRoot()->GetContext().lookup;

            if (!lookup->Exists(name))
            {
                return nullptr;
            }

            return GetRoot()->GetContext().lookup->GetValue(name);
        }

        throw std::runtime_error("Invalid id");
    }

    if (type == "enum")
    {
        const auto& enumMap = rule->GetEnumValues(); // "string" -> value

        if (value.is_string())
        {
            const auto& str = value.as_string().c_str();

            if (enumMap.contains(str))
            {
                return enumMap.at(str).GetValue();
            }

            throw std::runtime_error("Invalid enum");
        }

        if (value.is_int64() || value.is_uint64())
        {
            for (const auto& [str, val] : enumMap)
            {
                if (val.GetValue() == value)
                {
                    return val.GetValue();
                }
            }

            throw std::runtime_error("Invalid enum");
        }

        throw std::runtime_error("Invalid enum");
    }

    if (type == "integer")
    {
        if (value.is_int64() || value.is_uint64())
        {
            return value;
        }

        if (value.is_double())
        {
            if (value.as_double() == static_cast<int64_t>(value.as_double()))
            {
                return value;
            }

            throw std::runtime_error("Invalid integer");
        }

        if (value.is_string())
        {
            try
            {
                return std::stoll(value.as_string().c_str());
            }
            catch (const std::exception &)
            {
                throw std::runtime_error("Invalid integer");
            }
        }

        throw std::runtime_error("Invalid integer");
    }

    if (type == "number")
    {
        if (value.is_int64() || value.is_uint64() || value.is_double())
        {
            return value;
        }

        if (value.is_string())
        {
            try
            {
                return std::stod(value.as_string().c_str());
            }
            catch (const std::exception &)
            {
                throw std::runtime_error("Invalid number");
            }
        }

        throw std::runtime_error("Invalid number");
    }

    if (type == "string")
    {
        if (value.is_string())
        {
            return value;
        }

        if (value.is_int64())
        {
            return boost::json::value(std::to_string(value.as_int64()));
        }

        if (value.is_uint64())
        {
            return boost::json::value(std::to_string(value.as_uint64()));
        }

        if (value.is_double())
        {
            return boost::json::value(std::to_string(value.as_double()));
        }

        if (value.is_bool())
        {
            return boost::json::value(value.as_bool() ? "true" : "false");
        }

        throw std::runtime_error("Invalid string");
    }

    if (type == "boolean")
    {
        if (value.is_bool())
        {
            return value;
        }

        if (value.is_string())
        {
            const std::string str = value.as_string().c_str();

            if (str == "true")
            {
                return boost::json::value(true);
            }

            if (str == "false")
            {
                return boost::json::value(false);
            }

            throw std::runtime_error("Invalid boolean");
        }

        if (value.is_int64())
        {
            return boost::json::value(value.as_int64() != 0);
        }

        if (value.is_uint64())
        {
            return boost::json::value(value.as_uint64() != 0);
        }

        if (value.is_double())
        {
            return boost::json::value(value.as_double() != 0);
        }

        throw std::runtime_error("Invalid boolean");
    }

    if (rule != nullptr && rule->GetType() == "resource")
    {
        return ProcessResource(value, parts, rule, options);
    }

    if (value.is_array())
    {
        if (rule == nullptr || rule->GetArrayType() == nullptr)
        {
            throw std::runtime_error("Invalid array");
        }

        const auto& jsonArray = value.as_array();

        if (parts.size() >= 2)
        {
            // Remove the first part
            parts.erase(parts.begin());

            std::string first = parts.front();

            if (first.starts_with("$"))
            {
                const auto &variable = GetRoot()->GetVariable(first.substr(1));
                
                if (!variable.is_string())
                {
                    throw std::runtime_error("Invalid array index");
                }

                first = variable.as_string().c_str();
            }

            if (first == "#length")
            {
                return boost::json::value(jsonArray.size());
            }

            if (first.starts_with("[") && first.ends_with("]"))
            {
                const auto index = first.substr(1, first.size() - 2);

                try
                {
                    const auto i = std::stoi(index);

                    if (i < 0 || i >= jsonArray.size())
                    {
                        throw std::runtime_error("Invalid array index");
                    }

                    //parts.erase(parts.begin());

                    return ProcessValue(jsonArray.at(i), parts, rule->GetArrayType(), options);
                }
                catch (const std::exception &)
                {
                    throw std::runtime_error("Invalid array index");
                }
            }
        }

        boost::json::array array;

        size_t i = 0;

        for (const auto &item : jsonArray)
        {
            try {
                array.push_back(ProcessValue(item, parts, rule->GetArrayType(), options));
            } catch (const std::exception &e) {
                std::cout << "Failed to process array item " << i << ": " << e.what() << std::endl;
            }
        }

        return array;
    }

    if (value.is_object())
    {
        return ProcessObject(value.as_object(), parts, rule, options);
    }

    return value;
}

boost::json::value nejlika::TypeTemplateScope::ProcessResource(
    const boost::json::value &value,
    std::vector<std::string> parts,
    const std::shared_ptr<TypeTemplateParameter> &rule,
    TypeTemplateQueryOptions options
)
{
    if (options != TypeTemplateQueryOptions::Full)
    {
        return value;
    }

    std::unordered_map<std::string, TypeTemplateValue> parameters;

    for (const auto &[key, value] : rule->GetTypeArguments())
    {
        parameters.emplace(key, FindValue(value, options));
    }

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

    if (!value.is_string())
    {
        throw std::runtime_error("Resource value is not a string");
    }

    const std::filesystem::path resource = value.as_string().c_str();

    const std::string prefix = parameters.at("prefix").GetValue().as_string().c_str();
    const std::string &type = parameters.at("type").GetValue().as_string().c_str();

    const auto &root = GetRoot();

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
        const auto str = withoutPrefix.string();

        // If it starts with /, remove it
        if (str.find('/') == 0)
        {
            withoutPrefix = str.substr(1);
        }

        // If it starts with res/, remove it
        if (str.find("res/") == 0)
        {
            withoutPrefix = str.substr(4);
        }

        // Combine with prefix
        const auto combined = prefix + "" + withoutPrefix.string();

        return boost::json::value(combined);
    }

    // Check for a namespace in the resource
    if (std::string(resource).find(':') == std::string::npos && isCoreSymbol)
    {
        throw std::runtime_error("Resource '" + std::string(resource) + "' does not contain a namespace delimiter ':'");
    }

    auto &package = mods->GetModPack(ns);

    std::filesystem::path sourcePath;

    const auto &resources = ModResources::FindResources(
        root->GetContext(),
        resource,
        package.GetResources(),
        sourcePath);

    if (!resources.HasResource(sourcePath))
    {
        throw std::runtime_error("Resource '" + std::string(resource) + "' does not exist");
    }

    const auto &source = resources.GetResourcePath(sourcePath);

    const auto &extension = source.extension().string().substr(1);

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

            throw std::runtime_error(ss.str());
        }
    }
    else if (type != "*")
    {
        if (extension != type)
        {
            throw std::runtime_error("Resource '" + std::string(resource) + "' has an invalid extension, expected '" + std::string(type) + "'");
        }
    }

    auto &ctx = GetRoot()->GetContext();

    const auto &modRelative = source.lexically_relative(ctx.configuration->GetModsDirectory());

    bool preserveFilename = parameters.contains("preserve-filename") && parameters.at("preserve-filename").GetValue().as_bool();

    // Generate a random name
    const auto &destination = preserveFilename ?
          ctx.artifacts->GenerateFilename(ctx, source.filename().string())
        : ctx.artifacts->GenerateRandomFilename(ctx, extension);

    ctx.artifacts->Symlink(ctx, modRelative, destination);

    // Add the icon to the database
    const auto &relative = prefix + "" + destination.string().substr(4);

    if (parameters.contains("fake-extension"))
    {
        const std::string fakeExtension = parameters.at("fake-extension").GetValue().as_string().c_str();

        // Replace the extension
        const std::string fakeRelative = std::filesystem::path(relative).replace_extension(fakeExtension).string();

        return boost::json::value(fakeRelative);
    }

    return boost::json::value(relative);
}
