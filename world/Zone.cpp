#include "Zone.hpp"

nejlika::world::Zone::Zone(nejlika::Reader &io)
{
    m_Version = io.Read<uint32_t>();

    m_FileRevision = m_Version >= 36 ? io.Read<uint32_t>() : 0;

    m_ZoneID = io.Read<uint32_t>();

    m_PlayerStartPos = m_Version >= 38 ? io.Read<vector3>() : vector3();

    m_PlayerStartRot = m_Version >= 38 ? io.Read<vector4>() : vector4();

    uint32_t numSceneFiles = m_Version >= 37 ? io.Read<uint32_t>() : io.Read<uint8_t>();

    for (uint32_t i = 0; i < numSceneFiles; i++)
    {
        m_Scenes.push_back(nejlika::world::SceneReference(io, m_Version));
    }

    uint8_t numZoneBoundaryLines = io.Read<uint8_t>();

    for (uint8_t i = 0; i < numZoneBoundaryLines; i++)
    {
        m_BoundaryLines.push_back(nejlika::world::BoundaryLine(io, m_Version));
    }

    m_TerrainFilename = io.ReadString<uint8_t>();

    m_ZoneName = m_Version >= 31 ? io.ReadString<uint8_t>() : "";

    m_ZoneDescription = m_Version >= 31 ? io.ReadString<uint8_t>() : "";

    if (m_Version >= 32)
    {
        m_TransitionInformation = nejlika::world::TransitionInformation(io, m_Version);
    }

    if (m_Version >= 35)
    {
        uint32_t pathChunkSize = io.Read<uint32_t>();
        
        size_t head = io.GetReadHead();

        m_PathInformation = nejlika::world::PathInformation(io, m_Version);

        // Assert that the path chunk size is correct
        if (io.GetReadHead() - head != pathChunkSize)
        {
            throw std::runtime_error("Path chunk size mismatch");
        }
    }
}

void nejlika::world::Zone::Save(nejlika::Writer &io) const
{
    io.Write(m_Version);

    if (m_Version >= 36)
    {
        io.Write(m_FileRevision);
    }

    io.Write(m_ZoneID);

    if (m_Version >= 38)
    {
        io.Write(m_PlayerStartPos);
        io.Write(m_PlayerStartRot);
    }

    if (m_Version >= 37)
    {
        io.Write(static_cast<uint32_t>(m_Scenes.size()));
    }
    else
    {
        io.Write(static_cast<uint8_t>(m_Scenes.size()));
    }

    for (const auto& scene : m_Scenes)
    {
        scene.Save(io, m_Version);
    }

    io.Write(static_cast<uint8_t>(m_BoundaryLines.size()));

    for (const auto& boundaryLine : m_BoundaryLines)
    {
        boundaryLine.Save(io, m_Version);
    }

    io.WriteString<uint8_t>(m_TerrainFilename);

    if (m_Version >= 31)
    {
        io.WriteString<uint8_t>(m_ZoneName);
        io.WriteString<uint8_t>(m_ZoneDescription);
    }

    if (m_Version >= 32)
    {
        m_TransitionInformation.Save(io, m_Version);
    }

    if (m_Version >= 35)
    {
        size_t head = io.GetWriteHead();

        io.Write(static_cast<uint32_t>(0));

        m_PathInformation.Save(io, m_Version);

        size_t head2 = io.GetWriteHead();

        io.SetWriteHead(head);

        const uint32_t pathChunkSize = head2 - head - sizeof(uint32_t);

        io.Write(pathChunkSize);
    }
}

version nejlika::world::Zone::GetVersion() const
{
    return m_Version;
}

uint32_t nejlika::world::Zone::GetFileRevision() const
{
    return m_FileRevision;
}

uint32_t nejlika::world::Zone::GetZoneID() const
{
    return m_ZoneID;
}

const vector3 &nejlika::world::Zone::GetPlayerStartPos() const
{
    return m_PlayerStartPos;
}

const vector4 &nejlika::world::Zone::GetPlayerStartRot() const
{
    return m_PlayerStartRot;
}

std::vector<nejlika::world::SceneReference> &nejlika::world::Zone::GetScenes()
{
    return m_Scenes;
}

std::vector<nejlika::world::BoundaryLine> &nejlika::world::Zone::GetBoundaryLines()
{
    return m_BoundaryLines;
}

std::string &nejlika::world::Zone::GetTerrainFilename()
{
    return m_TerrainFilename;
}

std::string &nejlika::world::Zone::GetTerrainName()
{
    return m_ZoneName;
}

std::string &nejlika::world::Zone::GetTerrainDescription()
{
    return m_ZoneDescription;
}

nejlika::world::TransitionInformation &nejlika::world::Zone::GetTransitionInformation()
{
    return m_TransitionInformation;
}

nejlika::world::PathInformation &nejlika::world::Zone::GetPathInformation()
{
    return m_PathInformation;
}

void nejlika::world::Zone::SetVersion(version version)
{
    m_Version = version;
}

void nejlika::world::Zone::SetFileRevision(uint32_t fileRevision)
{
    m_FileRevision = fileRevision;
}

void nejlika::world::Zone::SetZoneID(uint32_t zoneID)
{
    m_ZoneID = zoneID;
}

void nejlika::world::Zone::SetPlayerStartPos(const vector3 &playerStartPos)
{
    m_PlayerStartPos = playerStartPos;
}

void nejlika::world::Zone::SetPlayerStartRot(const vector4 &playerStartRot)
{
    m_PlayerStartRot = playerStartRot;
}

void nejlika::world::Zone::SetScenes(const std::vector<nejlika::world::SceneReference> &scenes)
{
    m_Scenes = scenes;
}

void nejlika::world::Zone::SetBoundaryLines(const std::vector<nejlika::world::BoundaryLine> &boundaryLines)
{
    m_BoundaryLines = boundaryLines;
}

void nejlika::world::Zone::SetTerrainFilename(const std::string &terrainFilename)
{
    m_TerrainFilename = terrainFilename;
}

void nejlika::world::Zone::SetTerrainName(const std::string &zoneName)
{
    m_ZoneName = zoneName;
}

void nejlika::world::Zone::SetTerrainDescription(const std::string &zoneDescription)
{
    m_ZoneDescription = zoneDescription;
}

void nejlika::world::Zone::SetTransitionInformation(const nejlika::world::TransitionInformation &transitionInformation)
{
    m_TransitionInformation = transitionInformation;
}

void nejlika::world::Zone::SetPathInformation(const nejlika::world::PathInformation &pathInformation)
{
    m_PathInformation = pathInformation;
}

nejlika::world::Zone::~Zone()
{
}

