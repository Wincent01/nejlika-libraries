#include "Artifacts.hpp"

#include "nejlika.hpp"
#include "Configuration.hpp"
#include "Mods.hpp"

#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace nejlika;

nejlika::Artifacts::Artifacts(const std::filesystem::path &path)
{
    this->m_Path = path;

    // If the artifacts directory doesn't exist, create it.
    if (!std::filesystem::exists(path))
    {
        std::filesystem::create_directories(path);
    }

    // If the artifacts directory is not a directory, throw an error.
    if (!std::filesystem::is_directory(path))
    {
        throw std::runtime_error("Artifacts path is not a directory.");
    }

    // Load the artifacts JSON file.
    std::ifstream file(path / "artifacts.json");

    // If the artifacts JSON file doesn't exist, create it.
    if (!file.is_open())
    {
        Save();

        return;
    }

    // Read the JSON file.
    std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Parse the JSON.
    Deserialize(boost::json::parse(json).as_object());

    file.close();
}

const std::filesystem::path &nejlika::Artifacts::GetPath() const
{
    return m_Path;
}

std::vector<std::filesystem::path> nejlika::Artifacts::GetArtifacts() const
{
    // Collect all files in the artifacts directory.
    std::vector<std::filesystem::path> artifacts;

    // Recursively iterate through the artifacts directory.
    for (const auto& entry : std::filesystem::recursive_directory_iterator(m_Path))
    {
        // Skip 'artifacts.json'.
        if (entry.path().filename() == "artifacts.json")
        {
            continue;
        }

        // Skip directories.
        if (entry.is_directory())
        {
            continue;
        }

        // Make the path relative to the artifacts directory.
        const auto& relativePath = std::filesystem::relative(entry.path(), m_Path);

        artifacts.push_back(relativePath);
    }

    return artifacts;
}

void nejlika::Artifacts::AddArtifact(nejlika::Context& ctx, const std::filesystem::path &path)
{
    // Path is relative to the client's directory.
    const auto& clientPath = ctx.configuration->GetClient() / path;

    // Check if the file exists.
    if (!std::filesystem::exists(clientPath))
    {
        std::stringstream ss;

        ss << "File \"" << path << "\" does not exist in the client's directory.";

        throw std::runtime_error(ss.str());
    }

    // Get the path to the artifact.
    const auto& artifactPath = this->m_Path / path;

    // Create the directory if it doesn't exist.
    if (!std::filesystem::exists(artifactPath.parent_path()))
    {
        std::filesystem::create_directories(artifactPath.parent_path());
    }

    // If the artifact already exists, skip it.
    if (std::filesystem::exists(artifactPath))
    {
        return;
    }

    // Move the file to the artifacts directory.
    std::filesystem::rename(clientPath, artifactPath);
}

void nejlika::Artifacts::Symlink(nejlika::Context& ctx, const std::filesystem::path &modPath, const std::filesystem::path &gamePath)
{
    const auto& modsPath = ctx.configuration->GetModsDirectory();
    const auto& clientPath = ctx.configuration->GetClient();

    // Get the path to the mod's resource.
    const auto& modResourcePath = modsPath / modPath;

    // Check if the file exists.
    if (!std::filesystem::exists(modResourcePath))
    {
        std::stringstream ss;

        ss << "File \"" << modPath << "\" does not exist in the mods directory.";

        throw std::runtime_error(ss.str());
    }

    // Get the path to the game's resource.
    const auto& gameResourcePath = clientPath / gamePath;

    // Check if the file exists.
    if (std::filesystem::exists(gameResourcePath) && !m_OldHangingArtifacts.contains(gamePath))
    {
        if (!std::filesystem::is_symlink(gameResourcePath)) {
            // Add the game's resource to the list of artifacts.
            AddArtifact(ctx, gamePath);
        }

        // Remove the game's resource.
        std::filesystem::remove(gameResourcePath);
    }
    else
    {
        // Add the game's resource to the list of hanging artifacts.
        m_HangingArtifacts.emplace(gamePath);
    }

    // Create the directory if it doesn't exist.
    if (!std::filesystem::exists(gameResourcePath.parent_path()))
    {
        std::filesystem::create_directories(gameResourcePath.parent_path());
    }

    // Make the symlink relative to it's destination.
    const auto& relativePath = modResourcePath.lexically_relative(gameResourcePath.parent_path());

    // Create the symlink.
    std::filesystem::create_symlink(relativePath, gameResourcePath);

    // Create on mirrors
    const auto& clientMirrors = ctx.configuration->GetClientMirrors();

    for (const auto& mirror : clientMirrors)
    {
        const auto& mirrorPath = mirror / gamePath;

        // Create the directory if it doesn't exist.
        if (!std::filesystem::exists(mirrorPath.parent_path()))
        {
            std::filesystem::create_directories(mirrorPath.parent_path());
        }

        if (std::filesystem::exists(mirrorPath))
        {
            continue;
        }

        // Copy the file
        //std::filesystem::copy(gameResourcePath, mirrorPath);
        m_Mirrors.emplace(gameResourcePath.string(), mirrorPath.string());
    }
}

void nejlika::Artifacts::RegisterGeneratedFile(nejlika::Context &ctx, const std::filesystem::path &path)
{
    // Create on mirrors
    const auto& clientMirrors = ctx.configuration->GetClientMirrors();

    const auto& clientPath = ctx.configuration->GetClient();
    const auto& gameResourcePath = clientPath / path;

    for (const auto& mirror : clientMirrors)
    {
        const auto& mirrorPath = mirror / path;

        // Create the directory if it doesn't exist.
        if (!std::filesystem::exists(mirrorPath.parent_path()))
        {
            std::filesystem::create_directories(mirrorPath.parent_path());
        }

        if (std::filesystem::exists(mirrorPath))
        {
            continue;
        }

        // Copy the file
        //std::filesystem::copy(path, mirrorPath);
        m_Mirrors.emplace(gameResourcePath.string(), mirrorPath.string());
    }
}

bool nejlika::Artifacts::CanGenerateFiles() const
{
    return true;
}

void nejlika::Artifacts::Save() const
{
    // Create the JSON object.
    boost::json::object object = Serialize();

    // Serialize the JSON object.
    std::string json = boost::json::serialize(object);

    // Write the JSON to the file.
    std::ofstream file(m_Path / "artifacts.json");

    file << json;

    file.close();

    // Symlink mirrors
    for (const auto& [source, destination] : m_Mirrors)
    {
        // Create the symlink.
        std::filesystem::create_symlink(source, destination);
    }
}


std::filesystem::path nejlika::Artifacts::GenerateFilename(nejlika::Context &ctx, const std::string &filename) const
{
    const auto& source = ctx.configuration->GetAddedResourcesDirectory();

    return source / filename;
}

std::filesystem::path nejlika::Artifacts::GenerateRandomFilename(nejlika::Context& ctx, const std::string &extension) const
{
    const auto& source = ctx.configuration->GetAddedResourcesDirectory();

    // Generate a random filename.
    boost::uuids::uuid uuid = boost::uuids::random_generator()();

    // Convert the UUID to a string.
    const auto& uuidString = boost::uuids::to_string(uuid);

    std::filesystem::path path;

    // Create the path to the file.
    if (!extension.starts_with("."))
    {
        path = source / (uuidString + "." + extension);
    }
    else
    {
        path = source / (uuidString + extension);
    }

    // Check if the file already exists.
    if (std::filesystem::exists(path))
    {
        // Generate a new filename.
        return GenerateRandomFilename(ctx, extension);
    }

    return path;
}

std::filesystem::path nejlika::Artifacts::GenerateRandomDirectory(nejlika::Context& ctx) const
{
    const auto& source = ctx.configuration->GetAddedResourcesDirectory();

    // Generate a random filename.
    boost::uuids::uuid uuid = boost::uuids::random_generator()();

    // Convert the UUID to a string.
    const auto& uuidString = boost::uuids::to_string(uuid);

    // Create the path to the directory.
    const auto& path = source / uuidString;

    // Check if the directory already exists.
    if (std::filesystem::exists(path))
    {
        // Generate a new directory name.
        return GenerateRandomDirectory(ctx);
    }

    return path;
}

std::filesystem::path nejlika::Artifacts::GetAddedResourcePath(nejlika::Context& ctx, const std::filesystem::path &path) const
{
    const auto& source = ctx.configuration->GetAddedResourcesDirectory();

    return source / path;
}

std::unordered_set<std::filesystem::path, nejlika::filepath_hash> nejlika::Artifacts::Restore(nejlika::Context& ctx)
{
    const auto& clientPath = ctx.configuration->GetClient();

    auto& modPacks = ctx.mods->GetModPacks();

    std::unordered_set<std::string> modifiedResources;

    std::vector<std::string> missingResources;

    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> restoredArtifacts;

    const auto& added = clientPath / ctx.configuration->GetAddedResourcesDirectory();

    // If the resources added by the user directory doesn't exist, create it.
    if (!std::filesystem::exists(added))
    {
        std::filesystem::create_directories(added);
    }

    // Delete everything in the added resources directory.
    for (const auto& entry : std::filesystem::directory_iterator(added))
    {
        if (entry.is_directory())
        {
            std::filesystem::remove_all(entry.path());
        }
        else
        {
            std::filesystem::remove(entry.path());
        }
    }
    
    const auto& artifacts = GetArtifacts();
    
    std::cout << "Found " << artifacts.size() << " moved resources." << std::endl;

    // Move back all artifacts to their original location.
    for (const auto& artifact : artifacts)
    {
        // Get the path to the artifact in the client's directory.
        const auto& clientArtifactPath = clientPath / artifact;

        std::cout << "Restoring " << artifact << std::endl;

        // Move the artifact back to the client's directory.
        std::filesystem::rename(m_Path / artifact, clientArtifactPath);

        // Add the artifact to the list of restored artifacts.
        restoredArtifacts.emplace(artifact);
    }

    // Delete all hanging artifacts.
    for (const auto& artifact : m_HangingArtifacts)
    {
        // Get the path to the artifact in the client's directory.
        const auto& clientArtifactPath = clientPath / artifact;

        // Delete the artifact.
        std::filesystem::remove(clientArtifactPath);
    }

    // Clear the hanging artifacts vector.
    m_HangingArtifacts.clear();

    return restoredArtifacts;
}

std::filesystem::path nejlika::Artifacts::ResolveSymlink(const std::filesystem::path &path) const
{
    return path;

    // Get the absolute path.
    const auto& absolutePath = std::filesystem::absolute(path);

    // Check if the file is a symlink.
    if (!std::filesystem::is_symlink(absolutePath))
    {
        return absolutePath;
    }

    // Get the target of the symlink.
    const auto& target = std::filesystem::read_symlink(absolutePath);

    // Check if the target is an absolute path.
    if (target.is_absolute())
    {
        return target;
    }

    // Get the parent path of the symlink.
    const auto& parentPath = absolutePath.parent_path();

    // Resolve the target.
    return parentPath / target;
}

boost::json::object nejlika::Artifacts::Serialize() const
{
    // Serialize the hanging artifacts.
    boost::json::array hangingArtifactsArray;

    for (const auto& artifact : m_HangingArtifacts)
    {
        hangingArtifactsArray.push_back(boost::json::value(artifact.string()));
    }

    // Create the JSON object.
    boost::json::object object;

    object["hanging"] = hangingArtifactsArray;

    return object;
}

void nejlika::Artifacts::Deserialize(const boost::json::object &object)
{
    // Deserialize the hanging artifacts.
    const auto& hangingArtifactsArray = object.at("hanging").as_array();

    for (const auto& artifact : hangingArtifactsArray)
    {
        m_HangingArtifacts.emplace(artifact.as_string().c_str());
    }
}
