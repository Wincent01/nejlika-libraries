#include "SkinPartition.hpp"

using namespace nejlika::geometry;

void SkinPartition::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumVertices = reader.Read<ushort>();

    m_NumTriangles = reader.Read<ushort>();

    m_NumBones = reader.Read<ushort>();

    m_NumStrips = reader.Read<ushort>();

    m_NumWeightsPerVertex = reader.Read<ushort>();

    m_Bones.resize(m_NumBones);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i] = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasVertexMap = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_VertexMap.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexMap.size(); i++)
        {
            m_VertexMap[i] = reader.Read<ushort>();
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasVertexMap)
    {
        m_VertexMap.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexMap.size(); i++)
        {
            m_VertexMap[i] = reader.Read<ushort>();
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasVertexWeights = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_VertexWeights.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].resize(m_NumWeightsPerVertex);
            for (uint32_t j = 0; j < m_VertexWeights[i].size(); j++)
            {
                m_VertexWeights[i][j] = reader.Read<float>();
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasVertexWeights)
    {
        m_VertexWeights.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].resize(m_NumWeightsPerVertex);
            for (uint32_t j = 0; j < m_VertexWeights[i].size(); j++)
            {
                m_VertexWeights[i][j] = reader.Read<float>();
            }
        }
    }

    m_StripLengths.resize(m_NumStrips);
    for (uint32_t i = 0; i < m_StripLengths.size(); i++)
    {
        m_StripLengths[i] = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasFaces = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2) && m_NumStrips!= 0)
    {
        m_Strips.resize(m_NumStrips);
        for (uint32_t i = 0; i < m_Strips.size(); i++)
        {
            m_Strips[i].resize(m_StripLengths[i]);
            for (uint32_t j = 0; j < m_Strips[i].size(); j++)
            {
                m_Strips[i][j] = reader.Read<ushort>();
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasFaces) && (m_NumStrips!= 0))
    {
        m_Strips.resize(m_NumStrips);
        for (uint32_t i = 0; i < m_Strips.size(); i++)
        {
            m_Strips[i].resize(m_StripLengths[i]);
            for (uint32_t j = 0; j < m_Strips[i].size(); j++)
            {
                m_Strips[i][j] = reader.Read<ushort>();
            }
        }
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2) && m_NumStrips== 0)
    {
        m_Triangles.resize(m_NumTriangles);
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasFaces) && (m_NumStrips== 0))
    {
        m_Triangles.resize(m_NumTriangles);
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Read(reader, version, user, 0);
        }
    }

    m_HasBoneIndices = reader.Read<bool>();

    if (m_HasBoneIndices)
    {
        m_BoneIndices.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_BoneIndices.size(); i++)
        {
            m_BoneIndices[i].resize(m_NumWeightsPerVertex);
            for (uint32_t j = 0; j < m_BoneIndices[i].size(); j++)
            {
                m_BoneIndices[i][j] = reader.Read<byte>();
            }
        }
    }

    if (user>= 12)
    {
        m_UnknownShort = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_Unknown83C3 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_Unknown00001 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_NumVertices2 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_Unknown00002 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_Unknown00003 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_Unknown00004 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        m_UnknownArr1.resize(m_NumVertices2);
        for (uint32_t i = 0; i < m_UnknownArr1.size(); i++)
        {
            m_UnknownArr1[i].Read(reader, version, user, 0);
        }
    }

}

void SkinPartition::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumVertices);

    writer.Write(m_NumTriangles);

    writer.Write(m_NumBones);

    writer.Write(m_NumStrips);

    writer.Write(m_NumWeightsPerVertex);

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        writer.Write(m_Bones[i]);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasVertexMap);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        for (uint32_t i = 0; i < m_VertexMap.size(); i++)
        {
            writer.Write(m_VertexMap[i]);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasVertexMap)
    {
        for (uint32_t i = 0; i < m_VertexMap.size(); i++)
        {
            writer.Write(m_VertexMap[i]);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasVertexWeights);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            for (uint32_t j = 0; j < m_VertexWeights[i].size(); j++)
            {
                writer.Write(m_VertexWeights[i][j]);
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasVertexWeights)
    {
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            for (uint32_t j = 0; j < m_VertexWeights[i].size(); j++)
            {
                writer.Write(m_VertexWeights[i][j]);
            }
        }
    }

    for (uint32_t i = 0; i < m_StripLengths.size(); i++)
    {
        writer.Write(m_StripLengths[i]);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasFaces);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2) && m_NumStrips!= 0)
    {
        for (uint32_t i = 0; i < m_Strips.size(); i++)
        {
            for (uint32_t j = 0; j < m_Strips[i].size(); j++)
            {
                writer.Write(m_Strips[i][j]);
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasFaces) && (m_NumStrips!= 0))
    {
        for (uint32_t i = 0; i < m_Strips.size(); i++)
        {
            for (uint32_t j = 0; j < m_Strips[i].size(); j++)
            {
                writer.Write(m_Strips[i][j]);
            }
        }
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2) && m_NumStrips== 0)
    {
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasFaces) && (m_NumStrips== 0))
    {
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Write(writer, version, user, 0);
        }
    }

    writer.Write(m_HasBoneIndices);

    if (m_HasBoneIndices)
    {
        for (uint32_t i = 0; i < m_BoneIndices.size(); i++)
        {
            for (uint32_t j = 0; j < m_BoneIndices[i].size(); j++)
            {
                writer.Write(m_BoneIndices[i][j]);
            }
        }
    }

    if (user>= 12)
    {
        writer.Write(m_UnknownShort);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_Unknown83C3);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_Unknown00001);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_NumVertices2);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_Unknown00002);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_Unknown00003);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        writer.Write(m_Unknown00004);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user== 1)
    {
        for (uint32_t i = 0; i < m_UnknownArr1.size(); i++)
        {
            m_UnknownArr1[i].Write(writer, version, user, 0);
        }
    }

}
