#pragma once

#include <filesystem>
#include <string>
#include <vector>
#include <unordered_map>

namespace nejlika {

class Configuration
{
public:
    /**
     * @brief Constructs an empty Configuration object.
     */
    Configuration();

    /**
     * @brief Constructs a Configuration object with the specified configuration file path.
     *
     * @param configuration The path to the configuration file.
     * @throw If the configuration file could not be parsed.
     */
    Configuration(const std::filesystem::path& configuration);

    /**
     * @brief Saves the configuration to the configuration file.
     * @throw If the configuration file could not be saved.
     */
    void Save() const;

    /**
     * @brief Gets the path to the configuration file.
     * 
     * @return The path to the configuration file.
     */
    const std::filesystem::path& GetConfiguration() const;

    /**
     * @brief Gets the path to the directory containing the client executable.
     *
     * @return The path to the directory containing the client executable.
     */
    const std::filesystem::path& GetClient() const;

    /**
     * @brief Gets the path to the database SQLite file.
     *
     * @return The path to the database SQLite file.
     */
    const std::filesystem::path& GetDatabase() const;

    /**
     * @brief Gets the path to the sqlite_to_fdb executable.
     *
     * @return The path to the sqlite_to_fdb executable.
     */
    const std::filesystem::path& GetSqliteToFdb() const;

    /**
     * @brief Gets the path to the fdb_to_sqlite executable.
     *
     * @return The path to the fdb_to_sqlite executable.
     */
    const std::filesystem::path& GetFdbToSqlite() const;
    
    /**
     * @brief Gets the path to the lookup file.
     *
     * @return The path to the lookup file.
     */
    const std::filesystem::path& GetLookup() const;
    
    /**
     * @brief Gets the path to the locale file.
     *
     * @return The path to the locale file.
     */
    const std::filesystem::path& GetLocale() const;

    /**
     * @brief Gets the path to the mods directory.
     *
     * @return The path to the mods directory.
     */
    const std::filesystem::path& GetModsDirectory() const;

    /**
     * @brief Gets the path to the artifacts directory.
     *
     * @return The path to the artifacts directory.
     */
    const std::filesystem::path& GetArtifactsDirectory() const;

    /**
     * @brief Gets the path to the added resources directory.
     *
     * @return The path to the added resources directory.
     */
    const std::filesystem::path& GetAddedResourcesDirectory() const;

    /**
     * @brief Gets the pre-commands.
     *
     * @return The pre-commands.
     */
    const std::vector<std::string>& GetPreCommands() const;

    /**
     * @brief Gets the post-commands.
     *
     * @return The post-commands.
     */
    const std::vector<std::string>& GetPostCommands() const;

    /**
     * @brief Gets the client mirrors.
     *
     * @return The client mirrors.
     */
    const std::vector<std::filesystem::path>& GetClientMirrors() const;

    /**
     * @brief Get whether or not this project is public.
     * 
     * @return True if the project is public, false otherwise.
     */
    bool IsPublic() const;

    /**
     * @brief Sets the path to the configuration file.
     * 
     * @param configuration The path to the configuration file.
     */
    void SetConfiguration(const std::filesystem::path& configuration);

    /**
     * @brief Sets the path to the directory containing the client executable.
     *
     * @param client The path to the directory containing the client executable.
     */
    void SetClient(const std::filesystem::path& client);

    /**
     * @brief Sets the path to the database SQLite file.
     *
     * @param database The path to the database SQLite file.
     */
    void SetDatabase(const std::filesystem::path& database);

    /**
     * @brief Sets the path to the sqlite_to_fdb executable.
     *
     * @param sqliteToFdb The path to the sqlite_to_fdb executable.
     */
    void SetSqliteToFdb(const std::filesystem::path& sqliteToFdb);

    /**
     * @brief Sets the path to the fdb_to_sqlite executable.
     *
     * @param fdbToSqlite The path to the fdb_to_sqlite executable.
     */
    void SetFdbToSqlite(const std::filesystem::path& fdbToSqlite);

    /**
     * @brief Sets the path to the lookup file.
     *
     * @param lookup The path to the lookup file.
     */
    void SetLookup(const std::filesystem::path& lookup);

    /**
     * @brief Sets the path to the locale file.
     *
     * @param locale The path to the locale file.
     */
    void SetLocale(const std::filesystem::path& locale);

    /**
     * @brief Sets the path to the mods directory.
     *
     * @param modsDirectory The path to the mods directory.
     */
    void SetModsDirectory(const std::filesystem::path& modsDirectory);

    /**
     * @brief Sets the path to the artifacts directory.
     *
     * @param artifactsDirectory The path to the artifacts directory.
     */
    void SetArtifactsDirectory(const std::filesystem::path& artifactsDirectory);

    /**
     * @brief Sets the path to the added resources directory.
     *
     * @param addedResourcesDirectory The path to the added resources directory.
     */
    void SetAddedResourcesDirectory(const std::filesystem::path& addedResourcesDirectory);

    /**
     * @brief Sets the pre-commands.
     *
     * @param preCommands The pre-commands.
     */
    void SetPreCommands(const std::vector<std::string>& preCommands);

    /**
     * @brief Sets the post-commands.
     *
     * @param postCommands The post-commands.
     */
    void SetPostCommands(const std::vector<std::string>& postCommands);

    /**
     * @brief Sets the client mirrors.
     *
     * @param clientMirrors The client mirrors.
     */
    void SetClientMirrors(const std::vector<std::filesystem::path>& clientMirrors);

    /**
     * @brief Set whether or not this project is public.
     * 
     * @param isPublic True if the project is public, false otherwise.
     */
    void SetPublic(bool isPublic);

    /**
     * @brief Gets a variable.
     *
     * @param name The name of the variable.
     * @return The value of the variable.
     */
    const std::string& GetVariable(const std::string& name) const;

    /**
     * @brief Sets a variable.
     *
     * @param name The name of the variable.
     * @param value The value of the variable.
     */
    void SetVariable(const std::string& name, const std::string& value);

    /**
     * @brief Gets the variables.
     * 
     * @return The variables.
     */
    const std::unordered_map<std::string, std::string>& GetVariables() const;

    /**
     * @brief Remove a variable.
     * 
     * @param name The name of the variable.
     */
    void RemoveVariable(const std::string& name);

private:
    void CreateDefaultConfiguration();

    std::filesystem::path m_Configuration;

    std::filesystem::path m_Client;

    std::filesystem::path m_Database;

    std::filesystem::path m_SqliteToFdb;

    std::filesystem::path m_FdbToSqlite;

    std::filesystem::path m_Lookup;

    std::filesystem::path m_Locale;

    std::filesystem::path m_ModsDirectory;

    std::filesystem::path m_ArtifactsDirectory;

    std::filesystem::path m_AddedResourcesDirectory;

    std::vector<std::string> m_PreCommands;

    std::vector<std::string> m_PostCommands;

    std::vector<std::filesystem::path> m_ClientMirrors;

    std::unordered_map<std::string, std::string> m_Variables;

    bool m_IsPublic = false;
};

} // namespace nejlika