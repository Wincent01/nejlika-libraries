#include "Path.hpp"

nejlika::world::Path::Path(nejlika::Reader &io, version pathVersion)
{
    m_PathVersion = io.Read<version>();

    m_Name = io.ReadString16<uint8_t>();

    if (m_PathVersion <= 2) {
        m_TypeName = io.ReadString16<uint8_t>();
    }

    m_PathType = static_cast<PathType>(io.Read<uint32_t>());

    m_Flags = io.Read<uint32_t>();

    m_Behavior = static_cast<PathBehavior>(io.Read<uint32_t>());

    switch (m_PathType)
    {
    case PathType::Platform:
        m_Data = std::make_unique<PlatformData>(io, m_PathVersion);
        break;
    case PathType::Property:
        m_Data = std::make_unique<PropertyData>(io, m_PathVersion);
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraData>(io, m_PathVersion);
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerData>(io, m_PathVersion);
        break;
    default:
        m_Data = nullptr;
        break;
    }

    uint32_t waypointCount = io.Read<uint32_t>();

    m_Waypoints.reserve(waypointCount);

    for (int i = 0; i < waypointCount; i++)
    {
        m_Waypoints.push_back(Waypoint(io, m_PathVersion, m_PathType));
    }
}

nejlika::world::Path::Path(PathType pathType, version pathVersion)
{
    m_PathVersion = pathVersion;

    m_PathType = pathType;
    
    switch (m_PathType)
    {
    case PathType::Platform:
        m_Data = std::make_unique<PlatformData>();
        break;
    case PathType::Property:
        m_Data = std::make_unique<PropertyData>();
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraData>();
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerData>();
        break;
    default:
        m_Data = nullptr;
        break;
    }

    m_Flags = 0;

    m_Behavior = PathBehavior::Loop;
}

nejlika::world::Path::Path(const Path &other)
{
    m_PathVersion = other.m_PathVersion;

    m_Name = other.m_Name;

    m_TypeName = other.m_TypeName;

    m_PathType = other.m_PathType;

    m_Flags = other.m_Flags;

    m_Behavior = other.m_Behavior;

    switch (m_PathType)
    {
    case PathType::Platform:
        m_Data = std::make_unique<PlatformData>(*dynamic_cast<PlatformData*>(other.m_Data.get()));
        break;
    case PathType::Property:
        m_Data = std::make_unique<PropertyData>(*dynamic_cast<PropertyData*>(other.m_Data.get()));
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraData>(*dynamic_cast<CameraData*>(other.m_Data.get()));
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerData>(*dynamic_cast<SpawnerData*>(other.m_Data.get()));
        break;
    default:
        m_Data = nullptr;
        break;
    }

    for (int i = 0; i < other.m_Waypoints.size(); i++)
    {
        m_Waypoints.push_back(other.m_Waypoints[i]);
    }
}

nejlika::world::Path& nejlika::world::Path::operator=(const nejlika::world::Path& other)
{
    m_PathVersion = other.m_PathVersion;

    m_Name = other.m_Name;

    m_TypeName = other.m_TypeName;

    m_PathType = other.m_PathType;

    m_Flags = other.m_Flags;

    m_Behavior = other.m_Behavior;

    switch (m_PathType)
    {
    case PathType::Platform:
        m_Data = std::make_unique<PlatformData>(*dynamic_cast<PlatformData*>(other.m_Data.get()));
        break;
    case PathType::Property:
        m_Data = std::make_unique<PropertyData>(*dynamic_cast<PropertyData*>(other.m_Data.get()));
        break;
    case PathType::Camera:
        m_Data = std::make_unique<CameraData>(*dynamic_cast<CameraData*>(other.m_Data.get()));
        break;
    case PathType::Spawner:
        m_Data = std::make_unique<SpawnerData>(*dynamic_cast<SpawnerData*>(other.m_Data.get()));
        break;
    default:
        m_Data = nullptr;
        break;
    }

    m_Waypoints.clear();

    for (int i = 0; i < other.m_Waypoints.size(); i++)
    {
        m_Waypoints.push_back(other.m_Waypoints[i]);
    }

    return *this;
}

void nejlika::world::Path::Save(nejlika::Writer &io, version pathVersion) const
{
    io.Write(m_PathVersion);

    io.WriteString16<uint8_t>(m_Name);

    if (m_PathVersion <= 2) {
        io.WriteString16<uint8_t>(m_TypeName);
    }

    io.Write(static_cast<uint32_t>(m_PathType));

    io.Write(m_Flags);

    io.Write(static_cast<uint32_t>(m_Behavior));

    switch (m_PathType)
    {
    case PathType::Platform:
        m_Data->Save(io, m_PathVersion);
        break;
    case PathType::Property:
        m_Data->Save(io, m_PathVersion);
        break;
    case PathType::Camera:
        m_Data->Save(io, m_PathVersion);
        break;
    case PathType::Spawner:
        m_Data->Save(io, m_PathVersion);
        break;
    default:
        break;
    }

    io.Write(static_cast<uint32_t>(m_Waypoints.size()));

    for (int i = 0; i < m_Waypoints.size(); i++)
    {
        m_Waypoints[i].Save(io, m_PathVersion, m_PathType);
    }
}

version nejlika::world::Path::GetPathVersion() const
{
    return m_PathVersion;
}

const str16 &nejlika::world::Path::GetName() const
{
    return m_Name;
}

const str16 &nejlika::world::Path::GetTypeName() const
{
    return m_TypeName;
}

PathType nejlika::world::Path::GetPathType() const
{
    return m_PathType;
}

uint32_t nejlika::world::Path::GetFlags() const
{
    return m_Flags;
}

PathBehavior nejlika::world::Path::GetBehavior() const
{
    return m_Behavior;
}

std::vector<nejlika::world::Waypoint> &nejlika::world::Path::GetWaypoints()
{
    return m_Waypoints;
}

void nejlika::world::Path::SetName(const str16& name)
{
    m_Name = name;
}

void nejlika::world::Path::SetTypeName(const str16& typeName)
{
    m_TypeName = typeName;
}

void nejlika::world::Path::SetFlags(uint32_t flags)
{
    m_Flags = flags;
}

void nejlika::world::Path::SetBehavior(PathBehavior behavior)
{
    m_Behavior = behavior;
}

nejlika::world::Path::~Path()
{
    m_Waypoints.clear();
}
