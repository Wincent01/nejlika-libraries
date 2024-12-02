#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "PathKeyValuePairs.hpp"

namespace nejlika::world
{

class NpcWaypointData : public WorldSerialize
{
public:
    NpcWaypointData(nejlika::Reader& io, version version);

    NpcWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const PathKeyValuePairs& GetConfig() const;

    ~NpcWaypointData();

private:
    PathKeyValuePairs m_Config;
};

}