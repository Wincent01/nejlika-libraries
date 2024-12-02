#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "PathKeyValuePairs.hpp"

namespace nejlika::world
{

class RailWaypointData : public WorldSerialize
{
public:
    RailWaypointData(nejlika::Reader& io, version version);

    RailWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const vector4& GetRotation() const;

    float GetSpeed() const;

    const PathKeyValuePairs& GetConfig() const;

    ~RailWaypointData();

private:
    vector4 m_Rotation;

    float m_Speed;

    PathKeyValuePairs m_Config;
};

}