#include "PlatformWayointData.hpp"

nejlika::world::PlatformWaypointData::PlatformWaypointData(nejlika::Reader &io, version version)
{
    m_Rotation = io.Read<vector4>();

    m_LockPlayer = io.Read<bool>();

    m_Speed = io.Read<float>();

    m_Wait = io.Read<float>();

    if (version >= 13)
    {
        m_DepartAudioGuid = io.ReadString16<uint8_t>();
        m_ArriveAudioGuid = io.ReadString16<uint8_t>();
    }
}

nejlika::world::PlatformWaypointData::PlatformWaypointData()
{
}

void nejlika::world::PlatformWaypointData::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_Rotation);

    io.Write(m_LockPlayer);

    io.Write(m_Speed);

    io.Write(m_Wait);

    if (version >= 13)
    {
        io.WriteString16<uint8_t>(m_DepartAudioGuid);
        io.WriteString16<uint8_t>(m_ArriveAudioGuid);
    }
}

const vector4 &nejlika::world::PlatformWaypointData::GetRotation() const
{
    return m_Rotation;
}

bool nejlika::world::PlatformWaypointData::GetLockPlayer() const
{
    return m_LockPlayer;
}

float nejlika::world::PlatformWaypointData::GetSpeed() const
{
    return m_Speed;
}

float nejlika::world::PlatformWaypointData::GetWait() const
{
    return m_Wait;
}

const str16 &nejlika::world::PlatformWaypointData::GetDepartAudioGuid() const
{
    return m_DepartAudioGuid;
}

const str16 &nejlika::world::PlatformWaypointData::GetArriveAudioGuid() const
{
    return m_ArriveAudioGuid;
}

nejlika::world::PlatformWaypointData::~PlatformWaypointData()
{
}
