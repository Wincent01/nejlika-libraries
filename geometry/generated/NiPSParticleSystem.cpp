#include "NiPSParticleSystem.hpp"

using namespace nejlika::geometry;

void NiPSParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_Unknown3 = reader.Read<int>();

    m_Unknown38.resize(m_Unknown3);
    for (uint32_t i = 0; i < m_Unknown38.size(); i++)
    {
        m_Unknown38[i] = reader.Read<int>();
    }

    m_Unknown4 = reader.Read<int>();

    m_Unknown5 = reader.Read<int>();

    m_Unknown39.resize(m_Unknown3);
    for (uint32_t i = 0; i < m_Unknown39.size(); i++)
    {
        m_Unknown39[i] = reader.Read<int>();
    }

    m_Unknown6 = reader.Read<int>();

    m_Unknown7 = reader.Read<int>();

    m_Unknown8 = reader.Read<int>();

    m_Unknown9 = reader.Read<int>();

    m_Unknown10 = reader.Read<float>();

    m_Unknown11 = reader.Read<int>();

    m_Unknown12 = reader.Read<int>();

    m_Simulator.Read(reader, version, user, 0);

    if (m_Unknown12> 1)
    {
        m_Generator.Read(reader, version, user, 0);
    }

    m_Unknown15 = reader.Read<int>();

    m_Unknown16 = reader.Read<int>();

    m_Unknown17 = reader.Read<int>();

    m_Emitter.Read(reader, version, user, 0);

    m_Unknown19 = reader.Read<int>();

    m_Unknown20 = reader.Read<int>();

    m_Unknown21 = reader.Read<int>();

    m_Unknown22.resize(4);
    for (uint32_t i = 0; i < m_Unknown22.size(); i++)
    {
        m_Unknown22[i] = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown27 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown28 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown29 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown30 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown31 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown32 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown33 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown34 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown35 = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown36 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_Unknown37 = reader.Read<short>();
    }

}

void NiPSParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    writer.Write(m_Unknown3);

    for (uint32_t i = 0; i < m_Unknown38.size(); i++)
    {
        writer.Write(m_Unknown38[i]);
    }

    writer.Write(m_Unknown4);

    writer.Write(m_Unknown5);

    for (uint32_t i = 0; i < m_Unknown39.size(); i++)
    {
        writer.Write(m_Unknown39[i]);
    }

    writer.Write(m_Unknown6);

    writer.Write(m_Unknown7);

    writer.Write(m_Unknown8);

    writer.Write(m_Unknown9);

    writer.Write(m_Unknown10);

    writer.Write(m_Unknown11);

    writer.Write(m_Unknown12);

    m_Simulator.Write(writer, version, user, 0);

    if (m_Unknown12> 1)
    {
        m_Generator.Write(writer, version, user, 0);
    }

    writer.Write(m_Unknown15);

    writer.Write(m_Unknown16);

    writer.Write(m_Unknown17);

    m_Emitter.Write(writer, version, user, 0);

    writer.Write(m_Unknown19);

    writer.Write(m_Unknown20);

    writer.Write(m_Unknown21);

    for (uint32_t i = 0; i < m_Unknown22.size(); i++)
    {
        writer.Write(m_Unknown22[i]);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown27);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown28);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown29);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown30);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown31);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown32);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown33);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown34);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown35);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown36);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_Unknown37);
    }

}
