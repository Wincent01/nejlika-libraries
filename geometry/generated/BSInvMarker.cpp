#include "BSInvMarker.hpp"

using namespace nejlika::geometry;

void BSInvMarker::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_RotationX = reader.Read<ushort>();

    m_RotationY = reader.Read<ushort>();

    m_RotationZ = reader.Read<ushort>();

    m_Zoom = reader.Read<float>();

}

void BSInvMarker::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_RotationX);

    writer.Write(m_RotationY);

    writer.Write(m_RotationZ);

    writer.Write(m_Zoom);

}
