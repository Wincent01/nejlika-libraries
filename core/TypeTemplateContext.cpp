#include "TypeTemplateContext.hpp"

#include "TypeTemplateScope.hpp"

#include <iostream>

using namespace nejlika;

TypeTemplateContext::TypeTemplateContext(const std::shared_ptr<TypeTemplateContext>& parent, nejlika::Context* ctx)
{
    m_Parent = parent;
    m_Context = ctx;
}

const boost::json::value& TypeTemplateContext::GetVariable(const std::string& key) const
{
    auto it = m_Variables.find(key);
    if (it != m_Variables.end())
    {
        return it->second;
    }
    else if (m_Parent)
    {
        return m_Parent->GetVariable(key);
    }
    else
    {
        throw std::runtime_error("Variable not found: " + key);
    }
}

void TypeTemplateContext::SetVariable(const std::string& key, const boost::json::value& value)
{
    m_Variables[key] = value;
}

bool nejlika::TypeTemplateContext::HasVariable(const std::string &key) const
{
    auto it = m_Variables.find(key);
    
    if (it != m_Variables.end())
    {
        return true;
    }
    
    return m_Parent && m_Parent->HasVariable(key);
}

const std::shared_ptr<TypeTemplateScope>& nejlika::TypeTemplateContext::GetParameter(const std::string &key) const
{
    auto it = m_Parameters.find(key);
    if (it != m_Parameters.end())
    {
        return it->second;
    }
    else if (m_Parent)
    {
        return m_Parent->GetParameter(key);
    }
    else
    {
        throw std::runtime_error("Parameter not found: " + key);
    }
}

void TypeTemplateContext::SetParameter(const std::string& key, const std::shared_ptr<TypeTemplateScope>& value)
{
    m_Parameters[key] = value;
}

const std::shared_ptr<TypeTemplateContext>& TypeTemplateContext::GetParent() const
{
    return m_Parent;
}

boost::json::value nejlika::TypeTemplateContext::FindValue(const TypeTemplateValue &value, TypeTemplateQueryOptions options)
{
    const auto& core = value.GetValue();

    if (core.is_object())
    {
        auto& object = core.as_object();

        if (!object.contains("value"))
        {
            return core;
        }

        try {
            return FindValue(object.at("value"), options);
        } catch (const std::exception& e) {
            if (object.contains("default"))
            {
                return object.at("default");
            }
            else
            {
                throw e;
            }
        }
    }

    if (!core.is_array())
    {
        return core;
    }

    std::vector<std::string> parts;

    for (const auto& item : core.as_array())
    {
        if (!item.is_string())
        {
            throw std::runtime_error("Invalid path");
        }

        parts.push_back(item.as_string().c_str());
    }

    return FindValue(parts, options);
}

nejlika::Context &TypeTemplateContext::GetContext() const
{
    return *m_Context;
}

boost::json::value nejlika::TypeTemplateContext::FindValue(std::vector<std::string> parts, TypeTemplateQueryOptions options)
{
    const auto& top = parts.front();

    if (top == "variable")
    {
        if (parts.size() != 2)
        {
            throw std::runtime_error("Invalid path");
        }

        const auto& variable = GetVariable(parts.at(1));

        return variable;
    }
    else if (top == "parameter")
    {
        if (parts.size() < 2)
        {
            throw std::runtime_error("Invalid path");
        }

        const auto& parameter = GetParameter(parts.at(1));

        // Remove the first two parts
        parts.erase(parts.begin(), parts.begin() + 2);

        return parameter->InternalFindValue(parts, options);
    }
    else if (top == "parent")
    {
        if (parts.size() < 2)
        {
            throw std::runtime_error("Invalid path");
        }

        // Remove the first part
        parts.erase(parts.begin());

        return m_Parent->FindValue(parts, options);
    }

    const auto& variableIt = m_Variables.find(top);
    
    // Check if the value is in the variables or parameters
    if (variableIt != m_Variables.end())
    {
        if (parts.size() != 1)
        {
            throw std::runtime_error("Invalid path");
        }

        return variableIt->second;
    }

    if (m_Parameters.contains(top))
    {
        const auto& parameter = m_Parameters.at(top);

        // Remove the first part
        parts.erase(parts.begin());

        return parameter->InternalFindValue(parts, options);
    }

    throw std::runtime_error("Invalid path");
}
