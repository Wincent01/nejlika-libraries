#include "Locale.hpp"

#include <sstream>
#include <iostream>
#include <unordered_set>

using namespace nejlika;

nejlika::Locale::Locale()
{
}

nejlika::Locale::Locale(const std::filesystem::path &path)
{
    tinyxml2::XMLDocument tree;

    auto result = tree.LoadFile(path.string().c_str());

    if (result != tinyxml2::XML_SUCCESS)
    {
        std::stringstream ss;

        ss << "Failed to load locale file \"" << path << "\". Error code: " << result;

        throw std::runtime_error(ss.str());
    }

    Deserialize(tree);
}

const nejlika::Localization& nejlika::Locale::Get(const std::string& phrase) const
{
    const auto& it = m_Localizations.find(phrase);

    if (it == m_Localizations.end())
    {
        std::stringstream ss;

        ss << "Phrase \"" << phrase << "\" does not exist in the locale.";

        throw std::runtime_error(ss.str());
    }

    return it->second;
}

void nejlika::Locale::Set(const std::string& phrase, const Localization& localization)
{
    // Debug message
    std::stringstream ss;
    
    const auto& it = m_Localizations.find(phrase);

    if (it != m_Localizations.end())
    {
        ss.str("");

        ss << "Replacing localization for phrase \"" << phrase << "\", from \"" << it->second.Get("en_US") << "\" to \"" << localization.Get("en_US") << "\".";

        it->second = localization;
        return;
    }
    
    m_Localizations.emplace(phrase, localization);
}

bool nejlika::Locale::Remove(const std::string &phrase)
{
    return m_Localizations.erase(phrase) > 0;
}

bool nejlika::Locale::IsLocalized(const std::string& phrase) const
{
    return m_Localizations.find(phrase) != m_Localizations.end();
}

const nejlika::Localization& nejlika::Locale::operator[](const std::string& phrase) const
{
    return Get(phrase);
}

nejlika::Localization& nejlika::Locale::operator[](const std::string& phrase)
{
    return m_Localizations[phrase];
}

void nejlika::Locale::Deserialize(const tinyxml2::XMLDocument &tree)
{

    auto root = tree.FirstChildElement("localization");

    if (!root)
    {
        throw std::runtime_error("Invalid localization file, root element not found.");
    }

    // Get the phrases
    auto phrases = root->FirstChildElement("phrases");

    if (!phrases)
    {
        throw std::runtime_error("Invalid localization file, phrases element not found.");
    }

    // Get the count
    auto count = phrases->IntAttribute("count");

    if (count == 0)
    {
        throw std::runtime_error("Invalid localization file, phrases count is 0.");
    }

    // Get the locale
    for (const auto *phrase = phrases->FirstChildElement("phrase"); phrase != nullptr; phrase = phrase->NextSiblingElement("phrase"))
    {
        // Get the id
        auto id = phrase->Attribute("id");

        if (!id)
        {
            throw std::runtime_error("Invalid localization file, phrase id not found.");
        }

        Localization localization;

        localization.Deserialize(phrase);

        m_Localizations.emplace(id, localization);
    }
}

void nejlika::Locale::Serialize(tinyxml2::XMLDocument &tree) const
{
    auto root = tree.NewElement("localization");

    root->SetAttribute("version", "1.2");
    root->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
    root->SetAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");

    tree.InsertEndChild(root);

    // Serialize the locales
    auto locales = tree.NewElement("locales");

    root->InsertEndChild(locales);

    // Serialize the phrases
    auto phrases = tree.NewElement("phrases");

    root->InsertEndChild(phrases);

    phrases->SetAttribute("count", m_Localizations.size());

    // Keep track of all languages
    std::unordered_set<std::string> languages;

    for (const auto& it : m_Localizations)
    {
        auto phrase = it.second.Serialize(tree);

        phrase->SetAttribute("id", it.first.c_str());

        phrases->InsertEndChild(phrase);

        const auto& map = it.second.GetMap();

        for (const auto& it : map)
        {
            languages.emplace(it.first);
        }
    }

    locales->SetAttribute("count", languages.size());

    for (const auto& it : languages)
    {
        auto locale = tree.NewElement("locale");

        locale->SetText(it.c_str());

        locales->InsertEndChild(locale);
    }
}
