#include "CullData.hpp"

using namespace nejlika::world;

nejlika::world::CullData::CullData(uint32_t groupId, float maxDistance, float minDistance)
{
    m_GroupId = groupId;

    m_MaxDistance = maxDistance;

    m_MinDistance = minDistance;
}

nejlika::world::CullData::CullData(nejlika::Reader &io)
{
    m_GroupId = io.Read<uint32_t>();

    m_MaxDistance = io.Read<float>();

    m_MinDistance = io.Read<float>();
}

void nejlika::world::CullData::Save(nejlika::Writer &io) const
{
    io.Write(m_GroupId);

    io.Write(m_MaxDistance);

    io.Write(m_MinDistance);
}

const uint32_t nejlika::world::CullData::GetGroupId() const
{
    return m_GroupId;
}

const float nejlika::world::CullData::GetMaxDistance() const
{
    return m_MaxDistance;
}

const float nejlika::world::CullData::GetMinDistance() const
{
    return m_MinDistance;
}

nejlika::world::CullData::~CullData()
{
}
