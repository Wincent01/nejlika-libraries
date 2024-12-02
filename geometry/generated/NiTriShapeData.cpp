#include "NiTriShapeData.hpp"

using namespace nejlika::geometry;

void NiTriShapeData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriBasedGeomData::Read(reader, version, user, arg);

    m_NumTrianglePoints = reader.Read<uint>();

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasTriangles = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Triangles.resize(m_NumTriangles);
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3) && m_HasTriangles)
    {
        m_Triangles.resize(m_NumTriangles);
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_NumMatchGroups = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_MatchGroups.resize(m_NumMatchGroups);
        for (uint32_t i = 0; i < m_MatchGroups.size(); i++)
        {
            m_MatchGroups[i].Read(reader, version, user, 0);
        }
    }

}

void NiTriShapeData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriBasedGeomData::Write(writer, version, user, arg);

    writer.Write(m_NumTrianglePoints);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasTriangles);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3) && m_HasTriangles)
    {
        for (uint32_t i = 0; i < m_Triangles.size(); i++)
        {
            m_Triangles[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_NumMatchGroups);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        for (uint32_t i = 0; i < m_MatchGroups.size(); i++)
        {
            m_MatchGroups[i].Write(writer, version, user, 0);
        }
    }

}
