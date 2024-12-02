#include "bhkMeshShape.hpp"

using namespace nejlika::geometry;

void bhkMeshShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShape::Read(reader, version, user, arg);

    m_Unknown1.resize(9);
    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        m_Unknown1[i] = reader.Read<float>();
    }

    m_NumUnknownFloats = reader.Read<int>();

    m_UnknownFloats.resize(m_NumUnknownFloats);
    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        m_UnknownFloats[i].resize(3);
        for (uint32_t j = 0; j < m_UnknownFloats[i].size(); j++)
        {
            m_UnknownFloats[i][j] = reader.Read<float>();
        }
    }

    m_Unknown2.resize(3);
    for (uint32_t i = 0; i < m_Unknown2.size(); i++)
    {
        m_Unknown2[i] = reader.Read<int>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_NumStripsData = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_StripsData.resize(m_NumStripsData);
        for (uint32_t i = 0; i < m_StripsData.size(); i++)
        {
            m_StripsData[i].Read(reader, version, user, 0);
        }
    }

}

void bhkMeshShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShape::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        writer.Write(m_Unknown1[i]);
    }

    writer.Write(m_NumUnknownFloats);

    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        for (uint32_t j = 0; j < m_UnknownFloats[i].size(); j++)
        {
            writer.Write(m_UnknownFloats[i][j]);
        }
    }

    for (uint32_t i = 0; i < m_Unknown2.size(); i++)
    {
        writer.Write(m_Unknown2[i]);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_NumStripsData);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_StripsData.size(); i++)
        {
            m_StripsData[i].Write(writer, version, user, 0);
        }
    }

}
