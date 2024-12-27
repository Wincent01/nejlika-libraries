#include "ModResources.hpp"

#include <iostream>

#include "nejlika.hpp"
#include "Configuration.hpp"
#include "Lookup.hpp"
#include "Mods.hpp"

using namespace nejlika;

nejlika::ModResources::ModResources()
{
}

nejlika::ModResources::ModResources(const std::filesystem::path &path)
{
    SetPath(path);
}

const std::filesystem::path &nejlika::ModResources::GetPath() const
{
    return m_Path;
}

void nejlika::ModResources::SetPath(const std::filesystem::path &path)
{
    m_Path = path;
    m_DirectoryName = path.filename();
    m_Resources.clear();

    // Iterate over all files in the resource directory.
    for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
    {
        // Skip directories.
        if (entry.is_directory())
        {
            continue;
        }

        // Ignore files which either start with '.' or are in a directory or subdirectory which starts with '.'.
        if (entry.path().filename().string().front() == '.' || entry.path().parent_path().string().find("/.") != std::string::npos)
        {
            continue;
        }

        const auto& entryPath = entry.path();
        const auto& parentPath = path.parent_path();

        // Get the relative path to the resource file, without resolving symlinks.
        std::filesystem::path relativePath = entryPath.lexically_proximate(parentPath);

        // Add the resource file to the map.
        m_Resources.emplace(relativePath);
    }
}

void nejlika::ModResources::Reload()
{
    SetPath(m_Path);
}

std::filesystem::path nejlika::ModResources::GetResourcePath(const std::filesystem::path &path) const
{
    auto it = m_Resources.find(path);

    if (it == m_Resources.end())
    {
        it = m_Resources.find(m_DirectoryName / path);
    }

    if (it == m_Resources.end())
    {
        std::stringstream ss;

        ss << "Resource file \"" << path << "\" not found.";

        throw std::runtime_error(ss.str());
    }

    return m_Path.parent_path() / *it;
}

std::filesystem::path nejlika::ModResources::AddResource(const std::filesystem::path &path)
{
    std::filesystem::path p = GetResourcePathWithDirectoryName(path);

    if (HasResource(p))
    {
        std::stringstream ss;

        ss << "Resource file \"" << p << "\" already exists.";

        throw std::runtime_error(ss.str());
    }

    m_Resources.emplace(p);

    p = GetResourcePathWithoutDirectoryName(p);

    // Create the intermediate directories if they don't exist.
    std::filesystem::create_directories(m_Path / p.parent_path());

    return m_Path / p;
}

void nejlika::ModResources::RemoveResource(const std::filesystem::path &path, bool deleteFile)
{
    auto it = m_Resources.find(path);

    if (it == m_Resources.end())
    {
        it = m_Resources.find(m_DirectoryName / path);
    }

    if (it == m_Resources.end())
    {
        std::stringstream ss;

        ss << "Resource file \"" << path << "\" not found.";

        throw std::runtime_error(ss.str());
    }

    if (deleteFile)
    {
        std::filesystem::remove(m_Path / GetResourcePathWithoutDirectoryName(*it));
    }

    m_Resources.erase(it);
}

void nejlika::ModResources::CreateSubdirectory(const std::filesystem::path &path)
{
    std::filesystem::create_directories(m_Path / GetResourcePathWithoutDirectoryName(path));
}

bool nejlika::ModResources::HasResourcesInSubdirectory(const std::filesystem::path &subdirectory) const
{
    const auto directory = subdirectory.empty() ? m_DirectoryName : GetResourcePathWithDirectoryName(subdirectory);

    for (const auto &path : m_Resources)
    {
        const auto& parentPath = path.parent_path();

        if (parentPath == directory)
        {
            return true;
        }
    }

    return false;
}

void nejlika::ModResources::DeleteSubdirectory(const std::filesystem::path &path)
{
    if (HasResourcesInSubdirectory(path))
    {
        std::stringstream ss;

        ss << "Subdirectory \"" << path << "\" is not empty.";

        throw std::runtime_error(ss.str());
    }
    
    std::filesystem::remove_all(m_Path / GetResourcePathWithoutDirectoryName(path));
}

bool nejlika::ModResources::HasResource(const std::filesystem::path &path) const
{
    return m_Resources.find(path) != m_Resources.end() || m_Resources.find(m_DirectoryName / path) != m_Resources.end();
}

const std::unordered_set<std::filesystem::path, nejlika::filepath_hash>& nejlika::ModResources::GetResources() const
{
    return m_Resources;
}

std::unordered_set<std::filesystem::path, nejlika::filepath_hash> nejlika::ModResources::GetResourcesInSubdirectory(
    const std::filesystem::path &subdirectory,
    bool includeSubdirectories,
    bool recursive
) const
{
    const auto directory = subdirectory.empty() ? m_DirectoryName : GetResourcePathWithDirectoryName(subdirectory);

    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> result;

    for (const auto &path : m_Resources)
    {
        const auto& parentPath = path.parent_path();

        if (parentPath == directory)
        {
            result.emplace(path);
        }
    }

    if (includeSubdirectories)
    {
        const auto p = m_Path / GetResourcePathWithoutDirectoryName(subdirectory);

        std::vector<std::filesystem::directory_entry> iterator;

        if (recursive)
        {
            for (const auto &entry : std::filesystem::recursive_directory_iterator(p))
            {
                iterator.emplace_back(entry.path());
            }
        }
        else
        {
            for (const auto &entry : std::filesystem::directory_iterator(p))
            {
                iterator.emplace_back(entry.path());
            }
        }

        for (const auto &entry : iterator)
        {
            if (!entry.is_directory())
            {
                continue;
            }
            
            // Skip directories which either start with '.' or are in a directory or subdirectory which starts with '.'.
            if (entry.path().filename().string().front() == '.' || entry.path().parent_path().string().find("/.") != std::string::npos)
            {
                continue;
            }

            result.emplace(subdirectory / entry.path().filename());
        }
    }

    return result;
}

std::unordered_set<std::filesystem::path, nejlika::filepath_hash> nejlika::ModResources::GetResourcesInSubdirectoryCore(
    nejlika::Context& ctx,
    const std::filesystem::path &subdirectory,
    bool includeSubdirectories,
    bool recursive
)
{
    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> result;

    const auto p = ctx.configuration->GetClient() / "res" / subdirectory;

    std::vector<std::filesystem::directory_entry> iterator;

    if (recursive)
    {
        for (const auto &entry : std::filesystem::recursive_directory_iterator(p))
        {
            iterator.emplace_back(entry.path());
        }
    }
    else
    {
        for (const auto &entry : std::filesystem::directory_iterator(p))
        {
            iterator.emplace_back(entry.path());
        }
    }

    for (const auto &entry : iterator)
    {
        if (entry.is_directory())
        {
            continue;
        }

        result.emplace(subdirectory / entry.path().filename());
    }

    if (includeSubdirectories)
    {
        for (const auto &entry : iterator)
        {
            if (!entry.is_directory())
            {
                continue;
            }

            // Skip directories which either start with '.' or are in a directory or subdirectory which starts with '.'.
            if (entry.path().filename().string().front() == '.' || entry.path().parent_path().string().find("/.") != std::string::npos)
            {
                continue;
            }

            result.emplace(subdirectory / entry.path().filename());
        }
    }

    return result;
}

bool nejlika::ModResources::IsCoreResource(const std::filesystem::path &path, std::filesystem::path &resourcePath)
{
    if (!IsCoreResource(path))
    {
        return false;
    }

    // Make sure there is a colon after the prefix
    if (path.string().size() <= Lookup::core_prefix.size() || path.string()[Lookup::core_prefix.size()] != ':')
    {
        std::stringstream ss;

        ss << "The resource " << path << " is not a core resource, as it does not start with \"" << Lookup::core_prefix << "/\".";

        throw std::runtime_error(ss.str());
    }

    resourcePath = path.string().substr(Lookup::core_prefix.size() + 1);

    return true;
}

bool nejlika::ModResources::IsCoreResource(const std::filesystem::path &path)
{
    return path.string().starts_with(Lookup::core_prefix);
}

std::filesystem::path nejlika::ModResources::GetCoreResourcePath(nejlika::Context &ctx, const std::filesystem::path &path, const std::filesystem::path &subdirectory)
{
    if (!IsCoreResource(path))
    {
        std::stringstream ss;

        ss << "The resource " << path << " is not a core resource.";

        throw std::runtime_error(ss.str());
    }

    // Make sure there is a colon after the prefix
    if (path.string().size() <= Lookup::core_prefix.size() || path.string()[Lookup::core_prefix.size()] != ':')
    {
        std::stringstream ss;

        ss << "The resource " << path << " is not a core resource, as it does not start with \"" << Lookup::core_prefix << "/\".";

        throw std::runtime_error(ss.str());
    }

    auto value = path.string().substr(Lookup::core_prefix.size() + 1);

    // Make it all lowercase
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);

    // Turn all double backslashes into single backslashes
    value.erase(std::unique(value.begin(), value.end(), [](char a, char b) { return a == '\\' && b == '\\'; }), value.end());

    // Turn all backslashes into forward slashes
    std::replace(value.begin(), value.end(), '\\', '/');

    const auto& resource = FindCaseInsensitive(ctx.configuration->GetClient() / subdirectory, value);

    if (resource.empty())
    {
        std::stringstream ss;

        ss << "The resource " << path << " was not found.";

        throw std::runtime_error(ss.str());
    }

    return resource;
}

const std::filesystem::path &nejlika::ModResources::GetDirectoryName() const
{
    return m_DirectoryName;
}

std::filesystem::path nejlika::ModResources::GetResourcePathWithDirectoryName(const std::filesystem::path &path) const
{
    if (path.string().find(m_DirectoryName.string()) != 0)
    {
        return m_DirectoryName / path;
    }

    return path;
}

std::filesystem::path nejlika::ModResources::GetResourcePathWithoutDirectoryName(const std::filesystem::path &path) const
{
    if (path.string().find(m_DirectoryName.string()) == 0)
    {
        return path.string().substr(m_DirectoryName.string().length() + 1);
    }

    return path;
}

const ModResources& nejlika::ModResources::FindResources(nejlika::Context &ctx, const std::filesystem::path &path, const ModResources& defaultModPack, std::filesystem::path& withoutPrefix)
{
    if (path.string().find(':') == std::string::npos)
    {
        withoutPrefix = path;

        return defaultModPack;
    }

    const auto str = path.string();

    const auto modPackName = str.substr(0, str.find(':'));

    for (auto &modPack : ctx.mods->GetModPacks())
    {
        if (modPack->GetName() == modPackName)
        {
            withoutPrefix = str.substr(str.find(':') + 1);

            return modPack->GetResources();
        }
    }
    
    withoutPrefix = path;

    return defaultModPack;
}

const ModResources &nejlika::ModResources::FindResources(nejlika::Context &ctx, const std::filesystem::path &path, std::filesystem::path &withoutPrefix)
{
    if (path.string().find(':') == std::string::npos)
    {
        throw std::runtime_error("No mod pack specified.");
    }

    const auto str = path.string();

    const auto modPackName = str.substr(0, str.find(':'));

    for (auto &modPack : ctx.mods->GetModPacks())
    {
        if (modPack->GetName() == modPackName)
        {
            withoutPrefix = str.substr(str.find(':') + 1);

            return modPack->GetResources();
        }
    }

    throw std::runtime_error("Mod pack \"" + modPackName + "\" not found.");
}

std::filesystem::path nejlika::ModResources::FindResource(nejlika::Context &ctx, const std::filesystem::path &path)
{
    if (IsCoreResource(path))
    {
        return GetCoreResourcePath(ctx, path, "res");
    }

    std::filesystem::path withoutPrefix;
    
    try
    {
        const auto& resources = FindResources(ctx, path, withoutPrefix);

        return resources.GetResourcePath(withoutPrefix);
    }
    catch (const std::exception& e)
    {
        std::stringstream ss;

        ss << "Resource file \"" << path << "\" not found.";

        throw std::runtime_error(ss.str());
    }
}

std::filesystem::path nejlika::ModResources::FindCaseInsensitive(const std::filesystem::path &root, const std::filesystem::path &path)
{
    // Working from the root, take each part of the path, and search for it in the current directory
    // If a directory/file is found (case insensitive), continue to the next part
    // If a directory/file is not found, return an empty path

    std::filesystem::path current = root;

    for (const auto& part : path)
    {
        // If it's a .., go up a directory
        if (part == "..")
        {
            current = current.parent_path();

            continue;
        }

        bool found = false;

        for (const auto& entry : std::filesystem::directory_iterator(current))
        {
            // Case insensitive comparison, make both lowercase
            auto entryLower = entry.path().filename().string();
            auto partLower = part.string();

            std::transform(entryLower.begin(), entryLower.end(), entryLower.begin(), ::tolower);
            std::transform(partLower.begin(), partLower.end(), partLower.begin(), ::tolower);

            if (entryLower == partLower)
            {
                current /= entry.path();

                found = true;

                break;
            }
        }

        if (!found)
        {
            return {};
        }
    }

    return current;
}
