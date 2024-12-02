#include "bhkCompressedMeshShapeData.hpp"

using namespace nejlika::geometry;

void bhkCompressedMeshShapeData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkRefObject::Read(reader, version, user, arg);

    m_BitsPerIndex = reader.Read<uint>();

    m_BitsPerWIndex = reader.Read<uint>();

    m_MaskWIndex = reader.Read<uint>();

    m_MaskIndex = reader.Read<uint>();

    m_Error = reader.Read<float>();

    m_BoundsMin.Read(reader, version, user, 0);

    m_BoundsMax.Read(reader, version, user, 0);

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownInt3 = reader.Read<uint>();

    m_UnknownInt4 = reader.Read<uint>();

    m_UnknownInt5 = reader.Read<uint>();

    m_UnknownByte2 = reader.Read<byte>();

    m_NumMaterials = reader.Read<uint>();

    m_ChunkMaterials.resize(m_NumMaterials);
    for (uint32_t i = 0; i < m_ChunkMaterials.size(); i++)
    {
        m_ChunkMaterials[i].Read(reader, version, user, 0);
    }

    m_UnknownInt6 = reader.Read<uint>();

    m_NumTransforms = reader.Read<uint>();

    m_ChunkTransforms.resize(m_NumTransforms);
    for (uint32_t i = 0; i < m_ChunkTransforms.size(); i++)
    {
        m_ChunkTransforms[i].Read(reader, version, user, 0);
    }

    m_NumBigVerts = reader.Read<uint>();

    m_BigVerts.resize(m_NumBigVerts);
    for (uint32_t i = 0; i < m_BigVerts.size(); i++)
    {
        m_BigVerts[i].Read(reader, version, user, 0);
    }

    m_NumBigTris = reader.Read<uint>();

    m_BigTris.resize(m_NumBigTris);
    for (uint32_t i = 0; i < m_BigTris.size(); i++)
    {
        m_BigTris[i].Read(reader, version, user, 0);
    }

    m_NumChunks = reader.Read<uint>();

    m_Chunks.resize(m_NumChunks);
    for (uint32_t i = 0; i < m_Chunks.size(); i++)
    {
        m_Chunks[i].Read(reader, version, user, 0);
    }

    m_UnknownInt12 = reader.Read<uint>();

}

void bhkCompressedMeshShapeData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkRefObject::Write(writer, version, user, arg);

    writer.Write(m_BitsPerIndex);

    writer.Write(m_BitsPerWIndex);

    writer.Write(m_MaskWIndex);

    writer.Write(m_MaskIndex);

    writer.Write(m_Error);

    m_BoundsMin.Write(writer, version, user, 0);

    m_BoundsMax.Write(writer, version, user, 0);

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownInt3);

    writer.Write(m_UnknownInt4);

    writer.Write(m_UnknownInt5);

    writer.Write(m_UnknownByte2);

    writer.Write(m_NumMaterials);

    for (uint32_t i = 0; i < m_ChunkMaterials.size(); i++)
    {
        m_ChunkMaterials[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt6);

    writer.Write(m_NumTransforms);

    for (uint32_t i = 0; i < m_ChunkTransforms.size(); i++)
    {
        m_ChunkTransforms[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumBigVerts);

    for (uint32_t i = 0; i < m_BigVerts.size(); i++)
    {
        m_BigVerts[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumBigTris);

    for (uint32_t i = 0; i < m_BigTris.size(); i++)
    {
        m_BigTris[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumChunks);

    for (uint32_t i = 0; i < m_Chunks.size(); i++)
    {
        m_Chunks[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt12);

}
