#include "SkinData.hpp"

using namespace nejlika::geometry;

void SkinData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_SkinTransform.Read(reader, version, user, 0);

    m_BoundingSphereOffset.Read(reader, version, user, 0);

    m_BoundingSphereRadius = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_Unknown13Shorts.resize(13);
        for (uint32_t i = 0; i < m_Unknown13Shorts.size(); i++)
        {
            m_Unknown13Shorts[i] = reader.Read<short>();
        }
    }

    m_NumVertices = reader.Read<ushort>();

    if (version <= VERSION_NUMBER(4, 2, 1, 0))
    {
        m_VertexWeights.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && arg!= 0)
    {
        m_VertexWeights.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].Read(reader, version, user, 0);
        }
    }

}

void SkinData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_SkinTransform.Write(writer, version, user, 0);

    m_BoundingSphereOffset.Write(writer, version, user, 0);

    writer.Write(m_BoundingSphereRadius);

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        for (uint32_t i = 0; i < m_Unknown13Shorts.size(); i++)
        {
            writer.Write(m_Unknown13Shorts[i]);
        }
    }

    writer.Write(m_NumVertices);

    if (version <= VERSION_NUMBER(4, 2, 1, 0))
    {
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && arg!= 0)
    {
        for (uint32_t i = 0; i < m_VertexWeights.size(); i++)
        {
            m_VertexWeights[i].Write(writer, version, user, 0);
        }
    }

}
