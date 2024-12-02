#include "SpawnerWaypointData.hpp"


nejlika::world::SpawnerWaypointData::SpawnerWaypointData(nejlika::Reader& io, version version)
{
    m_Rotation = io.Read<vector4>();

    m_Config = PathKeyValuePairs(io, version);
}

nejlika::world::SpawnerWaypointData::SpawnerWaypointData()
{
}

void nejlika::world::SpawnerWaypointData::Save(nejlika::Writer& io, version version) const
{
    io.Write(m_Rotation);

    m_Config.Save(io, version);
}

const vector4& nejlika::world::SpawnerWaypointData::GetRotation() const
{
    return m_Rotation;
}

const nejlika::world::PathKeyValuePairs& nejlika::world::SpawnerWaypointData::GetConfig() const
{
    return m_Config;
}

void nejlika::world::SpawnerWaypointData::SetRotation(const vector4 &rotation)
{
    m_Rotation = rotation;
}

nejlika::world::PathKeyValuePairs& nejlika::world::SpawnerWaypointData::GetConfig()
{
    return m_Config;
}

nejlika::world::SpawnerWaypointData::~SpawnerWaypointData()
{
}

