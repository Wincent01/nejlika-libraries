#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class SpawnerData : public WorldSerialize
{
public:
    SpawnerData(nejlika::Reader& io, version version);

    SpawnerData();

    void Save(nejlika::Writer& io, version version) const override;

    uint32_t GetSpawnedLot() const;

    uint32_t GetRespawnTime() const;

    int32_t GetMaxToSpawn() const;

    uint32_t GetNumToMaintain() const;

    uint64_t GetObjectID() const;

    bool GetActivateOnLoad() const;

    void SetSpawnedLot(uint32_t spawnedLot);

    void SetRespawnTime(uint32_t respawnTime);

    void SetMaxToSpawn(int32_t maxToSpawn);

    void SetNumToMaintain(uint32_t numToMaintain);

    void SetObjectID(uint64_t objectID);

    void SetActivateOnLoad(bool activateOnLoad);

    ~SpawnerData();

private:
    uint32_t m_SpawnedLot;

    uint32_t m_RespawnTime;

    int32_t m_MaxToSpawn;

    uint32_t m_NumToMaintain;

    uint64_t m_ObjectID;

    bool m_ActivateOnLoad;
};

}