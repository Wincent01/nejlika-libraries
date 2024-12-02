#pragma once

#include <filesystem>

#include "AbstractSerializable.hpp"

namespace nejlika
{

/**
 * @brief Represents a manifest for a mod pack.
 * 
 * Includes the mod pack's name, list of mod files, and the mod pack's resource directory.
 * 
 * Optionally includes the mod pack's description, version, and author.
 */
class Manifest  : public AbstractSerializable
{
public:
    /**
     * @brief Constructs a new Manifest object.
     */
    Manifest();

    /**
     * @brief Constructs a new Manifest object.
     * 
     * @param name The name of the mod pack.
     * @param description The description of the mod pack.
     * @param version The version of the mod pack.
     * @param author The author of the mod pack.
     * 
     * @note Sets resource directory to "resources".
     */
    Manifest(const std::string& name, const std::string& description, const std::string& version, const std::string& author);

    /**
     * @brief Constructs a new Manifest object.
     * 
     * @param path The path to the manifest file.
     * @throw If the manifest file could not be parsed.
     */
    Manifest(const std::filesystem::path& path);

    /**
     * @brief Gets the name of the mod pack.
     * 
     * @return The name of the mod pack.
     */
    const std::string& GetName() const;

    /**
     * @brief Sets the name of the mod pack.
     * 
     * @param name The name of the mod pack.
     */
    void SetName(const std::string& name);

    /**
     * @brief Gets the description of the mod pack.
     * 
     * @return The description of the mod pack.
     */
    const std::string& GetDescription() const;

    /**
     * @brief Sets the description of the mod pack.
     * 
     * @param description The description of the mod pack.
     */
    void SetDescription(const std::string& description);

    /**
     * @brief Gets the version of the mod pack.
     * 
     * @return The version of the mod pack.
     */
    const std::string& GetVersion() const;

    /**
     * @brief Sets the version of the mod pack.
     * 
     * @param version The version of the mod pack.
     */
    void SetVersion(const std::string& version);

    /**
     * @brief Gets the author of the mod pack.
     * 
     * @return The author of the mod pack.
     */
    const std::string& GetAuthor() const;

    /**
     * @brief Sets the author of the mod pack.
     * 
     * @param author The author of the mod pack.
     */
    void SetAuthor(const std::string& author);

    /**
     * @brief Gets the list of mod files.
     * 
     * @return The list of mod files.
     */
    const std::vector<std::string>& GetModFiles() const;

    /**
     * @brief Sets the list of mod files.
     * 
     * @param modFiles The list of mod files.
     */
    void SetModFiles(const std::vector<std::string>& modFiles);

    /**
     * @brief Gets the resource directory of the mod pack.
     * 
     * @return The resource directory of the mod pack.
     */
    const std::string& GetResourceDirectory() const;

    /**
     * @brief Sets the resource directory of the mod pack.
     * 
     * @param resourceDirectory The resource directory of the mod pack.
     */
    void SetResourceDirectory(const std::string& resourceDirectory);

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

private:
    std::string m_Name;

    std::string m_Description;

    std::string m_Version;

    std::string m_Author;

    std::vector<std::string> m_ModFiles;

    std::string m_ResourceDirectory;
};

}