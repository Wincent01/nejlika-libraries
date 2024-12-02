#include "World.hpp"

#include "Artifacts.hpp"
#include "ModResources.hpp"
#include "Writer.hpp"
#include "Database.hpp"
#include "Lookup.hpp"
#include "Configuration.hpp"
#include "Reader.hpp"

#include <fstream>
#include <future>
#include <thread>
#include <mutex>
#include <sstream>
#include <iostream>

using namespace nejlika::world;
using namespace nejlika;

Zone& World::GetZone()
{
    return m_Zone;
}

Level& World::GetLevel(int32_t id, int32_t layer)
{
    auto it = m_Levels.find((static_cast<uint64_t>(id) << 32) | layer);

    if (it == m_Levels.end())
    {
        std::stringstream ss;

        ss << "Level with id " << id << " and layer " << layer << " does not exist in the world.";

        throw std::runtime_error(ss.str());
    }

    return it->second;
}

Level& nejlika::world::World::GetLevel(uint64_t key)
{
    auto it = m_Levels.find(key);

    if (it == m_Levels.end())
    {
        std::stringstream ss;

        ss << "Level with key " << key << " does not exist in the world.";

        throw std::runtime_error(ss.str());
    }

    return it->second;
}

Level& World::AddLevel(int32_t id, int32_t layer)
{
    const auto key = (static_cast<uint64_t>(id) << 32) | layer;

    if (m_Levels.find(key) != m_Levels.end())
    {
        std::stringstream ss;

        ss << "Level with id " << id << " and layer " << layer << " already exists in the world.";

        throw std::runtime_error(ss.str());
    }

    return m_Levels[key] = Level();
}

bool World::RemoveLevel(int32_t id, int32_t layer)
{
    const auto key = (static_cast<uint64_t>(id) << 32) | layer;

    return m_Levels.erase(key) > 0;
}

bool World::HasLevel(int32_t id, int32_t layer) const
{
    const auto key = (static_cast<uint64_t>(id) << 32) | layer;

    return m_Levels.find(key) != m_Levels.end();
}

void World::Save(nejlika::Context& ctx, const nejlika::name& name)
{
    if (!ctx.artifacts->CanGenerateFiles())
    {
        return;
    }

    // The path from with all files will be saved.
    const auto root = ctx.artifacts->GetAddedResourcePath(ctx, name);

    const auto path = ctx.configuration->GetClient();

    // Create the directory.
    std::filesystem::create_directories(path / root);

    auto& scenes = m_Zone.GetScenes();

    // Loop through all levels and save them.
    for (auto& [key, level] : m_Levels)
    {
        const auto id = static_cast<int32_t>(key >> 32);
        const auto layer = static_cast<int32_t>(key & 0xFFFFFFFF);

        const std::filesystem::path filename = (std::to_string(id) + "_" + std::to_string(layer) + ".lvl");

        auto levelPath = root / filename;

        for (auto& scene : scenes)
        {
            if (scene.GetSceneID() == id && scene.GetLayerID() == layer)
            {
                scene.SetSceneFilename(filename);
            }
        }

        Writer levelWriter;
        level.Save(levelWriter);
        levelWriter.Save(path / levelPath);

        ctx.artifacts->RegisterGeneratedFile(ctx, levelPath);

        if (layer == 0)
        {
            // Check if a lutriggers file exists.
            auto it = m_Triggers.find(id);

            if (it != m_Triggers.end())
            {
                const auto lutriggersPath = levelPath.replace_extension(".lutriggers");

                it->second->SaveFile((path / lutriggersPath.string()).string().c_str());

                ctx.artifacts->RegisterGeneratedFile(ctx, lutriggersPath);
            }

            // Check if a aud file exists.
            it = m_Audio.find(id);

            if (it != m_Audio.end())
            {
                const auto audPath = levelPath.replace_extension(".aud");

                it->second->SaveFile((path / audPath.string()).string().c_str());

                ctx.artifacts->RegisterGeneratedFile(ctx, audPath);
            }
        }
    }

    // The path to the world file.
    const auto zonePath = root / "zone.luz";

    m_Zone.GetTerrainFilename() = "zone.raw";

    // Save the world file.
    Writer zoneWriter;
    m_Zone.Save(zoneWriter);
    zoneWriter.Save(path / zonePath);

    ctx.artifacts->RegisterGeneratedFile(ctx, zonePath);

    const auto worldId = ctx.lookup->GetValue(name);
    
    auto deltStmt = ctx.database->Prepare("DELETE FROM ZoneTable WHERE zoneID = ?;");

    deltStmt.bind(1, worldId);

    deltStmt.execDML();

    deltStmt.finalize();

    auto stmt = ctx.database->Prepare(R"(
        INSERT INTO ZoneTable (
            zoneID, locStatus, zoneName, scriptID,
            ghostdistance_min, ghostdistance, population_soft_cap, population_hard_cap,
            mixerProgram, petsAllowed, localize, fZoneWeight, 
            PlayerLoseCoinsOnDeath, disableSaveLoc, mountsAllowed
        ) VALUES (
            ?, ?, ?, ?,
            ?, ?, ?, ?,
            ?, ?, ?, ?,
            ?, ?, ?
        );
    )");

    stmt.bind(1, worldId);
    stmt.bind(2, 2);
    stmt.bind(3, ("../../" / root / "zone.luz").c_str());
    stmt.bind(4, m_ScriptID);
    stmt.bind(5, m_GhostDistanceMin);
    stmt.bind(6, m_GhostDistanceMax);
    stmt.bind(7, m_PopulationSoftCap);
    stmt.bind(8, m_PopulationHardCap);
    stmt.bind(9, m_MixerProgram.c_str());
    stmt.bind(10, m_PetsAllowed);
    stmt.bind(11, 1);
    stmt.bind(12, 1);
    stmt.bind(13, m_PlayersLoseCoinsOnDeath);
    stmt.bind(14, 0);
    stmt.bind(15, m_MountsAllowed);

    stmt.execDML();

    stmt.finalize();

    bool hasCopiedRaw = false;

    // Copy all ".raw", ".lutriggers", ".evc", and ".ast" files from the original path to the new path.
    for (const auto& entry : std::filesystem::directory_iterator(m_OriginalPath))
    {
        const auto& originalPath = entry.path();

        const auto& extension = originalPath.extension();

        if (extension == ".raw" || extension == ".evc" || extension == ".ast")
        {
            if (hasCopiedRaw && extension == ".raw") // Don't you dare!
            {
                continue;
            }

            const auto& newPath = root / ("zone" + extension.string());

            std::filesystem::copy(originalPath, path / newPath, std::filesystem::copy_options::overwrite_existing);

            ctx.artifacts->RegisterGeneratedFile(ctx, newPath);

            if (extension == ".raw")
            {
                hasCopiedRaw = true;
            }
        }
    }
}

void nejlika::world::World::Load(nejlika::Context &ctx, const nejlika::name &name)
{
    auto top_start = std::chrono::high_resolution_clock::now();

    const auto worldId = ctx.lookup->GetValue(name);

    auto stmt = ctx.database->Prepare(R"(
        SELECT
            zoneName, scriptID, ghostdistance_min, ghostdistance,
            population_soft_cap, population_hard_cap, mixerProgram,
            petsAllowed, PlayerLoseCoinsOnDeath, mountsAllowed
        FROM ZoneTable WHERE zoneID = ?;
    )");

    stmt.bind(1, worldId);
    auto result = stmt.execQuery();

    if (result.eof())
    {
        std::stringstream ss;
        ss << "World with id " << worldId << " does not exist in the database.";
        throw std::runtime_error(ss.str());
    }

    const auto maps = ctx.configuration->GetClient() / "res/maps";
    std::string filename = result.getStringField(0);
    std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
    const auto path = maps / filename;
    const auto root = path.parent_path();

    m_ScriptID = result.getIntField(1);
    m_GhostDistanceMin = result.getFloatField(2);
    m_GhostDistanceMax = result.getFloatField(3);
    m_PopulationSoftCap = result.getIntField(4);
    m_PopulationHardCap = result.getIntField(5);
    m_MixerProgram = result.getStringField(6);
    m_PetsAllowed = result.getIntField(7);
    m_PlayersLoseCoinsOnDeath = result.getIntField(8);
    m_MountsAllowed = result.getIntField(9);

    stmt.finalize();

    // Wait for the reader to be ready
    auto start_time = std::chrono::high_resolution_clock::now();

    Reader reader(path);
    m_Zone = Zone(reader);

    auto end_time = std::chrono::high_resolution_clock::now();

    std::cout << "Loaded zone " << path << " in " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << std::endl;

    m_TerrainPath = std::filesystem::path(filename).parent_path() / m_Zone.GetTerrainFilename();
    m_OriginalPath = root.string();
    
    for (auto& scene : m_Zone.GetScenes())
    {
        std::string filename = scene.GetSceneFilename();
        std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
        auto levelPath = root / filename;

        if (!std::filesystem::exists(levelPath))
        {
            std::stringstream ss;
            ss << "Level file " << levelPath << " does not exist.";
            throw std::runtime_error(ss.str());
        }

        start_time = std::chrono::high_resolution_clock::now();

        Reader levelReader(levelPath);

        const auto hash = (static_cast<uint64_t>(scene.GetSceneID()) << 32) | scene.GetLayerID();

        m_Levels.emplace(hash, levelReader);

        end_time = std::chrono::high_resolution_clock::now();

        std::cout << "Loaded level " << levelPath << " in " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << std::endl;

        auto& level = m_Levels.at(hash);

        for (auto& [id, object] : level.GetObjects().GetObjectMap())
        {
            m_ObjectIds.insert(id);
        }

        // Load lutriggers and aud files in parallel
        const auto lutriggersPath = levelPath.replace_extension(".lutriggers");
        if (std::filesystem::exists(lutriggersPath))
        {
            auto lutriggersDoc = std::make_shared<tinyxml2::XMLDocument>();
            lutriggersDoc->LoadFile(lutriggersPath.string().c_str());

            m_Triggers.emplace(scene.GetSceneID(), lutriggersDoc);
        }

        const auto audPath = levelPath.replace_extension(".aud");
        if (std::filesystem::exists(audPath))
        {
            auto audDoc = std::make_shared<tinyxml2::XMLDocument>();
            audDoc->LoadFile(audPath.string().c_str());

            m_Audio.emplace(scene.GetSceneID(), audDoc);
        }
    }

    auto top_end = std::chrono::high_resolution_clock::now();

    std::cout << "Loaded world in " << std::chrono::duration_cast<std::chrono::milliseconds>(top_end - top_start).count() << "ms" << std::endl;
}

std::unordered_map<uint64_t, Level> &nejlika::world::World::GetLevels()
{
    return m_Levels;
}

std::filesystem::path nejlika::world::World::GetTerrainPath()
{
    return m_TerrainPath;
}

uint64_t nejlika::world::World::ClaimObjectId()
{
    while (m_ObjectIds.find(m_LowestObjectId) != m_ObjectIds.end())
    {
        m_LowestObjectId++;
    }

    m_ObjectIds.insert(m_LowestObjectId);
    
    return m_LowestObjectId;
}
