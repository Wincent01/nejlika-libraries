#pragma once

#include "Zone.hpp"
#include "Level.hpp"
#include "nejlika.hpp"

#include <tinyxml2.h>

#include <unordered_map>
#include <unordered_set>

namespace nejlika::world
{

class World
{
public:
    World() = default;

    Zone& GetZone();

    Level& GetLevel(int32_t id, int32_t layer);

    Level& GetLevel(uint64_t key);

    Level& AddLevel(int32_t id, int32_t layer);

    bool RemoveLevel(int32_t id, int32_t layer);
    
    bool HasLevel(int32_t id, int32_t layer) const;

    void Save(nejlika::Context& ctx, const nejlika::name& name);

    void Load(nejlika::Context& ctx, const nejlika::name& name);

    std::unordered_map<uint64_t, Level>& GetLevels();

    std::filesystem::path GetTerrainPath();

    uint64_t ClaimObjectId();

    void SetScriptID(int32_t scriptId);
    int32_t GetScriptID() const;

    void SetGhostDistanceMin(float distance);
    float GetGhostDistanceMin() const;

    void SetGhostDistanceMax(float distance);
    float GetGhostDistanceMax() const;

    void SetPopulationSoftCap(int32_t cap);
    int32_t GetPopulationSoftCap() const;

    void SetPopulationHardCap(int32_t cap);
    int32_t GetPopulationHardCap() const;

    void SetMixerProgram(const std::string& program);
    const std::string& GetMixerProgram() const;

    void SetPetsAllowed(bool allowed);
    bool ArePetsAllowed() const;

    void SetPlayersLoseCoinsOnDeath(bool loseCoins);
    bool DoPlayersLoseCoinsOnDeath() const;

    void SetMountsAllowed(bool allowed);
    bool AreMountsAllowed() const;

private:
    Zone m_Zone;

    std::unordered_map<uint64_t, Level> m_Levels;

    std::unordered_set<uint64_t> m_ObjectIds;

    std::unordered_map<uint64_t, std::shared_ptr<tinyxml2::XMLDocument>> m_Triggers;

    std::unordered_map<uint64_t, std::shared_ptr<tinyxml2::XMLDocument>> m_Audio;

    uint64_t m_LowestObjectId = 0x38B40Aul;

    int32_t m_ScriptID = -1;

    float m_GhostDistanceMin = 0.0f;

    float m_GhostDistanceMax = 1000.0f;

    int32_t m_PopulationSoftCap = 30;

    int32_t m_PopulationHardCap = 50;

    std::string m_MixerProgram;

    bool m_PetsAllowed = true;

    bool m_PlayersLoseCoinsOnDeath = true;

    bool m_MountsAllowed = true;

    std::string m_OriginalPath;

    std::filesystem::path m_TerrainPath;
};

}
