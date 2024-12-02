#include "CameraData.hpp"

nejlika::world::CameraData::CameraData(nejlika::Reader &io, version version)
{
    m_NextPath = io.ReadString16<uint8_t>();

    m_RotatePlayer = version >= 14 ? io.Read<bool>() : false;
}

nejlika::world::CameraData::CameraData()
{
}

void nejlika::world::CameraData::Save(nejlika::Writer &io, version version) const
{
    io.WriteString16<uint8_t>(m_NextPath);

    if (version >= 14)
    {
        io.Write(m_RotatePlayer);
    }
}

const str16 &nejlika::world::CameraData::GetNextPath() const
{
    return m_NextPath;
}

bool nejlika::world::CameraData::GetRotatePlayer() const
{
    return m_RotatePlayer;
}

void nejlika::world::CameraData::SetNextPath(const str16 &nextPath)
{
    m_NextPath = nextPath;
}

void nejlika::world::CameraData::SetRotatePlayer(bool rotatePlayer)
{
    m_RotatePlayer = rotatePlayer;
}

nejlika::world::CameraData::~CameraData()
{
}