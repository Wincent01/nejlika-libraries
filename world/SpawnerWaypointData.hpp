#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "PathKeyValuePairs.hpp"

namespace nejlika::world
{

class SpawnerWaypointData : public WorldSerialize
{
public:
    SpawnerWaypointData(nejlika::Reader& io, version version);

    SpawnerWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const vector4& GetRotation() const;

    const PathKeyValuePairs& GetConfig() const;

    void SetRotation(const vector4& rotation);

    PathKeyValuePairs& GetConfig();

    ~SpawnerWaypointData();

private:
    vector4 m_Rotation;

    PathKeyValuePairs m_Config;
};

}