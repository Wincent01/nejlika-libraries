#include "SpawnerData.hpp"

nejlika::world::SpawnerData::SpawnerData(nejlika::Reader &io, version version)
{
    m_SpawnedLot = io.Read<uint32_t>();

    m_RespawnTime = io.Read<uint32_t>();
    
    m_MaxToSpawn = io.Read<int32_t>();
    
    m_NumToMaintain = io.Read<uint32_t>();
    
    m_ObjectID = io.Read<uint64_t>();
    
    m_ActivateOnLoad = version >= 9 ? io.Read<bool>() : false;
}

nejlika::world::SpawnerData::SpawnerData()
{
}

void nejlika::world::SpawnerData::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_SpawnedLot);
    
    io.Write(m_RespawnTime);
    
    io.Write(m_MaxToSpawn);
    
    io.Write(m_NumToMaintain);
    
    io.Write(m_ObjectID);
    
    if (version >= 9)
    {
        io.Write(m_ActivateOnLoad);
    }
}

uint32_t nejlika::world::SpawnerData::GetSpawnedLot() const
{
    return m_SpawnedLot;
}

uint32_t nejlika::world::SpawnerData::GetRespawnTime() const
{
    return m_RespawnTime;
}

int32_t nejlika::world::SpawnerData::GetMaxToSpawn() const
{
    return m_MaxToSpawn;
}

uint32_t nejlika::world::SpawnerData::GetNumToMaintain() const
{
    return m_NumToMaintain;
}

uint64_t nejlika::world::SpawnerData::GetObjectID() const
{
    return m_ObjectID;
}

bool nejlika::world::SpawnerData::GetActivateOnLoad() const
{
    return m_ActivateOnLoad;
}

void nejlika::world::SpawnerData::SetSpawnedLot(uint32_t spawnedLot)
{
    m_SpawnedLot = spawnedLot;
}

void nejlika::world::SpawnerData::SetRespawnTime(uint32_t respawnTime)
{
    m_RespawnTime = respawnTime;
}

void nejlika::world::SpawnerData::SetMaxToSpawn(int32_t maxToSpawn)
{
    m_MaxToSpawn = maxToSpawn;
}

void nejlika::world::SpawnerData::SetNumToMaintain(uint32_t numToMaintain)
{
    m_NumToMaintain = numToMaintain;
}

void nejlika::world::SpawnerData::SetObjectID(uint64_t objectID)
{
    m_ObjectID = objectID;
}

void nejlika::world::SpawnerData::SetActivateOnLoad(bool activateOnLoad)
{
    m_ActivateOnLoad = activateOnLoad;
}

nejlika::world::SpawnerData::~SpawnerData()
{
}
