#include "NiPSBombForce.hpp"

using namespace nejlika::geometry;

void NiPSBombForce::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_Unknown1 = reader.Read<byte>();

    m_Unknown2 = reader.Read<int>();

    m_Unknown3 = reader.Read<int>();

    m_Unknown4 = reader.Read<int>();

    m_Unknown5 = reader.Read<int>();

    m_Unknown6 = reader.Read<int>();

    m_Unknown7 = reader.Read<int>();

    m_Unknown8 = reader.Read<int>();

    m_Unknown9 = reader.Read<int>();

    m_Unknown10 = reader.Read<int>();

}

void NiPSBombForce::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

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
