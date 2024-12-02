#include "TypeTemplateAction.hpp"

using namespace nejlika;

boost::json::object nejlika::TypeTemplateAction::Serialize() const
{
    return boost::json::object();
}

void nejlika::TypeTemplateAction::Deserialize(const boost::json::object &json)
{
    if (json.contains("name"))
    {
        const auto& name = json.at("name");

        if (!name.is_string())
        {
            throw std::runtime_error("TypeTemplateAction::Deserialize: 'name' field is not a string.");
        }

        m_Name = name.as_string().c_str();
    }

    if (json.contains("description"))
    {
        const auto& description = json.at("description");

        if (!description.is_string())
        {
            throw std::runtime_error("TypeTemplateAction::Deserialize: 'description' field is not a string.");
        }

        m_Description = description.as_string().c_str();
    }

    if (json.contains("prepare"))
    {
        const auto& prepare = json.at("prepare");

        if (!prepare.is_array())
        {
            throw std::runtime_error("TypeTemplateAction::Deserialize: 'prepare' field is not an array.");
        }

        for (const auto& operation : prepare.as_array())
        {
            if (!operation.is_object())
            {
                throw std::runtime_error("TypeTemplateAction::Deserialize: 'prepare' field contains a non-object element.");
            }

            m_PrepareOperations.push_back(operation.as_object());
        }
    }

    if (!json.contains("apply"))
    {
        throw std::runtime_error("TypeTemplateAction::Deserialize: Missing 'apply' field.");
    }

    const auto& apply = json.at("apply");

    if (!apply.is_array())
    {
        throw std::runtime_error("TypeTemplateAction::Deserialize: 'apply' field is not an array.");
    }

    for (const auto& operation : apply.as_array())
    {
        if (!operation.is_object())
        {
            throw std::runtime_error("TypeTemplateAction::Deserialize: 'apply' field contains a non-object element.");
        }

        m_ApplyOperations.push_back(operation.as_object());
    }
}

const std::string &nejlika::TypeTemplateAction::GetName() const
{
    return m_Name;
}

const std::string &nejlika::TypeTemplateAction::GetDescription() const
{
    return m_Description;
}

const std::vector<boost::json::object> &nejlika::TypeTemplateAction::GetPrepareOperations() const
{
    return m_PrepareOperations;
}

const std::vector<boost::json::object> &nejlika::TypeTemplateAction::GetApplyOperations() const
{
    return m_ApplyOperations;
}

std::vector<std::shared_ptr<TypeTemplateAction>> nejlika::TypeTemplateAction::DeserializeActions(const boost::json::value &json)
{
    std::vector<std::shared_ptr<TypeTemplateAction>> parameters;

    if (json.is_object())
    {
        for (const auto& [key, value] : json.as_object())
        {
            auto parameter = std::make_shared<TypeTemplateAction>();
            parameter->Deserialize(value.as_object());
            parameter->m_Name = key;
            parameters.push_back(parameter);
        }
    }
    else if (json.is_array())
    {
        for (const auto& value : json.as_array())
        {
            parameters.emplace_back(std::make_shared<TypeTemplateAction>());
            parameters.back()->Deserialize(value.as_object());
        }
    }
    else
    {
        throw std::runtime_error("JSON value is not an object or array.");
    }

    return parameters;
}
