#pragma once

#include <filesystem>
#include <mutex>
#include <unordered_map>

#include "Manifest.hpp"
#include "AbstractMod.hpp"
#include "ModResources.hpp"
#include "nejlika.hpp"

namespace nejlika
{

/**
 * @brief Represents a mod pack.
 * 
 * Contains a manifest of metadata and a list of mods.
 * 
 * A mod pack is a directory containing a manifest file which points to a list of mod files.
 */
class ModPack
{
public:
    /**
     * @brief Constructs a new ModPack object.
     */
    ModPack();

    ModPack(const ModPack& other) = delete;

    /**
     * @brief Constructs a new ModPack object.
     * 
     * @param ctx The context.
     * @param other The other mod pack to copy.
     */
    ModPack(nejlika::Context& ctx, const ModPack& other);

    /**
     * @brief Constructs a new ModPack object from a manifest.
     * 
     * @param manifest The manifest of the mod pack.
     * @param path The path to the mod pack directory.
     * @throw If the directory is not empty.
     * @throw If the manifest mod list is not empty.
     */
    ModPack(const Manifest& manifest, const std::filesystem::path& path);
    
    /**
     * @brief Constructs a new ModPack object.
     * 
     * @param ctx The context.
     * @param path The path to the mod pack directory.
     * @throw If the mod pack directory could not be parsed.
     */
    ModPack(nejlika::Context& ctx, const std::filesystem::path& path);

    /**
     * @brief Gets the manifest of the mod pack.
     * 
     * @return The manifest of the mod pack.
     */
    Manifest& GetManifest();

    /**
     * @brief Gets the list of mods in the mod pack.
     * 
     * @return The list of mods in the mod pack.
     */
    const std::vector<std::shared_ptr<AbstractMod>>& GetMods() const;

    /**
     * @brief Gets the path to the mod pack directory.
     * 
     * @return The path to the mod pack directory.
     */
    const std::filesystem::path& GetPath() const;

    /**
     * @brief Get the mod resources.
     * 
     * @return The mod resources.
     */
    ModResources& GetResources();

    /**
     * @brief Add a mod to the mod pack.
     * 
     * @param mod The mod to add.
     */
    void AddMod(const std::shared_ptr<AbstractMod>& mod);

    /**
     * @brief Remove a mod from the mod pack.
     * 
     * @param mod The mod to remove.
     */
    void RemoveMod(const std::shared_ptr<AbstractMod>& mod);

    /**
     * @brief Update a mod in the mod pack.
     * 
     * @param mod The reference to the original mod.
     * @param updated The updated mod.
     */
    void UpdateMod(const std::shared_ptr<AbstractMod>& mod, const std::shared_ptr<AbstractMod>& updated);

    /**
     * @brief Find a mod by a name and optionally a type.
     * 
     * @param name The name of the mod to find.
     * @param type The type of the mod to find.
     * @return The mod if found, nullptr otherwise.
     */
    std::shared_ptr<AbstractMod> FindMod(const std::string& name, const std::string& type = "");

    /**
     * @brief Find a mod by its unique identifier.
     * 
     * @param id The unique identifier of the mod to find.
     * @return The mod if found, nullptr otherwise.
     */
    std::shared_ptr<AbstractMod> FindMod(const size_t& id);

    /**
     * @brief Check if a name of a mod has conflicts with any other mod in the mod pack.
     * 
     * @param name The name of the mod to check.
     * @param id The unique identifier of the mod to check.
     * @return True if the name has conflicts, false otherwise.
     */
    bool HasNameConflicts(const std::string& name, const size_t& id);
    
    /**
     * @brief Check if a name of a mod has conflicts with any other mod in the mod pack.
     * 
     * @param name The name to check.
     * @return True if the name has conflicts, false otherwise.
     */
    bool HasNameConflicts(const std::string& name);

    /**
     * @brief Checks if this mod pack includes a mod.
     * 
     * @param mod The mod to check for.
     * @return True if the mod pack includes the mod, false otherwise.
     */
    bool IncludesMod(const std::shared_ptr<AbstractMod>& mod) const;

    /**
     * @brief Save to filesystem.
     * 
     * @param path The path to save to.
     * @throw If the mod pack could not be saved.
     * 
     * @note This will remove all current mods in the directory and replace them with the current list of mods.
     * @note This will also update the manifest file.
     */
    void Save(const std::filesystem::path& path);

    /**
     * @brief Save to filesystem.
     * 
     * @throw If the mod pack could not be saved.
     * 
     * @note This will remove all current mods in the directory and replace them with the current list of mods.
     * @note This will also update the manifest file.
     */
    void Save();

    /**
     * @brief Rename the mod pack.
     * 
     * @param name The new name of the mod pack.
     * @param refactor Whether to refactor the mod names to match the new mod pack name.
     * 
     * @note This will update the manifest file.
     * @note This will remove rename the mod pack directory.
     * @note If refactoring, the renaming of mods will not catch every reference to the mod.
     * @warning This will cause references to the mod pack to be invalid.
     */
    void Rename(const std::string& name, bool refactor = false);

    /**
     * @brief Get the name of the mod pack.
     * 
     * @return The name of the mod pack.
     */
    const std::string& GetName() const;

    /**
     * @brief Get the mutex for the mod pack.
     * 
     * @return The mutex for the mod pack.
     */
    std::mutex& GetMutex();

    ~ModPack();

private:
    Manifest m_Manifest;

    std::vector<std::shared_ptr<AbstractMod>> m_Mods;
    
    std::filesystem::path m_Path;

    ModResources m_Resources;

    std::mutex m_Mutex;
};

}
