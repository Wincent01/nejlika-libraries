#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"

namespace nejlika::world
{

class BoundaryLine
{
public:
    BoundaryLine(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    const vector3& GetNormal() const;

    const vector3& GetPoint() const;

    uint32_t GetDestinationZoneID() const;

    uint32_t GetDestinationSceneID() const;

    const vector3& GetSpawnLocation() const;

    ~BoundaryLine();

private:
    vector3 m_Normal;

    vector3 m_Point;

    uint32_t m_DestinationZoneID;

    uint32_t m_DestinationSceneID;

    vector3 m_SpawnLocation;
};

}