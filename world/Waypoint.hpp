#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "NpcWaypointData.hpp"
#include "PlatformWayointData.hpp"
#include "CameraWaypointData.hpp"
#include "SpawnerWaypointData.hpp"
#include "RacingWaypointData.hpp"
#include "RailWaypointData.hpp"

namespace nejlika::world
{

class Waypoint
{
public:
    Waypoint(nejlika::Reader& io, version version, PathType pathType);

    Waypoint(const vector3& position, PathType pathType);

    Waypoint(const Waypoint& other);

    void Save(nejlika::Writer& io, version version, PathType pathType) const;

    const vector3& GetPosition() const;

    template<typename T>
    T& GetData() const {
        return *dynamic_cast<T*>(m_Data.get());
    }

    ~Waypoint();

private:
    vector3 m_Position;

    PathType m_PathType;

    std::unique_ptr<WorldSerialize> m_Data;
};

}