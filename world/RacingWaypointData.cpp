#include "RacingWaypointData.hpp"

nejlika::world::RacingWaypointData::RacingWaypointData(nejlika::Reader &io, version version)
{
    m_Rotation = io.Read<vector4>();

    m_IsResetNode = io.Read<bool>();

    m_IsNonHorizontalCamera = io.Read<bool>();

    m_PlaneWidth = io.Read<float>();

    m_PlaneHeight = io.Read<float>();

    m_ShortestDistanceToEnd = io.Read<float>();
}

nejlika::world::RacingWaypointData::RacingWaypointData()
{
}

void nejlika::world::RacingWaypointData::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_Rotation);

    io.Write(m_IsResetNode);

    io.Write(m_IsNonHorizontalCamera);

    io.Write(m_PlaneWidth);

    io.Write(m_PlaneHeight);

    io.Write(m_ShortestDistanceToEnd);
}

const vector4 &nejlika::world::RacingWaypointData::GetRotation() const
{
    return m_Rotation;
}

bool nejlika::world::RacingWaypointData::IsResetNode() const
{
    return m_IsResetNode;
}

bool nejlika::world::RacingWaypointData::IsNonHorizontalCamera() const
{
    return m_IsNonHorizontalCamera;
}

float nejlika::world::RacingWaypointData::GetPlaneWidth() const
{
    return m_PlaneWidth;
}

float nejlika::world::RacingWaypointData::GetPlaneHeight() const
{
    return m_PlaneHeight;
}

float nejlika::world::RacingWaypointData::GetShortestDistanceToEnd() const
{
    return m_ShortestDistanceToEnd;
}

nejlika::world::RacingWaypointData::~RacingWaypointData()
{
}
