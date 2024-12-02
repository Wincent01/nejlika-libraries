#include "NiPSFacingQuadGenerator.hpp"

using namespace nejlika::geometry;

void NiPSFacingQuadGenerator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1 = reader.Read<byte>();

    m_Unknown2 = reader.Read<byte>();

    m_Unknown3 = reader.Read<byte>();

    m_Unknown4 = reader.Read<byte>();

    m_Unknown5 = reader.Read<byte>();

    m_Unknown6 = reader.Read<byte>();

    m_Unknown7 = reader.Read<byte>();

    m_Unknown8 = reader.Read<byte>();

    m_Unknown9 = reader.Read<byte>();

    m_Unknown10 = reader.Read<byte>();

    m_Unknown11 = reader.Read<byte>();

    m_Unknown12 = reader.Read<byte>();

}

void NiPSFacingQuadGenerator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_Unknown1);

    writer.Write(m_Unknown2);

    writer.Write(m_Unknown3);

    writer.Write(m_Unknown4);

    writer.Write(m_Unknown5);

    writer.Write(m_Unknown6);

    writer.Write(m_Unknown7);

    writer.Write(m_Unknown8);

    writer.Write(m_Unknown9);

    writer.Write(m_Unknown10);

    writer.Write(m_Unknown11);

    writer.Write(m_Unknown12);

}
