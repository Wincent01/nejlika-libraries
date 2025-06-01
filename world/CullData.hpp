#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

namespace nejlika::world
{

class CullData
{
public:
    CullData() = default;

    CullData(uint32_t groupId, float maxDistance, float minDistance);

    CullData(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const uint32_t GetGroupId() const;

    const float GetMaxDistance() const;

    const float GetMinDistance() const;

    ~CullData();

private:
    uint32_t m_GroupId;
    float m_MaxDistance;
    float m_MinDistance;
};

}