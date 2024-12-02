#include "TypeTemplateParameter.hpp"
#include "TypeTemplateValue.hpp"

using namespace nejlika;

nejlika::TypeTemplateParameter::TypeTemplateParameter()
{
}

nejlika::TypeTemplateParameter::TypeTemplateParameter(const std::string& name, const std::vector<std::shared_ptr<TypeTemplateParameter>>& objectProperties)
{
    this->name = name;
    this->objectProperties = objectProperties;

    type = "object";
}

const std::string &nejlika::TypeTemplateParameter::GetName() const
{
    return name;
}

const std::string & nejlika::TypeTemplateParameter::GetDescription() const
{
    return description;
}

const std::string & nejlika::TypeTemplateParameter::GetType() const
{
    return type;
}

bool nejlika::TypeTemplateParameter::IsRequired() const
{
    return required;
}

bool nejlika::TypeTemplateParameter::IsNullable() const
{
    return nullable;
}

const boost::json::value& nejlika::TypeTemplateParameter::GetDefaultValue() const
{
    return defaultValue;
}

bool nejlika::TypeTemplateParameter::HasDefault() const
{
    return hasDefault;
}

const std::unordered_map<std::string, TypeTemplateValue> &nejlika::TypeTemplateParameter::GetTypeArguments() const
{
    return typeArguments;
}

const std::vector<std::string>& nejlika::TypeTemplateParameter::GetAliases() const
{
    return aliases;
}

const std::shared_ptr<TypeTemplateParameter>& nejlika::TypeTemplateParameter::GetArrayType() const
{
    return arrayType;
}

const std::vector<std::shared_ptr<TypeTemplateParameter>>& nejlika::TypeTemplateParameter::GetObjectProperties() const
{
    return objectProperties;
}

const std::shared_ptr<TypeTemplateParameter>& nejlika::TypeTemplateParameter::FindObjectProperty(const std::string &name) const
{
    for (const auto& property : objectProperties)
    {
        if (property->GetName() == name)
        {
            return property;
        }
    }

    throw std::runtime_error("Object property not found.");
}

bool nejlika::TypeTemplateParameter::HasObjectProperty(const std::string &name) const
{
    for (const auto& property : objectProperties)
    {
        if (property->GetName() == name)
        {
            return true;
        }
    }

    return false;
}

const std::unordered_map<std::string, TypeTemplateValue> &nejlika::TypeTemplateParameter::GetEnumValues() const
{
    return enumValues;
}

void nejlika::TypeTemplateParameter::Deserialize(const boost::json::object &json)
{
    if (json.contains("name") && json.at("name").is_string())
    {
        name = json.at("name").as_string().c_str();
    }

    if (json.contains("description") && json.at("description").is_string())
    {
        description = json.at("description").as_string().c_str();
    }

    if (!json.contains("type") || !json.at("type").is_string())
    {
        throw std::runtime_error("Parameter type is missing or not a string.");
    }

    type = json.at("type").as_string().c_str();

    if (json.contains("required") && json.at("required").is_bool())
    {
        required = json.at("required").as_bool();
    }
    else
    {
        required = true;
    }

    if (json.contains("nullable") && json.at("nullable").is_bool())
    {
        nullable = json.at("nullable").as_bool();
    }
    else
    {
        nullable = false;
    }

    if (json.contains("default"))
    {
        hasDefault = true;

        defaultValue = json.at("default");
    }
    else
    {
        hasDefault = false;
    }

    if (json.contains("arguments") && json.at("arguments").is_object())
    {
        for (const auto& [key, value] : json.at("arguments").as_object())
        {
            typeArguments.emplace(key, TypeTemplateValue(value));
        }
    }

    if (json.contains("aliases") && json.at("aliases").is_array())
    {
        for (const auto& value : json.at("aliases").as_array())
        {
            aliases.push_back(value.as_string().c_str());
        }
    }

    if (json.contains("array-type") && json.at("array-type").is_object())
    {
        arrayType = std::make_shared<TypeTemplateParameter>();
        arrayType->Deserialize(json.at("array-type").as_object());
    }
    else if (type == "array")
    {
        throw std::runtime_error("Array type is missing.");
    }

    if (json.contains("object-properties"))
    {
        objectProperties = TypeTemplateParameter::DeserializeParameters(json.at("object-properties"));
    }

    if (type == "enum")
    {
        if (!json.contains("enum") )
        {
            throw std::runtime_error("Enum values are missing.");
        }

        if (json.at("enum").is_object())
        {
            for (const auto& [key, value] : json.at("enum").as_object())
            {
                enumValues.emplace(key, TypeTemplateValue(value));
            }
        }
        else if (json.at("enum").is_array())
        {
            for (const auto& value : json.at("enum").as_array())
            {
                enumValues.emplace(value.as_string().c_str(), TypeTemplateValue(value));
            }
        }
        else
        {
            throw std::runtime_error("Enum values are not an object or array.");
        }
    }

    if (type == "id")
    {
        if (json.contains("types") && json.at("types").is_array())
        {
            for (const auto& value : json.at("types").as_array())
            {
                idTypes.emplace(value.as_string().c_str());
            }
        }
    }
}

std::vector<std::shared_ptr<TypeTemplateParameter>> nejlika::TypeTemplateParameter::DeserializeParameters(const boost::json::value &json)
{
    std::vector<std::shared_ptr<TypeTemplateParameter>> parameters;

    if (json.is_object())
    {
        for (const auto& [key, value] : json.as_object())
        {
            auto parameter = std::make_shared<TypeTemplateParameter>();
            parameter->Deserialize(value.as_object());
            parameter->name = key;
            parameters.push_back(parameter);
        }
    }
    else if (json.is_array())
    {
        for (const auto& value : json.as_array())
        {
            parameters.emplace_back(std::make_shared<TypeTemplateParameter>());
            parameters.back()->Deserialize(value.as_object());
        }
    }
    else
    {
        throw std::runtime_error("JSON value is not an object or array.");
    }

    return parameters;
}

const std::unordered_set<std::string> &nejlika::TypeTemplateParameter::GetIdTypes() const
{
    return idTypes;
}

boost::json::object nejlika::TypeTemplateParameter::Serialize() const
{
    boost::json::object json;

    json["name"] = name;
    json["description"] = description;
    json["type"] = type;
    json["required"] = required;
    json["nullable"] = nullable;
    json["default"] = defaultValue;

    if (!typeArguments.empty())
    {
        boost::json::object arguments;

        for (const auto& [key, value] : typeArguments)
        {
            arguments[key] = value.GetValue();
        }

        json["arguments"] = arguments;
    }

    if (!aliases.empty())
    {
        boost::json::array array;

        for (const auto& value : aliases)
        {
            array.emplace_back(value);
        }

        json["aliases"] = array;
    }

    if (arrayType)
    {
        json["array-type"] = arrayType->Serialize();
    }

    if (!objectProperties.empty())
    {
        boost::json::array array;

        for (const auto& value : objectProperties)
        {
            array.push_back(value->Serialize());
        }

        json["object-properties"] = array;
    }

    return json;
}
