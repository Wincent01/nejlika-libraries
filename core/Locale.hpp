#pragma once

#include <filesystem>

#include <tinyxml2.h>

#include <map>

#include "Localization.hpp"

namespace nejlika
{

/**
 * @brief Represents the locale of the client.
 * 
 * A list of phrases and their localized strings.
 * 
 * @see Localization
 */
class Locale
{
public:
    /**
     * @brief Constructs a new Locale object.
     */
    Locale();

    /**
     * @brief Constructs the locale from the specified file.
     * 
     * @param path The path to the locale file.
     * @throw If the locale file could not be parsed.
     */
    Locale(const std::filesystem::path& path);

    /**
     * @brief Get the localization for a specific phrase.
     * 
     * @param phrase The phrase to get the localization for.
     * @return The localization for the specified phrase.
     * @throw If the phrase is not found.
     */
    const Localization& Get(const std::string& phrase) const;

    /**
     * @brief Set the localization for a specific phrase.
     * 
     * @param phrase The phrase to set the localization for.
     * @param localization The localization to set.
     */
    void Set(const std::string& phrase, const Localization& localization);

    /**
     * @brief Remove the localization for a specific phrase.
     * 
     * @param phrase The phrase to remove the localization for.
     */
    bool Remove(const std::string& phrase);

    /**
     * @brief Checks if the specified phrase is localized.
     * 
     * @param phrase The phrase to check.
     * @return True if the phrase is localized, false otherwise.
     */
    bool IsLocalized(const std::string& phrase) const;

    /**
     * @brief Gets the localization for a specific phrase.
     * 
     * @param phrase The phrase to get the localization for.
     * @return The localization for the specified phrase.
     * @throw If the phrase is not found.
     */
    const Localization& operator[](const std::string& phrase) const;

    /**
     * @brief Gets the localization for a specific phrase.
     * 
     * @param phrase The phrase to get the localization for.
     * @return The localization for the specified phrase.
     * @throw If the phrase is not found.
     */
    Localization& operator[](const std::string& phrase);

    /**
     * @brief Deserializes the object from an XML tree.
     * 
     * @param tree The XML tree to deserialize.
     */
    void Deserialize(const tinyxml2::XMLDocument& tree);

    /**
     * @brief Serializes the object into an XML tree.
     * 
     * @param tree The XML tree to serialize into.
     */
    void Serialize(tinyxml2::XMLDocument& tree) const;

private:
    std::map<std::string, Localization> m_Localizations;
};

}

