#include "BoundaryLine.hpp"

nejlika::world::BoundaryLine::BoundaryLine(nejlika::Reader &io, version version)
{
    m_Normal = io.Read<vector3>();

    m_Point = io.Read<vector3>();

    m_DestinationZoneID = io.Read<uint32_t>();

    m_DestinationSceneID = io.Read<uint32_t>();

    m_SpawnLocation = io.Read<vector3>();
}

void nejlika::world::BoundaryLine::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_Normal);

    io.Write(m_Point);

    io.Write(m_DestinationZoneID);

    io.Write(m_DestinationSceneID);

    io.Write(m_SpawnLocation);
}

const vector3 &nejlika::world::BoundaryLine::GetNormal() const
{
    return m_Normal;
}

const vector3 &nejlika::world::BoundaryLine::GetPoint() const
{
    return m_Point;
}

uint32_t nejlika::world::BoundaryLine::GetDestinationZoneID() const
{
    return m_DestinationZoneID;
}

uint32_t nejlika::world::BoundaryLine::GetDestinationSceneID() const
{
    return m_DestinationSceneID;
}

const vector3 &nejlika::world::BoundaryLine::GetSpawnLocation() const
{
    return m_SpawnLocation;
}

nejlika::world::BoundaryLine::~BoundaryLine()
{
}