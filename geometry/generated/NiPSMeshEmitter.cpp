#include "NiPSMeshEmitter.hpp"

using namespace nejlika::geometry;

void NiPSMeshEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_Unknown1 = reader.Read<int>();

    m_Unknown2 = reader.Read<int>();

    m_Unknown3 = reader.Read<int>();

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown27 = reader.Read<int>();
    }

    m_Unknown4 = reader.Read<float>();

    m_Unknown5 = reader.Read<float>();

    m_Unknown6 = reader.Read<float>();

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown28 = reader.Read<float>();
    }

    m_Unknown7 = reader.Read<int>();

    m_Unknown8 = reader.Read<float>();

    m_Unknown9 = reader.Read<float>();

    m_Unknown10 = reader.Read<float>();

    m_Unknown11 = reader.Read<float>();

    m_Unknown12 = reader.Read<float>();

    m_Unknown13 = reader.Read<int>();

    m_Unknown14 = reader.Read<float>();

    m_Unknown15 = reader.Read<float>();

    m_Unknown16 = reader.Read<float>();

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown17 = reader.Read<int>();
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown18 = reader.Read<int>();
    }

    m_Unknown19 = reader.Read<short>();

    m_Unknown20 = reader.Read<int>();

    m_Unknown21 = reader.Read<int>();

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown22 = reader.Read<float>();
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown23 = reader.Read<int>();
    }

    m_Unknown24 = reader.Read<int>();

    m_Unknown25 = reader.Read<int>();

    m_Unknown26 = reader.Read<int>();

}

void NiPSMeshEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    writer.Write(m_Unknown1);

    writer.Write(m_Unknown2);

    writer.Write(m_Unknown3);

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown27);
    }

    writer.Write(m_Unknown4);

    writer.Write(m_Unknown5);

    writer.Write(m_Unknown6);

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown28);
    }

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

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown17);
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown18);
    }

    writer.Write(m_Unknown19);

    writer.Write(m_Unknown20);

    writer.Write(m_Unknown21);

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown22);
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown23);
    }

    writer.Write(m_Unknown24);

    writer.Write(m_Unknown25);

    writer.Write(m_Unknown26);

}
