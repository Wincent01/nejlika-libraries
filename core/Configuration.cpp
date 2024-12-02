#include "Configuration.hpp"

#include <fstream>

#include <boost/json.hpp>

using namespace nejlika;

nejlika::Configuration::Configuration()
{
}

Configuration::Configuration(const std::filesystem::path &configuration)
{
    m_Configuration = configuration;

    // Check if the file exists.
    if (!std::filesystem::exists(configuration))
    {
        CreateDefaultConfiguration();

        throw std::runtime_error("Configuration file does not exist. A default configuration file has been created.");
    }

    // Read the json file
    std::ifstream file(configuration);

    std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Parse the json
    auto root = boost::json::parse(json).as_object();

    m_Client = std::filesystem::path(root.at("client").as_string().c_str());
    m_Database = std::filesystem::path(root.at("database").as_string().c_str());
    m_SqliteToFdb = std::filesystem::path(root.at("sqlite_to_fdb").as_string().c_str());
    m_FdbToSqlite = std::filesystem::path(root.at("fdb_to_sqlite").as_string().c_str());
    m_Lookup = std::filesystem::path(root.at("lookup").as_string().c_str());
    m_Locale = std::filesystem::path(root.at("locale").as_string().c_str());
    m_ModsDirectory = std::filesystem::path(root.at("mods").as_string().c_str());
    m_ArtifactsDirectory = std::filesystem::path(root.at("artifacts").as_string().c_str());
    m_AddedResourcesDirectory = std::filesystem::path(root.at("added_resources").as_string().c_str());

    if (root.contains("pre-commands"))
    {
        for (const auto& command : root.at("pre-commands").as_array())
        {
            m_PreCommands.push_back(command.as_string().c_str());
        }
    }
    
    if (root.contains("post-commands"))
    {
        for (const auto& command : root.at("post-commands").as_array())
        {
            m_PostCommands.push_back(command.as_string().c_str());
        }
    }

    if (root.contains("client-mirrors"))
    {
        for (const auto& mirror : root.at("client-mirrors").as_array())
        {
            m_ClientMirrors.push_back(std::filesystem::path(mirror.as_string().c_str()));
        }
    }

    if (root.contains("variables"))
    {
        for (const auto& [name, value] : root.at("variables").as_object())
        {
            m_Variables[name] = value.as_string().c_str();
        }
    }

    if (root.contains("public"))
    {
        m_IsPublic = root.at("public").as_bool();
    }

    // If the mods directory does not exist, create it.
    if (!std::filesystem::exists(m_ModsDirectory))
    {
        std::filesystem::create_directory(m_ModsDirectory);
    }
}

void nejlika::Configuration::Save() const
{
    std::ofstream file(m_Configuration);

    boost::json::object root;

    root["client"] = m_Client.string();
    root["database"] = m_Database.string();
    root["sqlite_to_fdb"] = m_SqliteToFdb.string();
    root["fdb_to_sqlite"] = m_FdbToSqlite.string();
    root["lookup"] = m_Lookup.string();
    root["locale"] = m_Locale.string();
    root["mods"] = m_ModsDirectory.string();
    root["artifacts"] = m_ArtifactsDirectory.string();
    root["added_resources"] = m_AddedResourcesDirectory.string();
    root["public"] = m_IsPublic;

    boost::json::array preCommands;

    for (const auto& command : m_PreCommands)
    {
        preCommands.push_back(boost::json::string(command));
    }

    root["pre-commands"] = preCommands;

    boost::json::array postCommands;

    for (const auto& command : m_PostCommands)
    {
        postCommands.push_back(boost::json::string(command));
    }

    root["post-commands"] = postCommands;

    boost::json::array clientMirrors;

    for (const auto& mirror : m_ClientMirrors)
    {
        clientMirrors.push_back(boost::json::string(mirror.string()));
    }

    root["client-mirrors"] = clientMirrors;

    boost::json::object variables;

    for (const auto& [name, value] : m_Variables)
    {
        variables[name] = value;
    }

    root["variables"] = variables;

    file << boost::json::serialize(root);

    file.close();
}

const std::filesystem::path &nejlika::Configuration::GetConfiguration() const
{
    return m_Configuration;
}

const std::filesystem::path &Configuration::GetClient() const
{
    return m_Client;
}

const std::filesystem::path &nejlika::Configuration::GetDatabase() const
{
    return m_Database;
}

const std::filesystem::path &Configuration::GetSqliteToFdb() const
{
    return m_SqliteToFdb;
}

const std::filesystem::path &Configuration::GetFdbToSqlite() const
{
    return m_FdbToSqlite;
}

const std::filesystem::path &nejlika::Configuration::GetLookup() const
{
    return m_Lookup;
}

const std::filesystem::path &nejlika::Configuration::GetLocale() const
{
    return m_Locale;
}

const std::filesystem::path &nejlika::Configuration::GetModsDirectory() const
{
    return m_ModsDirectory;
}

const std::filesystem::path &nejlika::Configuration::GetArtifactsDirectory() const
{
    return m_ArtifactsDirectory;
}

const std::filesystem::path &nejlika::Configuration::GetAddedResourcesDirectory() const
{
    return m_AddedResourcesDirectory;
}

const std::vector<std::string> &nejlika::Configuration::GetPreCommands() const
{
    return m_PreCommands;
}

const std::vector<std::string> &nejlika::Configuration::GetPostCommands() const
{
    return m_PostCommands;
}

const std::vector<std::filesystem::path> &nejlika::Configuration::GetClientMirrors() const
{
    return m_ClientMirrors;
}

bool nejlika::Configuration::IsPublic() const
{
    return m_IsPublic;
}

void nejlika::Configuration::SetConfiguration(const std::filesystem::path& configuration)
{
    m_Configuration = configuration;
}

void nejlika::Configuration::SetClient(const std::filesystem::path& client)
{
    m_Client = client;
}

void nejlika::Configuration::SetDatabase(const std::filesystem::path& database)
{
    m_Database = database;
}

void nejlika::Configuration::SetSqliteToFdb(const std::filesystem::path& sqliteToFdb)
{
    m_SqliteToFdb = sqliteToFdb;
}

void nejlika::Configuration::SetFdbToSqlite(const std::filesystem::path& fdbToSqlite)
{
    m_FdbToSqlite = fdbToSqlite;
}

void nejlika::Configuration::SetLookup(const std::filesystem::path& lookup)
{
    m_Lookup = lookup;
}

void nejlika::Configuration::SetLocale(const std::filesystem::path& locale)
{
    m_Locale = locale;
}

void nejlika::Configuration::SetModsDirectory(const std::filesystem::path& modsDirectory)
{
    m_ModsDirectory = modsDirectory;
}

void nejlika::Configuration::SetArtifactsDirectory(const std::filesystem::path& artifactsDirectory)
{
    m_ArtifactsDirectory = artifactsDirectory;
}

void nejlika::Configuration::SetAddedResourcesDirectory(const std::filesystem::path& addedResourcesDirectory)
{
    m_AddedResourcesDirectory = addedResourcesDirectory;
}

void nejlika::Configuration::SetPreCommands(const std::vector<std::string>& preCommands)
{
    m_PreCommands = preCommands;
}

void nejlika::Configuration::SetPostCommands(const std::vector<std::string>& postCommands)
{
    m_PostCommands = postCommands;
}

void nejlika::Configuration::SetClientMirrors(const std::vector<std::filesystem::path>& clientMirrors)
{
    m_ClientMirrors = clientMirrors;
}

void nejlika::Configuration::SetPublic(bool isPublic)
{
    m_IsPublic = isPublic;
}

const std::string& nejlika::Configuration::GetVariable(const std::string& name) const
{
    const auto& variable = m_Variables.find(name);

    if (variable == m_Variables.end())
    {
        static const std::string empty;

        return empty;
    }

    return variable->second;
}

void nejlika::Configuration::SetVariable(const std::string& name, const std::string& value)
{
    m_Variables[name] = value;
}

const std::unordered_map<std::string, std::string>& nejlika::Configuration::GetVariables() const
{
    return m_Variables;
}

void nejlika::Configuration::RemoveVariable(const std::string& name)
{
    m_Variables.erase(name);
}

void nejlika::Configuration::CreateDefaultConfiguration()
{
    std::ofstream file(m_Configuration);

    boost::json::object root;

    root["client"] = "path/to/client";
    root["database"] = "path/to/cdclient.sqlite";
    root["sqlite_to_fdb"] = "path/to/sqlite_to_fdb";
    root["fdb_to_sqlite"] = "path/to/fdb_to_sqlite";
    root["lookup"] = "lookup.json";
    root["locale"] = "locale.xml";
    root["mods"] = "mods";
    root["artifacts"] = "artifacts";
    root["added_resources"] = "res/maps/__nejlika__";

    file << boost::json::serialize(root);

    file.close();
}
