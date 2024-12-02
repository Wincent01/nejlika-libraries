#include "NiPathInterpolator.hpp"

using namespace nejlika::geometry;

void NiPathInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyBasedInterpolator::Read(reader, version, user, arg);

    m_UnknownShort = reader.Read<ushort>();

    m_UnknownInt = reader.Read<uint>();

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownShort2 = reader.Read<ushort>();

    m_PosData.Read(reader, version, user, 0);

    m_FloatData.Read(reader, version, user, 0);

}

void NiPathInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyBasedInterpolator::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort);

    writer.Write(m_UnknownInt);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownShort2);

    m_PosData.Write(writer, version, user, 0);

    m_FloatData.Write(writer, version, user, 0);

}
