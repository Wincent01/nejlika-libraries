#include "Waypoint.hpp"

nejlika::world::Waypoint::Waypoint(nejlika::Reader &io, version version, PathType pathType)
{
    m_PathType = pathType;

    m_Position = io.Read<vector3>();

    switch (pathType)
    {
    case PathType::NPC:
        m_Data = std::make_unique<NpcWaypointData>(io, version);
        break;
    case PathType::Platform:
        m_Data = std::make_unique<PlatformWaypointData>(io, version);
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraWaypointData>(io, version);
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerWaypointData>(io, version);
        break;
    case PathType::Racing:
        m_Data = std::make_unique<RacingWaypointData>(io, version);
        break;
    case PathType::Rail:
        m_Data = std::make_unique<RailWaypointData>(io, version);
        break;
    default:
        m_Data = nullptr;
        break;
    }
}

nejlika::world::Waypoint::Waypoint(const vector3 &position, PathType pathType)
{
    m_Position = position;

    m_PathType = pathType;

    switch (pathType)
    {
    case PathType::NPC:
        m_Data = std::make_unique<NpcWaypointData>();
        break;
    case PathType::Platform:
        m_Data = std::make_unique<PlatformWaypointData>();
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraWaypointData>();
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerWaypointData>();
        break;
    case PathType::Racing:
        m_Data = std::make_unique<RacingWaypointData>();
        break;
    case PathType::Rail:
        m_Data = std::make_unique<RailWaypointData>();
        break;
    default:
        m_Data = nullptr;
        break;
    }
}

nejlika::world::Waypoint::Waypoint(const Waypoint &other)
{
    m_Position = other.m_Position;

    m_PathType = other.m_PathType;

    switch (m_PathType)
    {
    case PathType::NPC:
        m_Data = std::make_unique<NpcWaypointData>(*dynamic_cast<NpcWaypointData*>(other.m_Data.get()));
        break;
    case PathType::Platform:
        m_Data = std::make_unique<PlatformWaypointData>(*dynamic_cast<PlatformWaypointData*>(other.m_Data.get()));
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraWaypointData>(*dynamic_cast<CameraWaypointData*>(other.m_Data.get()));
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerWaypointData>(*dynamic_cast<SpawnerWaypointData*>(other.m_Data.get()));
        break;
    case PathType::Racing:
        m_Data = std::make_unique<RacingWaypointData>(*dynamic_cast<RacingWaypointData*>(other.m_Data.get()));
        break;
    case PathType::Rail:
        m_Data = std::make_unique<RailWaypointData>(*dynamic_cast<RailWaypointData*>(other.m_Data.get()));
        break;
    default:
        m_Data = nullptr;
        break;
    }
}

void nejlika::world::Waypoint::Save(nejlika::Writer &io, version version, PathType pathType) const
{
    io.Write(m_Position);

    switch (pathType)
    {
    case PathType::NPC:
        m_Data->Save(io, version);
        break;
    case PathType::Platform:
        m_Data->Save(io, version);
        break;
    case PathType::Camera:
        m_Data->Save(io, version);
        break;
    case PathType::Spawner:
        m_Data->Save(io, version);
        break;
    case PathType::Racing:
        m_Data->Save(io, version);
        break;
    case PathType::Rail:
        m_Data->Save(io, version);
        break;
    default:
        break;
    }
}

const vector3 &nejlika::world::Waypoint::GetPosition() const
{
    return m_Position;
}

nejlika::world::Waypoint::~Waypoint()
{
}