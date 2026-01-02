#pragma once

#include <string>
#include <map>

#include <tinyxml2.h>

#include "AbstractSerializable.hpp"

namespace nejlika
{

/**
 * @brief Represents a localization.
 *
 * A map of language codes to localized strings.
 */
class Localization : public AbstractSerializable
{
public:
    /**
     * @brief Constructs a new Localization object.
     */
    Localization();

    /**
     * @brief Constructs a new Localization object from a map of language codes to localized strings.
     */
    Localization(const std::map<std::string, std::string>& strings);

    /**
     * @brief Gets the localized string for the specified language code.
     *
     * @param languageCode The language code to get the localized string for.
     * @return The localized string for the specified language code or an empty string if the language code is not found.
     */
    const std::string& Get(const std::string& languageCode) const;

    /**
     * @brief Sets the localized string for the specified language code.
     *
     * @param languageCode The language code to set the localized string for.
     * @param value The localized string to set.
     */
    void Set(const std::string& languageCode, const std::string& value);

    /**
     * @brief Get the map of language codes to localized strings.
     *
     * @return The map of language codes to localized strings.
     */
    const std::map<std::string, std::string>& GetMap() const;

    /**
     * @brief Gets weather or not any localized strings exist.
     *
     * @return Weather or not any localized strings exist.
     */
    bool IsEmpty() const;

    /**
     * @brief Gets the localized string for the specified language code.
     *
     * @param languageCode The language code to get the localized string for.
     * @return The localized string for the specified language code or an empty string if the language code is not found.
     */
    const std::string& operator[](const std::string& languageCode) const;

    /**
     * @brief Gets the localized string for the specified language code.
     *
     * @param languageCode The language code to get the localized string for.
     * @return The localized string for the specified language code or an empty string if the language code is not found.
     */
    std::string& operator[](const std::string& languageCode);

    /**
     * @brief Serializes the object into a JSON object.
     *
     * @return The serialized JSON object.
     */
    boost::json::object Serialize() const override;

    /**
     * @brief Deserializes the specified JSON object into the object.
     *
     * @param json The JSON object to deserialize.
     */
    void Deserialize(const boost::json::object& json) override;

    /**
     * @brief Serializes the object into a XML object.
     *
     * @return The serialized XML object.
     */
    tinyxml2::XMLElement* Serialize(tinyxml2::XMLDocument& document) const;

    /**
     * @brief Deserializes the specified XML object into the object.
     *
     * @param xml The XML object to deserialize.
     */
    void Deserialize(const tinyxml2::XMLElement* xml);

private:
    static const std::string m_EmptyString;

    std::map<std::string, std::string> m_Strings;
};

} // namespace nejlika