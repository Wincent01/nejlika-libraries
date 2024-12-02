#include "NiPSDragForce.hpp"

using namespace nejlika::geometry;

void NiPSDragForce::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1 = reader.Read<int>();

    m_Unknown2 = reader.Read<int>();

    m_Unknown3 = reader.Read<byte>();

    m_Unknown4 = reader.Read<float>();

    m_Unknown5 = reader.Read<float>();

    m_Unknown6 = reader.Read<float>();

    m_Unknown7 = reader.Read<float>();

    m_Unknown8 = reader.Read<float>();

    m_Unknown9 = reader.Read<float>();

    m_Unknown10 = reader.Read<int>();

}

void NiPSDragForce::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
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

}
