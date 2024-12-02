#include "NiPSGravityForce.hpp"

using namespace nejlika::geometry;

void NiPSGravityForce::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
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

    m_Unknown13 = reader.Read<byte>();

    m_Unknown14 = reader.Read<byte>();

    m_Unknown15 = reader.Read<byte>();

    m_Unknown16 = reader.Read<byte>();

    m_Unknown17 = reader.Read<byte>();

    m_Unknown18 = reader.Read<float>();

    m_Unknown19 = reader.Read<byte>();

    m_Unknown20 = reader.Read<byte>();

    m_Unknown21 = reader.Read<byte>();

    m_Unknown22 = reader.Read<byte>();

    m_Unknown23 = reader.Read<byte>();

    m_Unknown24 = reader.Read<byte>();

    m_Unknown25 = reader.Read<byte>();

    m_Unknown26 = reader.Read<byte>();

    m_Unknown27 = reader.Read<byte>();

    m_Unknown28 = reader.Read<byte>();

    m_Unknown29 = reader.Read<byte>();

    m_Unknown30 = reader.Read<byte>();

    m_Unknown31 = reader.Read<byte>();

    m_Unknown32 = reader.Read<byte>();

    m_Unknown33 = reader.Read<byte>();

    m_Unknown34 = reader.Read<byte>();

    m_Unknown35 = reader.Read<float>();

    m_Unknown36.Read(reader, version, user, 0);

}

void NiPSGravityForce::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
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

    writer.Write(m_Unknown13);

    writer.Write(m_Unknown14);

    writer.Write(m_Unknown15);

    writer.Write(m_Unknown16);

    writer.Write(m_Unknown17);

    writer.Write(m_Unknown18);

    writer.Write(m_Unknown19);

    writer.Write(m_Unknown20);

    writer.Write(m_Unknown21);

    writer.Write(m_Unknown22);

    writer.Write(m_Unknown23);

    writer.Write(m_Unknown24);

    writer.Write(m_Unknown25);

    writer.Write(m_Unknown26);

    writer.Write(m_Unknown27);

    writer.Write(m_Unknown28);

    writer.Write(m_Unknown29);

    writer.Write(m_Unknown30);

    writer.Write(m_Unknown31);

    writer.Write(m_Unknown32);

    writer.Write(m_Unknown33);

    writer.Write(m_Unknown34);

    writer.Write(m_Unknown35);

    m_Unknown36.Write(writer, version, user, 0);

}
