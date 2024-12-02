#include "NpcWaypointData.hpp"

nejlika::world::NpcWaypointData::NpcWaypointData(nejlika::Reader &io, version version)
{
    m_Config = PathKeyValuePairs(io, version);
}

nejlika::world::NpcWaypointData::NpcWaypointData()
{
}

void nejlika::world::NpcWaypointData::Save(nejlika::Writer &io, version version) const
{
    m_Config.Save(io, version);
}

const nejlika::world::PathKeyValuePairs& nejlika::world::NpcWaypointData::GetConfig() const
{
    return m_Config;
}

nejlika::world::NpcWaypointData::~NpcWaypointData()
{
}
