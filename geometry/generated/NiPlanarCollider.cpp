#include "NiPlanarCollider.hpp"

using namespace nejlika::geometry;

void NiPlanarCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_UnknownShort = reader.Read<ushort>();
    }

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownFloat5 = reader.Read<float>();

    m_UnknownFloat6 = reader.Read<float>();

    m_UnknownFloat7 = reader.Read<float>();

    m_UnknownFloat8 = reader.Read<float>();

    m_UnknownFloat9 = reader.Read<float>();

    m_UnknownFloat10 = reader.Read<float>();

    m_UnknownFloat11 = reader.Read<float>();

    m_UnknownFloat12 = reader.Read<float>();

    m_UnknownFloat13 = reader.Read<float>();

    m_UnknownFloat14 = reader.Read<float>();

    m_UnknownFloat15 = reader.Read<float>();

    m_UnknownFloat16 = reader.Read<float>();

}

void NiPlanarCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_UnknownShort);
    }

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_UnknownShort2);
    }

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownFloat5);

    writer.Write(m_UnknownFloat6);

    writer.Write(m_UnknownFloat7);

    writer.Write(m_UnknownFloat8);

    writer.Write(m_UnknownFloat9);

    writer.Write(m_UnknownFloat10);

    writer.Write(m_UnknownFloat11);

    writer.Write(m_UnknownFloat12);

    writer.Write(m_UnknownFloat13);

    writer.Write(m_UnknownFloat14);

    writer.Write(m_UnknownFloat15);

    writer.Write(m_UnknownFloat16);

}
