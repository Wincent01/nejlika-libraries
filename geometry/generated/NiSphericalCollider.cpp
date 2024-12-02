#include "NiSphericalCollider.hpp"

using namespace nejlika::geometry;

void NiSphericalCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownShort1 = reader.Read<ushort>();

    m_UnknownFloat2 = reader.Read<float>();

    if (version <= VERSION_NUMBER(4, 2, 0, 2))
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        m_UnknownFloat3 = reader.Read<float>();
    }

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownFloat5 = reader.Read<float>();

}

void NiSphericalCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownFloat2);

    if (version <= VERSION_NUMBER(4, 2, 0, 2))
    {
        writer.Write(m_UnknownShort2);
    }

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        writer.Write(m_UnknownFloat3);
    }

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownFloat5);

}
