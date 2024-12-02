#include "NiGeometryData.hpp"

using namespace nejlika::geometry;

void NiGeometryData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInt = reader.Read<int>();
    }

    if (!false)
    {
        m_NumVertices = reader.Read<ushort>();
    }

    if (false && ((version < VERSION_NUMBER(20, 2, 0, 7)) || (user< 11)))
    {
        m_NumVertices = reader.Read<ushort>();
    }

    if (false && (version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11))
    {
        m_BSMaxVertices = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_KeepFlags = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_CompressFlags = reader.Read<byte>();
    }

    m_HasVertices = reader.Read<bool>();

    if (m_HasVertices)
    {
        m_Vertices.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Vertices.size(); i++)
        {
            m_Vertices[i].Read(reader, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(10, 0, 1, 0)) && (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))))
    {
        m_NumUVSets = reader.Read<ushort>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_BSNumUVSets = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && !false && user == 12)
    {
        m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();
    }

    m_HasNormals = reader.Read<bool>();

    if (m_HasNormals)
    {
        m_Normals.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Normals.size(); i++)
        {
            m_Normals[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasNormals) && ((m_NumUVSets& 61440) || (m_BSNumUVSets& 61440)))
    {
        m_Tangents.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Tangents.size(); i++)
        {
            m_Tangents[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasNormals) && ((m_NumUVSets& 61440) || (m_BSNumUVSets& 61440)))
    {
        m_Bitangents.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Bitangents.size(); i++)
        {
            m_Bitangents[i].Read(reader, version, user, 0);
        }
    }

    m_Center.Read(reader, version, user, 0);

    m_Radius = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_Unknown13Shorts.resize(13);
        for (uint32_t i = 0; i < m_Unknown13Shorts.size(); i++)
        {
            m_Unknown13Shorts[i] = reader.Read<short>();
        }
    }

    m_HasVertexColors = reader.Read<bool>();

    if (m_HasVertexColors)
    {
        m_VertexColors.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexColors.size(); i++)
        {
            m_VertexColors[i].Read(reader, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_NumUVSets = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_HasUV = reader.Read<bool>();
    }

    m_UVSets.resize((m_NumUVSets& 63) | (m_BSNumUVSets& 1));
    for (uint32_t i = 0; i < m_UVSets.size(); i++)
    {
        m_UVSets[i].resize(m_NumVertices);
        for (uint32_t j = 0; j < m_UVSets[i].size(); j++)
        {
            m_UVSets[i][j].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && user< 12)
    {
        m_ConsistencyFlags = reader.Read<ConsistencyType>();
    }
    else
    {
        m_ConsistencyFlags = static_cast<ConsistencyType>(CT_MUTABLE);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && !false && user>= 12)
    {
        m_ConsistencyFlags = reader.Read<ConsistencyType>();
    }
    else
    {
        m_ConsistencyFlags = static_cast<ConsistencyType>(CT_MUTABLE);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && user< 12)
    {
        m_AdditionalData.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && !false && user>= 12)
    {
        m_AdditionalData.Read(reader, version, user, 0);
    }

}

void NiGeometryData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownInt);
    }

    if (!false)
    {
        writer.Write(m_NumVertices);
    }

    if (false && (version < VERSION_NUMBER(20, 2, 0, 7)) || (user< 11))
    {
        writer.Write(m_NumVertices);
    }

    if (false && (version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11))
    {
        writer.Write(m_BSMaxVertices);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_KeepFlags);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_CompressFlags);
    }

    writer.Write(m_HasVertices);

    if (m_HasVertices)
    {
        for (uint32_t i = 0; i < m_Vertices.size(); i++)
        {
            m_Vertices[i].Write(writer, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(10, 0, 1, 0)) && (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))))
    {
        writer.Write(m_NumUVSets);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        writer.Write(m_BSNumUVSets);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && !false && user == 12)
    {
        writer.Write(m_SkyrimMaterial);
    }

    writer.Write(m_HasNormals);

    if (m_HasNormals)
    {
        for (uint32_t i = 0; i < m_Normals.size(); i++)
        {
            m_Normals[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasNormals) && ((m_NumUVSets& 61440) || (m_BSNumUVSets& 61440)))
    {
        for (uint32_t i = 0; i < m_Tangents.size(); i++)
        {
            m_Tangents[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (m_HasNormals) && ((m_NumUVSets& 61440) || (m_BSNumUVSets& 61440)))
    {
        for (uint32_t i = 0; i < m_Bitangents.size(); i++)
        {
            m_Bitangents[i].Write(writer, version, user, 0);
        }
    }

    m_Center.Write(writer, version, user, 0);

    writer.Write(m_Radius);

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        for (uint32_t i = 0; i < m_Unknown13Shorts.size(); i++)
        {
            writer.Write(m_Unknown13Shorts[i]);
        }
    }

    writer.Write(m_HasVertexColors);

    if (m_HasVertexColors)
    {
        for (uint32_t i = 0; i < m_VertexColors.size(); i++)
        {
            m_VertexColors[i].Write(writer, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_NumUVSets);
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_HasUV);
    }

    for (uint32_t i = 0; i < m_UVSets.size(); i++)
    {
        for (uint32_t j = 0; j < m_UVSets[i].size(); j++)
        {
            m_UVSets[i][j].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && user< 12)
    {
        writer.Write(m_ConsistencyFlags);
    }
    else
    {
        //writer.Write(CT_MUTABLE);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && !false && user>= 12)
    {
        writer.Write(m_ConsistencyFlags);
    }
    else
    {
        //writer.Write(CT_MUTABLE);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && user< 12)
    {
        m_AdditionalData.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && !false && user>= 12)
    {
        m_AdditionalData.Write(writer, version, user, 0);
    }

}
