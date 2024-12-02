#include "AbstractMod.hpp"

#include <sstream>
#include <iostream>

#include "Lookup.hpp"
#include "TypeTemplate.hpp"
#include "TypeTemplateWrapper.hpp"
#include "TypeTemplateInterface.hpp"

using namespace nejlika;

std::shared_ptr<AbstractMod> nejlika::AbstractMod::Parse(nejlika::Context& ctx, const boost::json::object &json)
{
    if (!json.contains("type"))
    {
        throw std::runtime_error("Missing 'type' in mod");
    }

    // Get the type of the mod
    auto type = json.at("type").as_string().c_str();

    if (ctx.templates->HasTemplate(type))
    {
        const auto mod = std::make_shared<TypeTemplateWrapper>();

        mod->Deserialize(json);

        return mod;
    }

    if (nejlika::allowUnknownMods)
    {
        const auto mod = std::make_shared<AbstractMod>();

        mod->Deserialize(json);

        return mod;
    }

    std::stringstream ss;

    ss << "Unknown mod type: " << type;

    throw std::runtime_error(ss.str());
}

const name &nejlika::AbstractMod::GetName() const
{
    return m_Name;
}

const std::string &nejlika::AbstractMod::GetType() const
{
    return m_Type;
}

const id &nejlika::AbstractMod::GetExplicitId() const
{
    return m_ExplicitId;
}

const std::vector<name> &nejlika::AbstractMod::GetAliases() const
{
    return m_Aliases;
}

bool nejlika::AbstractMod::CanIdentifyWith(const name &name) const
{
    if (m_Name == name)
    {
        return true;
    }

    for (const auto &alias : m_Aliases)
    {
        if (alias == name)
        {
            return true;
        }
    }

    return false;
}

const std::string &nejlika::AbstractMod::GetAction() const
{
    return m_Action;
}

bool nejlika::AbstractMod::GetShowDefaults() const
{
    return m_ShowDefaults;
}

void nejlika::AbstractMod::Apply(nejlika::Context &ctx)
{
    std::stringstream ss;

    ss << "Mod \"" << m_Name << "\" does not implement Apply.";

    std::cout << ss.str() << std::endl;
    // Do nothing
}

boost::json::object nejlika::AbstractMod::Serialize() const
{
    boost::json::object json;

    json["name"] = m_Name;
    json["type"] = m_Type;

    if (m_ExplicitId)
    {
        json["explicit-id"] = m_ExplicitId;
    }

    if (!m_Aliases.empty())
    {
        boost::json::array aliases;

        for (const auto &alias : m_Aliases)
        {
            aliases.emplace_back(alias);
        }

        json["aliases"] = aliases;
    }

    if (!m_Action.empty())
    {
        json["action"] = m_Action;
    }

    if (m_ShowDefaults)
    {
        json["show-defaults"] = m_ShowDefaults;
    }

    if (!m_ExtraData.empty())
    {
        json["extra-data"] = boost::json::parse(m_ExtraData);
    }

    return json;
}

void nejlika::AbstractMod::Deserialize(const boost::json::object &json)
{
    // Required
    // 'name' has 'id' as a fallback
    if (json.contains("name"))
    {
        m_Name = json.at("name").as_string().c_str();
    }
    else
    {
        m_Name = json.at("id").as_string().c_str();
    }

    m_Type = json.at("type").as_string().c_str();

    // Optional
    if (json.contains("explicit-id"))
    {
        m_ExplicitId = json.at("explicit-id").as_int64();
    }

    // 'aliases' has 'old-ids' as a fallback
    if (json.contains("aliases"))
    {
        for (const auto &alias : json.at("aliases").as_array())
        {
            m_Aliases.emplace_back(alias.as_string().c_str());
        }
    }
    else if (json.contains("old-ids"))
    {
        for (const auto &alias : json.at("old-ids").as_array())
        {
            m_Aliases.emplace_back(alias.as_string().c_str());
        }
    }

    if (json.contains("action"))
    {
        m_Action = json.at("action").as_string().c_str();
    }

    if (json.contains("show-defaults"))
    {
        m_ShowDefaults = json.at("show-defaults").as_bool();
    }

    if (json.contains("extra-data"))
    {
        if (!json.at("extra-data").is_object())
        {
            throw std::runtime_error("extra-data must be an object");
        }

        m_ExtraData = boost::json::serialize(json.at("extra-data").as_object());
    }
}

bool nejlika::AbstractMod::TryGetId(nejlika::Context& ctx, id &modId) const
{
    if (ctx.lookup->Exists(m_Name))
    {
        modId = ctx.lookup->GetValue(m_Name);

        return true;
    }

    for (const auto& alias : m_Aliases)
    {
        if (ctx.lookup->Exists(alias))
        {
            modId = ctx.lookup->GetValue(alias);

            return true;
        }
    }

    if (m_ExplicitId != 0)
    {
        modId = m_ExplicitId;

        return true;
    }

    return false;
}

size_t nejlika::AbstractMod::GetUniqueRuntimeId() const
{
    return m_UniqueRuntimeId;
}

void nejlika::AbstractMod::SetUniqueRuntimeId(size_t uniqueRuntimeId)
{
    m_UniqueRuntimeId = uniqueRuntimeId;
}

void nejlika::AbstractMod::Rename(const name &name)
{
    m_Aliases.emplace_back(m_Name);

    m_Name = name;
}
