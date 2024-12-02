#include "Manifest.hpp"

#include <fstream>

using namespace nejlika;

nejlika::Manifest::Manifest()
{
}

nejlika::Manifest::Manifest(const std::string &name, const std::string &description, const std::string &version, const std::string &author)
{
    m_Name = name;
    m_Description = description;
    m_Version = version;
    m_Author = author;
    m_ResourceDirectory = "resources";
}

nejlika::Manifest::Manifest(const std::filesystem::path &path)
{
    // Check if the file exists.
    if (!std::filesystem::exists(path))
    {
        throw std::runtime_error("Manifest file does not exist.");
    }

    // Read the json file
    std::ifstream file(path);

    std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Parse the json
    const auto root = boost::json::parse(json).as_object();

    Deserialize(root);
}

const std::string &nejlika::Manifest::GetName() const
{
    return m_Name;
}

void nejlika::Manifest::SetName(const std::string &name)
{
    m_Name = name;
}

const std::string &nejlika::Manifest::GetDescription() const
{
    return m_Description;
}

void nejlika::Manifest::SetDescription(const std::string &description)
{
    m_Description = description;
}

const std::string &nejlika::Manifest::GetVersion() const
{
    return m_Version;
}

void nejlika::Manifest::SetVersion(const std::string &version)
{
    m_Version = version;
}

const std::string &nejlika::Manifest::GetAuthor() const
{
    return m_Author;
}

void nejlika::Manifest::SetAuthor(const std::string &author)
{
    m_Author = author;
}

const std::vector<std::string> &nejlika::Manifest::GetModFiles() const
{
    return m_ModFiles;
}

void nejlika::Manifest::SetModFiles(const std::vector<std::string> &modFiles)
{
    m_ModFiles = modFiles;
}

const std::string &nejlika::Manifest::GetResourceDirectory() const
{
    return m_ResourceDirectory;
}

void nejlika::Manifest::SetResourceDirectory(const std::string &resourceDirectory)
{
    m_ResourceDirectory = resourceDirectory;
}

boost::json::object nejlika::Manifest::Serialize() const
{
    boost::json::object json;

    json["name"] = m_Name;

    if (!m_ModFiles.empty())
    {
        boost::json::array modFiles;

        for (const auto &modFile : m_ModFiles)
        {
            modFiles.emplace_back(modFile);
        }

        json["files"] = modFiles;
    }

    if (!m_ResourceDirectory.empty())
    {
        json["resources"] = m_ResourceDirectory;
    }

    if (!m_Description.empty())
    {
        json["description"] = m_Description;
    }

    if (!m_Version.empty())
    {
        json["version"] = m_Version;
    }

    if (!m_Author.empty())
    {
        json["author"] = m_Author;
    }

    return json;
}

void nejlika::Manifest::Deserialize(const boost::json::object &json)
{
    m_Name = json.at("name").as_string().c_str();

    if (const auto it = json.find("files"); it != json.end())
    {
        m_ModFiles.clear();

        for (const auto &modFile : it->value().as_array())
        {
            m_ModFiles.emplace_back(modFile.as_string().c_str());
        }
    }

    if (const auto it = json.find("resources"); it != json.end())
    {
        m_ResourceDirectory = it->value().as_string().c_str();
    }

    if (const auto it = json.find("description"); it != json.end())
    {
        m_Description = it->value().as_string().c_str();
    }

    if (const auto it = json.find("version"); it != json.end())
    {
        m_Version = it->value().as_string().c_str();
    }

    if (const auto it = json.find("author"); it != json.end())
    {
        m_Author = it->value().as_string().c_str();
    }
}