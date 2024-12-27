#pragma once

#include <filesystem>
#include <unordered_set>

#include "nejlika.hpp"
#include "ModPack.hpp"

namespace nejlika
{

class AbstractMod;

/**
 * @brief A registry of applied mods and mod packs.
 * 
 * Provides utilities for managing mods and mod packs.
 */
class Mods
{
public:
    /**
     * @brief Constructs a new Mods object.
     */
    Mods();

    Mods(nejlika::Context& ctx, const Mods& other);

    /**
     * @brief Constructs a new Mods object from the specified mods directory.
     * 
     * @param path The path to the mods directory.
     */
    Mods(nejlika::Context& ctx, const std::filesystem::path& path);

    /**
     * @brief Gets the list of applied mods.
     * 
     * @return The list of applied mods.
     */
    const std::vector<std::shared_ptr<AbstractMod>>& GetAppliedMods() const;

    /**
     * @brief Gets the list of mod packs.
     * 
     * @return The list of mod packs.
     */
    std::vector<std::unique_ptr<ModPack>>& GetModPacks();

    /**
     * @brief Gets the path to the mods directory.
     * 
     * @return The path to the mods directory.
     */
    const std::filesystem::path& GetPath() const;

    /**
     * @brief Get a applied mod by its name.
     * 
     * @param name The name of the mod to get.
     * @return The mod with the specified name.
     * @throw If the mod is not found.
     */
    std::shared_ptr<AbstractMod> GetAppliedMod(const name& name) const;

    /**
     * @brief Check if a mod has been applied.
     * 
     * @param name The name of the mod to check.
     * @return If the mod has been applied.
     */
    bool HasAppliedMod(const name& name) const;

    /**
     * @brief Add a applied mod.
     * 
     * @param name The name of the mod to add.
     */
    void AddAppliedMod(const name& name, const std::string& type);

    /**
     * @brief Get the type of an applied mod.
     * 
     * @param name The name of the mod to get the type of.
     * @return The type of the mod.
     */
    const std::string& GetAppliedModType(const name& name) const;

    /**
     * @brief Get a mod pack by its name.
     * 
     * @param name The name of the mod pack to get.
     * @return The mod pack with the specified name.
     * @throw If the mod pack is not found.
     */
    ModPack& GetModPack(const std::string& name);

    /**
     * @brief Get a mod pack by a mod it contains.
     * 
     * @param mod The mod to get the mod pack for.
     * @return The mod pack containing the specified mod.
     * @throw If the mod pack is not found.
     */
    ModPack& GetModPack(const std::shared_ptr<AbstractMod>& mod);

    /**
     * @brief Check if a mod pack exists.
     * 
     * @param name The name of the mod pack to check.
     * @return If the mod pack exists.
     */
    bool HasModPack(const std::string& name) const;

    /**
     * @brief Add a mod pack.
     * 
     * @param pack The mod pack to add.
     * @return The mod pack that was added.
     * @throw If the mod pack already exists.
     * 
     * @note This will do a deep copy of the mod pack.
     */
    ModPack& AddModPack(nejlika::Context& ctx, const ModPack& pack);

    /**
     * @brief Add a mod pack.
     * 
     * @param manifest The details of the mod pack to add.
     * @return The mod pack that was added.
     * @throw If the mod pack already exists.
     * 
     * @note Will create in a subdirectory of the mods directory with the name of the mod pack.
     */
    ModPack& AddModPack(nejlika::Context& ctx, const Manifest& manifest);

    /**
     * @brief Remove a mod pack.
     * 
     * @param name The name of the mod pack to remove.
     * @throw If the mod pack is not found.
     */
    void RemoveModPack(const std::string& name);

    /**
     * @brief Get the resources for a mod pack by a mod it contains.
     * 
     * @param mod The mod to get the resources for.
     * @return The resources for the specified mod.
     * @throw If the mod pack is not found.
     */
    ModResources& GetResources(const std::shared_ptr<AbstractMod>& mod);

    /**
     * @brief Applies a mod.
     * 
     * @param mod The mod to apply.
     */
    void ApplyMod(nejlika::Context& ctx, const std::shared_ptr<AbstractMod>& mod);

    /**
     * @brief Set up a callback to be called when the specified mod is applied.
     * 
     * @param mod The mod name to wait for.
     * @param callback The callback to call when the mod is applied.
     */
    void AwaitMod(const name& mod, std::function<void(std::shared_ptr<AbstractMod>)> callback);

    /**
     * @brief Get a set of all unresolved mods.
     * 
     * @return A set of all unresolved mods.
     */
    std::unordered_set<name> GetUnresolved() const;

    /**
     * @brief Save the mod packs.
     * 
     * @param path The path to save the mod packs to.
     * 
     * @note Will save each mod packs to a subdirectory of the specified path, with the name of the mod pack.
     * @note See ModPack::Save for more information.
     */
    void Save(const std::filesystem::path& path);

    /**
     * @brief Save the mod packs to the mods directory.
     * 
     * @note See ModPack::Save for more information.
     */
    void Save();

private:
    std::vector<std::shared_ptr<AbstractMod>> m_AppliedMods;
    std::unordered_map<name, std::string> m_AppliedModsNames;

    std::vector<std::unique_ptr<ModPack>> m_ModPacks;

    std::filesystem::path m_Path;

    std::unordered_map<name, std::vector<std::function<void(std::shared_ptr<AbstractMod>)>>> m_Callbacks;
};

}
