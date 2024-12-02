#include "NiPhysXMeshDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXMeshDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownShort1 = reader.Read<short>();

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownShort2 = reader.Read<short>();

    m_UnknownBytes0.resize(3);
    for (uint32_t i = 0; i < m_UnknownBytes0.size(); i++)
    {
        m_UnknownBytes0[i] = reader.Read<byte>();
    }

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownBytes1.resize(4);
    for (uint32_t i = 0; i < m_UnknownBytes1.size(); i++)
    {
        m_UnknownBytes1[i] = reader.Read<byte>();
    }

    m_UnknownBytes2.resize(8);
    for (uint32_t i = 0; i < m_UnknownBytes2.size(); i++)
    {
        m_UnknownBytes2[i] = reader.Read<byte>();
    }

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_NumVertices = reader.Read<int>();

    m_UnknownInt4 = reader.Read<int>();

    m_Vertices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Read(reader, version, user, 0);
    }

    m_UnknownBytes3.resize(982);
    for (uint32_t i = 0; i < m_UnknownBytes3.size(); i++)
    {
        m_UnknownBytes3[i] = reader.Read<byte>();
    }

    m_UnknownShorts1.resize(368);
    for (uint32_t i = 0; i < m_UnknownShorts1.size(); i++)
    {
        m_UnknownShorts1[i] = reader.Read<short>();
    }

    m_UnknownInts1.resize(3328);
    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        m_UnknownInts1[i] = reader.Read<uint>();
    }

    m_UnknownByte2 = reader.Read<byte>();

}

void NiPhysXMeshDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownShort2);

    for (uint32_t i = 0; i < m_UnknownBytes0.size(); i++)
    {
        writer.Write(m_UnknownBytes0[i]);
    }

    writer.Write(m_UnknownByte1);

    for (uint32_t i = 0; i < m_UnknownBytes1.size(); i++)
    {
        writer.Write(m_UnknownBytes1[i]);
    }

    for (uint32_t i = 0; i < m_UnknownBytes2.size(); i++)
    {
        writer.Write(m_UnknownBytes2[i]);
    }

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_NumVertices);

    writer.Write(m_UnknownInt4);

    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_UnknownBytes3.size(); i++)
    {
        writer.Write(m_UnknownBytes3[i]);
    }

    for (uint32_t i = 0; i < m_UnknownShorts1.size(); i++)
    {
        writer.Write(m_UnknownShorts1[i]);
    }

    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        writer.Write(m_UnknownInts1[i]);
    }

    writer.Write(m_UnknownByte2);

}
