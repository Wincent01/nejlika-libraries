#pragma once

#include <filesystem>
#include <unordered_set>
#include <vector>

#include "hashing.hpp"
#include "AbstractSerializable.hpp"
#include "ArtifactsInterface.hpp"

namespace nejlika {

class Context;

/**
 * @brief Represents an artifacts. Files which have been moved from their original location.
 * 
 * Provides a way to create symlinks from mod resources to the game's resources. If a file is
 * overwritten by a mod, the original file is moved to the artifacts directory.
 */
class Artifacts : public ArtifactsInterface, public AbstractSerializable
{
public:
    /**
     * @brief Constructs a new Artifacts object.
     * 
     * @param path The path to the artifacts directory.
     * @throw If the artifacts directory could not be parsed.
     */
    Artifacts(const std::filesystem::path& path);

    /**
     * @brief Gets the path to the artifacts directory.
     * 
     * @return The path to the artifacts directory.
     */
    const std::filesystem::path& GetPath() const override;

    /**
     * @brief Get the list of artifacts. Fetches from the artifacts directory.
     * 
     * @return The list of artifacts. Paths are relative to the artifacts directory.
     */
    std::vector<std::filesystem::path> GetArtifacts() const override;

    /**
     * @brief Adds an artifact.
     * 
     * @param path The path to the artifact. Relative to the client's directory.
     */
    void AddArtifact(nejlika::Context& ctx, const std::filesystem::path& path) override;

    /**
     * @brief Symlink a file from a mod to the game's resources.
     * 
     * If the file already exists in the game's resources, it is moved to the artifacts directory.
     * 
     * @param modPath The path to the mod's resource.
     * @param gamePath The path to the game's resource.
     * @throw If the mod's resource does not exist.
     */
    void Symlink(nejlika::Context& ctx, const std::filesystem::path& modPath, const std::filesystem::path& gamePath) override;
    
    /**
     * @brief Register a generated file.
     * 
     * @param path The path to the generated file, relative to the client's directory.
     */
    void RegisterGeneratedFile(nejlika::Context& ctx, const std::filesystem::path& path) override;

    bool CanGenerateFiles() const override;

    /**
     * @brief Save the artifacts JSON file.
     */
    void Save() const override;

    std::filesystem::path GenerateFilename(nejlika::Context& ctx, const std::string& filename) const override;

    /**
     * @brief Generate a random filename for a added resource file with a given extension.
     * 
     * @param extension The extension of the file.
     * @return The generated filename, relative to the client's directory.
     */
    std::filesystem::path GenerateRandomFilename(nejlika::Context& ctx, const std::string& extension) const override;

    /**
     * @brief Generate a random directory name.
     * 
     * @return The generated directory name, relative to the client's directory.
     */
    std::filesystem::path GenerateRandomDirectory(nejlika::Context& ctx) const override;

    /**
     * @brief Get a path prefixed with the added resources directory.
     * 
     * @param path The path to prefix.
     * @return The prefixed path.
     */
    std::filesystem::path GetAddedResourcePath(nejlika::Context& ctx, const std::filesystem::path& path) const override;

    /**
     * @brief Restore the artifacts.
     * 
     * This will move back all artifacts to their original location if their link has been modified or deleted and delete any hanging artifacts.
     * 
     * @return Any artifacts which have been restored, not including hanging artifacts.
     * @throw If the artifacts directory is corrupted.
     */
    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> Restore(nejlika::Context& ctx) override;

    std::filesystem::path ResolveSymlink(const std::filesystem::path& path) const override;

    /**
     * @brief Serializes the object into a JSON object.
     * 
     * @return The serialized JSON object.
     */
    boost::json::object Serialize() const override;

    /**
     * @brief Deserializes the object from a JSON object.
     * 
     * @param object The JSON object to deserialize from.
     */
    void Deserialize(const boost::json::object& object) override;

private:
    std::filesystem::path m_Path;

    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> m_HangingArtifacts;

    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> m_OldHangingArtifacts;

    std::unordered_map<std::string, std::string> m_Mirrors;
};

}
