#include "ModPack.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#include <Lookup.hpp>

using namespace nejlika;

namespace {

}

nejlika::ModPack::ModPack()
{
}

nejlika::ModPack::ModPack(nejlika::Context& ctx, const ModPack &other)
{
    this->m_Manifest = other.m_Manifest;

    this->m_Resources = other.m_Resources;

    this->m_Path = other.m_Path;

    m_Mods = {};

    for (const auto& mod : other.m_Mods)
    {
        m_Mods.push_back(AbstractMod::Parse(ctx, mod->Serialize()));
    }
}

nejlika::ModPack::ModPack(const Manifest &manifest, const std::filesystem::path &path)
{
    if (!manifest.GetModFiles().empty())
    {
        throw std::runtime_error("Mod list in manifest is not empty.");
    }

    this->m_Manifest = manifest;

    this->m_Path = path;

    // Create the directory if it does not exist
    if (!std::filesystem::exists(path))
    {
        std::filesystem::create_directory(path);
    }
    // Check that the directory is empty
    else if (std::filesystem::directory_iterator(path) != std::filesystem::directory_iterator())
    {
        std::stringstream ss;

        ss << "Mod pack directory \"" << path << "\" is not empty.";

        throw std::runtime_error(ss.str());
    }

    // Create the manifest file
    std::ofstream manifestFile(path / "manifest.json");

    if (!manifestFile.is_open())
    {
        throw std::runtime_error("Could not create manifest file.");
    }

    manifestFile << m_Manifest.Serialize();

    manifestFile.close();

    // Create the resource directory
    std::filesystem::create_directory(path / m_Manifest.GetResourceDirectory());
}

nejlika::ModPack::ModPack(nejlika::Context& ctx, const std::filesystem::path &path)
{
    this->m_Path = path;

    std::filesystem::path manifestPath = path / "manifest.json";
    if (!std::filesystem::exists(manifestPath))
    {
        throw std::runtime_error("Mod pack directory does not contain a manifest file.");
    }

    std::ifstream manifestFile(manifestPath);
    if (!manifestFile.is_open())
    {
        throw std::runtime_error("Could not open manifest file.");
    }

    boost::json::value manifestJson = boost::json::parse(manifestFile);
    if (!manifestJson.is_object())
    {
        throw std::runtime_error("Manifest file is not a valid JSON object.");
    }

    m_Manifest.Deserialize(manifestJson.as_object());
    
    // Look at the manifest for all the mods
    for (const auto& modFile : m_Manifest.GetModFiles())
    {
        // Get the mod file path
        std::filesystem::path modPath = path / modFile;

        std::cout << "Loading mod file: " << modPath << std::endl;

        // Check if the file exists
        if (!std::filesystem::exists(modPath))
        {
            std::stringstream ss;

            ss << "Mod file \"" << modFile << "\" does not exist.";

            throw std::runtime_error(ss.str());
        }

        // Open the mod file
        std::ifstream modStream(modPath);
        if (!modStream.is_open())
        {
            throw std::runtime_error("Could not open mod file.");
        }

        // Parse the mod file
        boost::json::value modJson;
        
        try {
            modJson = boost::json::parse(modStream);
        } catch (const std::exception& e) {
            std::stringstream ss;

            ss << "Could not parse mod file \"" << modFile << "\": " << e.what();

            throw std::runtime_error(ss.str());
        }

        if (modJson.is_array())
        {
            for (const auto& mod : modJson.as_array()) {
                const auto abstractMod = AbstractMod::Parse(ctx, mod.as_object());

                m_Mods.push_back(abstractMod);
            }
        }
        else
        {
            const auto abstractMod = AbstractMod::Parse(ctx, modJson.as_object());

            m_Mods.push_back(abstractMod);
        }
    }

    std::cout << "Loaded " << m_Mods.size() << " mods." << std::endl;

    // Load mod resources
    const auto directory = m_Path / m_Manifest.GetResourceDirectory();

    m_Resources = ModResources(directory);

    std::cout << "Loaded mod resources." << std::endl;
}

Manifest& nejlika::ModPack::GetManifest()
{
    return m_Manifest;
}

const std::vector<std::shared_ptr<AbstractMod>>& nejlika::ModPack::GetMods() const
{
    return m_Mods;
}

const std::filesystem::path& nejlika::ModPack::GetPath() const
{
    return m_Path;
}

ModResources& nejlika::ModPack::GetResources()
{
    return m_Resources;
}

void nejlika::ModPack::AddMod(const std::shared_ptr<AbstractMod>& mod)
{
    m_Mutex.lock();

    // Check if any other mod has the same name
    for (const auto& other : m_Mods)
    {
        if (other->CanIdentifyWith(mod->GetName()))
        {
            std::stringstream ss;

            ss << "Mod with name \"" << mod->GetName() << "\" already exists.";
            
            m_Mutex.unlock();

            throw std::runtime_error(ss.str());
        }

        for (const auto& alias : mod->GetAliases())
        {
            if (other->CanIdentifyWith(alias))
            {
                std::stringstream ss;

                ss << "Mod with alias \"" << alias << "\" already exists.";

                m_Mutex.unlock();
                
                throw std::runtime_error(ss.str());
            }
        }
    }

    m_Mods.push_back(mod);

    m_Mutex.unlock();
}

void nejlika::ModPack::RemoveMod(const std::shared_ptr<AbstractMod>& mod)
{
    m_Mutex.lock();

    std::vector<std::shared_ptr<AbstractMod>> children;

    try {
        m_Mods.erase(std::remove(m_Mods.begin(), m_Mods.end(), mod), m_Mods.end());
    }
    catch (const std::exception& e)
    {
        m_Mutex.unlock();

        throw e;
    }

    m_Mutex.unlock();

    for (const auto& child : children)
    {
        RemoveMod(child);
    }
}

std::shared_ptr<AbstractMod> nejlika::ModPack::FindMod(const std::string &name, const std::string &type)
{
    m_Mutex.lock();

    for (const auto& mod : m_Mods)
    {
        if (mod->GetName() == name && (type.empty() || mod->GetType() == type))
        {
            m_Mutex.unlock();

            return mod;
        }
    }

    m_Mutex.unlock();

    return nullptr;
}

std::shared_ptr<AbstractMod> nejlika::ModPack::FindMod(const size_t& id)
{
    m_Mutex.lock();

    for (const auto& mod : m_Mods)
    {
        if (mod->GetUniqueRuntimeId() == id)
        {
            m_Mutex.unlock();

            return mod;
        }
    }

    m_Mutex.unlock();

    return nullptr;
}

bool nejlika::ModPack::HasNameConflicts(const std::string& name, const size_t& id)
{
    m_Mutex.lock();

    for (const auto& mod : m_Mods)
    {
        const auto uid = mod->GetUniqueRuntimeId();

        if (uid != 0 && uid == id)
        {
            continue;
        }
        
        if (mod->CanIdentifyWith(name))
        {
            m_Mutex.unlock();

            return true;
        }
    }

    m_Mutex.unlock();

    return false;
}

bool nejlika::ModPack::HasNameConflicts(const std::string& name)
{
    m_Mutex.lock();

    for (const auto& mod : m_Mods)
    {
        if (mod->CanIdentifyWith(name))
        {
            m_Mutex.unlock();

            return true;
        }
    }

    m_Mutex.unlock();

    return false;
}

bool nejlika::ModPack::IncludesMod(const std::shared_ptr<AbstractMod> &mod) const
{
    // Check both the mods and the children
    if (std::find(m_Mods.begin(), m_Mods.end(), mod) != m_Mods.end())
    {
        return true;
    }

    return false;
}

void nejlika::ModPack::Save(const std::filesystem::path &path)
{
    // Create the resource directory if it does not exist
    std::filesystem::create_directory(path / m_Manifest.GetResourceDirectory());

    // Create a .backup directory if it does not exist
    std::filesystem::create_directory(path / ".backup");

    // Create a directory with the current time in YYYY-MM-DD-HH-MM-SS format
    std::time_t time = std::time(nullptr);
    std::tm tm = *std::localtime(&time);

    std::stringstream ss;

    ss << std::put_time(&tm, "%Y-%m-%d-%H-%M-%S");
    
    std::filesystem::path backupPath = path / ".backup" / ss.str();

    std::filesystem::create_directory(backupPath);

    // Move all old mod files
    for (const auto& entry : m_Manifest.GetModFiles())
    {
        std::filesystem::rename(path / entry, backupPath / entry);
    }

    std::vector<std::string> modFiles;

    // Save the mods
    for (const auto& mod : m_Mods)
    {
        std::string fileName = mod->GetName() + ".json";

        std::ofstream modFile(path / fileName);

        if (!modFile.is_open())
        {
            throw std::runtime_error("Could not create mod file.");
        }

        modFile << mod->Serialize();

        modFile.close();

        modFiles.push_back(fileName);
    }
    
    // Set the new mod files
    m_Manifest.SetModFiles(modFiles);
    
    // Create the manifest file
    std::ofstream manifestFile(path / "manifest.json");

    if (!manifestFile.is_open())
    {
        throw std::runtime_error("Could not create manifest file.");
    }

    manifestFile << m_Manifest.Serialize();

    manifestFile.close();
}

void nejlika::ModPack::Save()
{
    Save(m_Path);
}

void nejlika::ModPack::Rename(const std::string &name, bool refactor)
{
    const auto newPath = m_Path.parent_path() / name;

    // Rename the directory
    std::filesystem::rename(m_Path, newPath);

    // Update the path
    m_Path = newPath;

    // Update the manifest
    m_Manifest.SetName(name);

    // Refactor the mod names
    if (refactor)
    {
        for (auto& mod : m_Mods)
        {
            const auto currentName = mod->GetName();

            if (Lookup::IsCoreSymbol(currentName))
            {
                continue;
            }

            // Split by the first ':'
            const auto pos = currentName.find(':');

            if (pos == std::string::npos)
            {
                continue;
            }

            const auto prefix = currentName.substr(0, pos);
            
            std::stringstream ss;

            // name:mod -> newName:mod
            ss << name << currentName.substr(pos);

            mod->Rename(ss.str());
        }
    }

    m_Resources.SetPath(newPath / m_Manifest.GetResourceDirectory());

    // Save the mod pack
    Save();
}

const std::string &nejlika::ModPack::GetName() const
{
    return m_Manifest.GetName();
}

std::mutex& nejlika::ModPack::GetMutex()
{
    return m_Mutex;
}

nejlika::ModPack::~ModPack()
{
    // Delete the mods
    for (const auto& mod : m_Mods)
    {
        RemoveMod(mod);
    }
}
