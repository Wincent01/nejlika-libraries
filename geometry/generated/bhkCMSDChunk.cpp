#include "bhkCMSDChunk.hpp"

using namespace nejlika::geometry;

void bhkCMSDChunk::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Translation.Read(reader, version, user, 0);

    m_MaterialIndex = reader.Read<uint>();

    m_UnknownShort1 = reader.Read<ushort>();

    m_TransformIndex = reader.Read<ushort>();

    m_NumVertices = reader.Read<uint>();

    m_Vertices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i] = reader.Read<ushort>();
    }

    m_NumIndices = reader.Read<uint>();

    m_Indices.resize(m_NumIndices);
    for (uint32_t i = 0; i < m_Indices.size(); i++)
    {
        m_Indices[i] = reader.Read<ushort>();
    }

    m_NumStrips = reader.Read<uint>();

    m_Strips.resize(m_NumStrips);
    for (uint32_t i = 0; i < m_Strips.size(); i++)
    {
        m_Strips[i] = reader.Read<ushort>();
    }

    m_NumIndices2 = reader.Read<uint>();

    m_Indices2.resize(m_NumIndices2);
    for (uint32_t i = 0; i < m_Indices2.size(); i++)
    {
        m_Indices2[i] = reader.Read<ushort>();
    }

}

void bhkCMSDChunk::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Translation.Write(writer, version, user, 0);

    writer.Write(m_MaterialIndex);

    writer.Write(m_UnknownShort1);

    writer.Write(m_TransformIndex);

    writer.Write(m_NumVertices);

    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        writer.Write(m_Vertices[i]);
    }

    writer.Write(m_NumIndices);

    for (uint32_t i = 0; i < m_Indices.size(); i++)
    {
        writer.Write(m_Indices[i]);
    }

    writer.Write(m_NumStrips);

    for (uint32_t i = 0; i < m_Strips.size(); i++)
    {
        writer.Write(m_Strips[i]);
    }

    writer.Write(m_NumIndices2);

    for (uint32_t i = 0; i < m_Indices2.size(); i++)
    {
        writer.Write(m_Indices2[i]);
    }

}
