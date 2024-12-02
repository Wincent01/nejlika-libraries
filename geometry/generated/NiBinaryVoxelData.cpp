#include "NiBinaryVoxelData.hpp"

using namespace nejlika::geometry;

void NiBinaryVoxelData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownShort1 = reader.Read<ushort>();

    m_UnknownShort2 = reader.Read<ushort>();

    m_UnknownShort3 = reader.Read<ushort>();

    m_Unknown7Floats.resize(7);
    for (uint32_t i = 0; i < m_Unknown7Floats.size(); i++)
    {
        m_Unknown7Floats[i] = reader.Read<float>();
    }

    m_UnknownBytes1.resize(7);
    for (uint32_t i = 0; i < m_UnknownBytes1.size(); i++)
    {
        m_UnknownBytes1[i].resize(12);
        for (uint32_t j = 0; j < m_UnknownBytes1[i].size(); j++)
        {
            m_UnknownBytes1[i][j] = reader.Read<byte>();
        }
    }

    m_NumUnknownVectors = reader.Read<uint>();

    m_UnknownVectors.resize(m_NumUnknownVectors);
    for (uint32_t i = 0; i < m_UnknownVectors.size(); i++)
    {
        m_UnknownVectors[i].Read(reader, version, user, 0);
    }

    m_NumUnknownBytes2 = reader.Read<uint>();

    m_UnknownBytes2.resize(m_NumUnknownBytes2);
    for (uint32_t i = 0; i < m_UnknownBytes2.size(); i++)
    {
        m_UnknownBytes2[i] = reader.Read<byte>();
    }

    m_Unknown5Ints.resize(5);
    for (uint32_t i = 0; i < m_Unknown5Ints.size(); i++)
    {
        m_Unknown5Ints[i] = reader.Read<uint>();
    }

}

void NiBinaryVoxelData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownShort2);

    writer.Write(m_UnknownShort3);

    for (uint32_t i = 0; i < m_Unknown7Floats.size(); i++)
    {
        writer.Write(m_Unknown7Floats[i]);
    }

    for (uint32_t i = 0; i < m_UnknownBytes1.size(); i++)
    {
        for (uint32_t j = 0; j < m_UnknownBytes1[i].size(); j++)
        {
            writer.Write(m_UnknownBytes1[i][j]);
        }
    }

    writer.Write(m_NumUnknownVectors);

    for (uint32_t i = 0; i < m_UnknownVectors.size(); i++)
    {
        m_UnknownVectors[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumUnknownBytes2);

    for (uint32_t i = 0; i < m_UnknownBytes2.size(); i++)
    {
        writer.Write(m_UnknownBytes2[i]);
    }

    for (uint32_t i = 0; i < m_Unknown5Ints.size(); i++)
    {
        writer.Write(m_Unknown5Ints[i]);
    }

}
