#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"

#include "SceneReference.hpp"
#include "BoundaryLine.hpp"
#include "TransitionInformation.hpp"
#include "PathInformation.hpp"

namespace nejlika::world {

class Zone
{
public:
    Zone() = default;

    Zone(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    version GetVersion() const;

    uint32_t GetFileRevision() const;

    uint32_t GetZoneID() const;

    const vector3& GetPlayerStartPos() const;

    const vector4& GetPlayerStartRot() const;

    std::vector<SceneReference>& GetScenes();

    std::vector<BoundaryLine>& GetBoundaryLines();

    std::string& GetTerrainFilename();

    std::string& GetTerrainName();

    std::string& GetTerrainDescription();

    TransitionInformation& GetTransitionInformation();

    PathInformation& GetPathInformation();

    void SetVersion(version version);

    void SetFileRevision(uint32_t fileRevision);

    void SetZoneID(uint32_t zoneID);

    void SetPlayerStartPos(const vector3& playerStartPos);

    void SetPlayerStartRot(const vector4& playerStartRot);

    void SetScenes(const std::vector<SceneReference>& scenes);

    void SetBoundaryLines(const std::vector<BoundaryLine>& boundaryLines);

    void SetTerrainFilename(const std::string& terrainFilename);

    void SetTerrainName(const std::string& zoneName);

    void SetTerrainDescription(const std::string& zoneDescription);

    void SetTransitionInformation(const TransitionInformation& transitionInformation);

    void SetPathInformation(const PathInformation& pathInformation);

    ~Zone();

private:
    uint32_t m_Version;

    uint32_t m_FileRevision;

    uint32_t m_ZoneID;

    vector3 m_PlayerStartPos;

    vector4 m_PlayerStartRot;

    std::vector<SceneReference> m_Scenes;

    std::vector<BoundaryLine> m_BoundaryLines;

    std::string m_TerrainFilename;

    std::string m_ZoneName;

    std::string m_ZoneDescription;

    TransitionInformation m_TransitionInformation;

    PathInformation m_PathInformation;
};


}
