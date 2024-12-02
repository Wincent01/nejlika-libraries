#include "NiBezierMesh.hpp"

using namespace nejlika::geometry;

void NiBezierMesh::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_NumBezierTriangles = reader.Read<uint>();

    m_BezierTriangle.resize(m_NumBezierTriangles);
    for (uint32_t i = 0; i < m_BezierTriangle.size(); i++)
    {
        m_BezierTriangle[i].Read(reader, version, user, 0);
    }

    m_Unknown3 = reader.Read<uint>();

    m_Count1 = reader.Read<ushort>();

    m_Unknown4 = reader.Read<ushort>();

    m_Points1.resize(m_Count1);
    for (uint32_t i = 0; i < m_Points1.size(); i++)
    {
        m_Points1[i].Read(reader, version, user, 0);
    }

    m_Unknown5 = reader.Read<uint>();

    m_Points2.resize(m_Count1);
    for (uint32_t i = 0; i < m_Points2.size(); i++)
    {
        m_Points2[i].resize(2);
        for (uint32_t j = 0; j < m_Points2[i].size(); j++)
        {
            m_Points2[i][j] = reader.Read<float>();
        }
    }

    m_Unknown6 = reader.Read<uint>();

    m_Count2 = reader.Read<ushort>();

    m_Data2.resize(m_Count2);
    for (uint32_t i = 0; i < m_Data2.size(); i++)
    {
        m_Data2[i].resize(4);
        for (uint32_t j = 0; j < m_Data2[i].size(); j++)
        {
            m_Data2[i][j] = reader.Read<ushort>();
        }
    }

}

void NiBezierMesh::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    writer.Write(m_NumBezierTriangles);

    for (uint32_t i = 0; i < m_BezierTriangle.size(); i++)
    {
        m_BezierTriangle[i].Write(writer, version, user, 0);
    }

    writer.Write(m_Unknown3);

    writer.Write(m_Count1);

    writer.Write(m_Unknown4);

    for (uint32_t i = 0; i < m_Points1.size(); i++)
    {
        m_Points1[i].Write(writer, version, user, 0);
    }

    writer.Write(m_Unknown5);

    for (uint32_t i = 0; i < m_Points2.size(); i++)
    {
        for (uint32_t j = 0; j < m_Points2[i].size(); j++)
        {
            writer.Write(m_Points2[i][j]);
        }
    }

    writer.Write(m_Unknown6);

    writer.Write(m_Count2);

    for (uint32_t i = 0; i < m_Data2.size(); i++)
    {
        for (uint32_t j = 0; j < m_Data2[i].size(); j++)
        {
            writer.Write(m_Data2[i][j]);
        }
    }

}
