#include "CameraWaypointData.hpp"

nejlika::world::CameraWaypointData::CameraWaypointData(nejlika::Reader &io, version version)
{
    m_Rotation = io.Read<vector4>();

    m_Time = io.Read<float>();

    m_Fov = io.Read<float>();

    m_Tension = io.Read<float>();

    m_Continuity = io.Read<float>();

    m_Bias = io.Read<float>();
}

nejlika::world::CameraWaypointData::CameraWaypointData()
{
}

void nejlika::world::CameraWaypointData::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_Rotation);

    io.Write(m_Time);

    io.Write(m_Fov);

    io.Write(m_Tension);

    io.Write(m_Continuity);

    io.Write(m_Bias);
}

const vector4 &nejlika::world::CameraWaypointData::GetRotation() const
{
    return m_Rotation;
}

float nejlika::world::CameraWaypointData::GetTime() const
{
    return m_Time;
}

float nejlika::world::CameraWaypointData::GetFov() const
{
    return m_Fov;
}

float nejlika::world::CameraWaypointData::GetTension() const
{
    return m_Tension;
}

float nejlika::world::CameraWaypointData::GetContinuity() const
{
    return m_Continuity;
}

float nejlika::world::CameraWaypointData::GetBias() const
{
    return m_Bias;
}

void nejlika::world::CameraWaypointData::SetRotation(const vector4 &rotation)
{
    m_Rotation = rotation;
}

void nejlika::world::CameraWaypointData::SetTime(float time)
{
    m_Time = time;
}

void nejlika::world::CameraWaypointData::SetFov(float fov)
{
    m_Fov = fov;
}

void nejlika::world::CameraWaypointData::SetTension(float tension)
{
    m_Tension = tension;
}

void nejlika::world::CameraWaypointData::SetContinuity(float continuity)
{
    m_Continuity = continuity;
}

void nejlika::world::CameraWaypointData::SetBias(float bias)
{
    m_Bias = bias;
}

nejlika::world::CameraWaypointData::~CameraWaypointData()
{
}
