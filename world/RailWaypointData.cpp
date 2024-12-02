#include "RailWaypointData.hpp"

nejlika::world::RailWaypointData::RailWaypointData(nejlika::Reader &io, version version)
{
    m_Rotation = io.Read<vector4>();

    m_Speed = version >= 16 ? io.Read<float>() : 1.0f;

    m_Config = PathKeyValuePairs(io, version);
}

nejlika::world::RailWaypointData::RailWaypointData()
{
}

void nejlika::world::RailWaypointData::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_Rotation);

    if (version >= 16)
    {
        io.Write(m_Speed);
    }

    m_Config.Save(io, version);
}

const vector4 &nejlika::world::RailWaypointData::GetRotation() const
{
    return m_Rotation;
}

float nejlika::world::RailWaypointData::GetSpeed() const
{
    return m_Speed;
}

const nejlika::world::PathKeyValuePairs &nejlika::world::RailWaypointData::GetConfig() const
{
    return m_Config;
}

nejlika::world::RailWaypointData::~RailWaypointData()
{
}
