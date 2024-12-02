#pragma once

#include <filesystem>
#include <unordered_set>
#include <vector>

#include "hashing.hpp"
#include "AbstractSerializable.hpp"

namespace nejlika {

class Context;

/**
 * @brief Represents an artifacts. Files which have been moved from their original location.
 * 
 * Provides a way to create symlinks from mod resources to the game's resources. If a file is
 * overwritten by a mod, the original file is moved to the artifacts directory.
 */
class ArtifactsInterface
{
public:
    /**
     * @brief Gets the path to the artifacts directory.
     * 
     * @return The path to the artifacts directory.
     */
    virtual const std::filesystem::path& GetPath() const = 0;

    /**
     * @brief Get the list of artifacts. Fetches from the artifacts directory.
     * 
     * @return The list of artifacts. Paths are relative to the artifacts directory.
     */
    virtual std::vector<std::filesystem::path> GetArtifacts() const = 0;

    /**
     * @brief Adds an artifact.
     * 
     * @param path The path to the artifact. Relative to the client's directory.
     */
    virtual void AddArtifact(nejlika::Context& ctx, const std::filesystem::path& path) = 0;

    /**
     * @brief Save the artifacts JSON file.
     */
    virtual void Save() const = 0;

    /**
     * @brief Symlink a file from a mod to the game's resources.
     * 
     * If the file already exists in the game's resources, it is moved to the artifacts directory.
     * 
     * @param modPath The path to the mod's resource.
     * @param gamePath The path to the game's resource.
     * @throw If the mod's resource does not exist.
     */
    virtual void Symlink(nejlika::Context& ctx, const std::filesystem::path& modPath, const std::filesystem::path& gamePath) = 0;

    /**
     * @brief Register a generated file.
     * 
     * @param path The path to the generated file, relative to the client's directory.
     */
    virtual void RegisterGeneratedFile(nejlika::Context& ctx, const std::filesystem::path& path) = 0;

    /**
     * @brief Check if files can be generated through this interface.
     * 
     * @return True if files can be generated, false otherwise.
     */
    virtual bool CanGenerateFiles() const = 0;

    /**
     * @brief Generate a filename for a added resource file.
     * 
     * @param filename The filename to generate.
     * @return The generated filename, relative to the client's directory.
     */
    virtual std::filesystem::path GenerateFilename(nejlika::Context& ctx, const std::string& filename) const = 0;

    /**
     * @brief Generate a random filename for a added resource file with a given extension.
     * 
     * @param extension The extension of the file.
     * @return The generated filename, relative to the client's directory.
     */
    virtual std::filesystem::path GenerateRandomFilename(nejlika::Context& ctx, const std::string& extension) const = 0;

    /**
     * @brief Generate a random directory name.
     * 
     * @return The generated directory name, relative to the client's directory.
     */
    virtual std::filesystem::path GenerateRandomDirectory(nejlika::Context& ctx) const = 0;

    /**
     * @brief Get a path prefixed with the added resources directory.
     * 
     * @param path The path to prefix.
     * @return The prefixed path.
     */
    virtual std::filesystem::path GetAddedResourcePath(nejlika::Context& ctx, const std::filesystem::path& path) const = 0;

    /**
     * @brief Restore the artifacts.
     * 
     * This will move back all artifacts to their original location if their link has been modified or deleted and delete any hanging artifacts.
     * 
     * @return Any artifacts which have been restored, not including hanging artifacts.
     * @throw If the artifacts directory is corrupted.
     */
    virtual std::unordered_set<std::filesystem::path, nejlika::filepath_hash> Restore(nejlika::Context& ctx) = 0;

    /**
     * @brief Resolve a path.
     * 
     * @param path The path to resolve.
     * @return The resolved path.
     */
    virtual std::filesystem::path ResolveSymlink(const std::filesystem::path& path) const = 0;
};

} // namespace nejlika