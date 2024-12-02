#include "Mods.hpp"

#include <sstream>
#include <iostream>

using namespace nejlika;

nejlika::Mods::Mods()
{
}

nejlika::Mods::Mods(nejlika::Context& ctx, const Mods &other)
{
    m_AppliedMods =  {};
    m_Callbacks = {};

    m_Path = other.m_Path;

    for (const auto& modPack : other.m_ModPacks)
    {
        m_ModPacks.push_back(std::make_unique<ModPack>(ctx, *modPack));
    }
}

nejlika::Mods::Mods(nejlika::Context& ctx, const std::filesystem::path& path)
{
    m_Path = path;

    // Check if the directory exists.
    if (!std::filesystem::exists(path))
    {
        throw std::runtime_error("Mods directory does not exist.");
    }

    // Iterate over the directory.
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        std::cout << "Loading mod pack \"" << entry.path() << "\"." << std::endl;

        // Check if the entry is a directory.
        if (!entry.is_directory()) continue;

        // Check if it contains a manifest file.
        std::filesystem::path manifestPath = entry.path() / "manifest.json";

        if (!std::filesystem::exists(manifestPath))
        {
            // Skip this directory.
            continue;
        }

        // Add the mod pack to the list of mod packs.
        m_ModPacks.emplace_back(std::make_unique<ModPack>(ctx, entry.path()));

        std::cout << "Loaded mod pack \"" << entry.path() << "\"." << std::endl;
    }

    std::cout << "Loaded " << m_ModPacks.size() << " mod packs." << std::endl;
}

std::vector<std::unique_ptr<ModPack>>& nejlika::Mods::GetModPacks()
{
    return m_ModPacks;
}


const std::filesystem::path& nejlika::Mods::GetPath() const
{
    return m_Path;
}

ModPack& nejlika::Mods::GetModPack(const std::string& name)
{
    for (auto& modPack : m_ModPacks)
    {
        if (modPack->GetManifest().GetName() == name)
        {
            return *modPack;
        }
    }

    std::stringstream ss;

    ss << "Mod pack \"" << name << "\" not found.";

    throw std::runtime_error(ss.str());
}

ModPack& nejlika::Mods::GetModPack(const std::shared_ptr<AbstractMod>& mod)
{
    for (auto& modPack : m_ModPacks)
    {
        if (modPack->IncludesMod(mod))
        {
            return *modPack;
        }
    }

    std::stringstream ss;

    ss << "Mod pack containing mod \"" << mod->GetName() << "\" not found.";

    throw std::runtime_error(ss.str());
}

bool nejlika::Mods::HasModPack(const std::string &name) const
{
    for (const auto& modPack : m_ModPacks)
    {
        if (modPack->GetName() == name)
        {
            return true;
        }
    }

    return false;
}

const std::vector<std::shared_ptr<AbstractMod>>& nejlika::Mods::GetAppliedMods() const
{
    return m_AppliedMods;
}

std::shared_ptr<AbstractMod> nejlika::Mods::GetAppliedMod(const name& name) const
{
    for (auto& mod : m_AppliedMods)
    {
        if (mod->GetName() == name)
        {
            return mod;
        }
    }

    std::stringstream ss;

    ss << "Mod \"" << name << "\" not found.";

    throw std::runtime_error(ss.str());
}

bool nejlika::Mods::HasAppliedMod(const name &name) const
{
    return m_AppliedModsNames.find(name) != m_AppliedModsNames.end();
}

void nejlika::Mods::AddAppliedMod(const name &name, const std::string& type)
{
    m_AppliedModsNames.emplace(name, type);
}

const std::string& nejlika::Mods::GetAppliedModType(const name &name) const
{
    return m_AppliedModsNames.at(name);
}

ModPack &nejlika::Mods::AddModPack(nejlika::Context& ctx, const ModPack &pack)
{
    if (HasModPack(pack.GetName()))
    {
        std::stringstream ss;

        ss << "A mod pack with the name \"" << pack.GetName() << "\" already exists.";

        throw std::runtime_error(ss.str());
    }

    m_ModPacks.push_back(std::make_unique<ModPack>(ctx, pack));

    return *m_ModPacks.back();
}

ModPack &nejlika::Mods::AddModPack(nejlika::Context& ctx, const Manifest &manifest)
{
    if (HasModPack(manifest.GetName()))
    {
        std::stringstream ss;

        ss << "A mod pack with the name \"" << manifest.GetName() << "\" already exists.";

        throw std::runtime_error(ss.str());
    }

    const auto path = m_Path / manifest.GetName();

    m_ModPacks.emplace_back(std::make_unique<ModPack>(manifest, path));

    return *m_ModPacks.back();
}

ModResources &nejlika::Mods::GetResources(const std::shared_ptr<AbstractMod> &mod)
{
    return GetModPack(mod).GetResources();
}

void nejlika::Mods::ApplyMod(nejlika::Context& ctx, const std::shared_ptr<AbstractMod>& mod)
{
    // Check if the mod is already applied.
    if (std::find(m_AppliedMods.begin(), m_AppliedMods.end(), mod) != m_AppliedMods.end())
    {
        std::stringstream ss;

        ss << "Mod \"" << mod->GetName() << "\" is already applied.";

        throw std::runtime_error(ss.str());
    }

    // Apply the mod.
    mod->Apply(ctx);

    // Add the mod to the list of applied mods.
    m_AppliedMods.push_back(mod);
    m_AppliedModsNames.emplace(mod->GetName(), mod->GetType());

    // Invoke callbacks which are waiting for this mod to be applied.
    auto it = m_Callbacks.find(mod->GetName());

    if (it == m_Callbacks.end())
    {
        return;
    }

    for (auto& callback : it->second)
    {
        callback(mod);
    }

    m_Callbacks.erase(it);
}

void nejlika::Mods::AwaitMod(const name& name, std::function<void(std::shared_ptr<AbstractMod>)> callback)
{
    // Check if the mod is already applied.
    for (const auto& mod : m_AppliedMods)
    {
        if (mod->GetName() == name)
        {
            callback(mod);

            return;
        }
    }

    // Add the callback to the list of callbacks.
    m_Callbacks[name].push_back(callback);
}

std::unordered_set<name> nejlika::Mods::GetUnresolved() const
{
    // Unresolved callbacks.
    std::unordered_set<name> unresolved;

    // Iterate over all callbacks.
    for (const auto& [name, callbacks] : m_Callbacks)
    {
        // Add the name to the list of unresolved mods.
        unresolved.insert(name);
    }

    return unresolved;
}

void nejlika::Mods::Save(const std::filesystem::path &path)
{
    // Iterate over all mod packs.
    for (auto& modPack : m_ModPacks)
    {
        const auto packPath = path / modPack->GetManifest().GetName();

        if (!std::filesystem::exists(packPath))
        {
            std::filesystem::create_directory(packPath);
        }

        // Save the mod pack.
        modPack->Save(packPath);
    }
}

void nejlika::Mods::Save()
{
    // Iterate over all mod packs.
    for (auto& modPack : m_ModPacks)
    {
        const auto packPath = modPack->GetPath().empty() ? m_Path / modPack->GetManifest().GetName() : modPack->GetPath();

        std::cout << "Saving mod pack \"" << modPack->GetManifest().GetName() << "\" to \"" << packPath << "\"." << std::endl;

        if (!std::filesystem::exists(packPath))
        {
            std::filesystem::create_directory(packPath);
        }

        // Save the mod pack.
        modPack->Save(packPath);
    }
}
