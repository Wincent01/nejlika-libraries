#include "Localization.hpp"

#include <sstream>

using namespace nejlika;

const std::string nejlika::Localization::m_EmptyString = "";

nejlika::Localization::Localization()
{
}

const std::string &nejlika::Localization::Get(const std::string &languageCode) const
{
    const auto &it = m_Strings.find(languageCode);

    if (it == m_Strings.end())
    {
        return m_EmptyString;
    }

    return it->second;
}

void nejlika::Localization::Set(const std::string &languageCode, const std::string &value)
{
    m_Strings.emplace(languageCode, value);
}

const std::map<std::string, std::string> &nejlika::Localization::GetMap() const
{
    return m_Strings;
}

bool nejlika::Localization::IsEmpty() const
{
    return m_Strings.empty();
}

const std::string &nejlika::Localization::operator[](const std::string &languageCode) const
{
    return Get(languageCode);
}

std::string &nejlika::Localization::operator[](const std::string &languageCode)
{
    return m_Strings[languageCode];
}

boost::json::object nejlika::Localization::Serialize() const
{
    boost::json::object json;

    for (const auto &it : m_Strings)
    {
        json.emplace(it.first, it.second);
    }

    return json;
}

void nejlika::Localization::Deserialize(const boost::json::object &json)
{
    m_Strings.clear();

    for (const auto &[k, v] : json)
    {
        m_Strings.emplace(k, v.as_string());
    }
}

tinyxml2::XMLElement *nejlika::Localization::Serialize(tinyxml2::XMLDocument &document) const
{
    auto xml = document.NewElement("phrase");

    for (const auto &it : m_Strings)
    {
        auto string = document.NewElement("translation");

        string->SetAttribute("locale", it.first.c_str());
        string->SetText(it.second.c_str());

        xml->InsertEndChild(string);
    }

    return xml;
}

void nejlika::Localization::Deserialize(const tinyxml2::XMLElement *xml)
{
    m_Strings.clear();

    for (const auto *string = xml->FirstChildElement("translation"); string != nullptr; string = string->NextSiblingElement("translation"))
    {
        auto locale = string->Attribute("locale");
        auto text = string->GetText();

        if (text == nullptr)
        {
            text = "";
        }

        m_Strings.emplace(locale, text);
    }
}
