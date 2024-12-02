#include "bhkConvexVerticesShape.hpp"

using namespace nejlika::geometry;

void bhkConvexVerticesShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConvexShape::Read(reader, version, user, arg);

    m_Unknown6Floats.resize(6);
    for (uint32_t i = 0; i < m_Unknown6Floats.size(); i++)
    {
        m_Unknown6Floats[i] = reader.Read<float>();
    }

    m_NumVertices = reader.Read<uint>();

    m_Vertices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Read(reader, version, user, 0);
    }

    m_NumNormals = reader.Read<uint>();

    m_Normals.resize(m_NumNormals);
    for (uint32_t i = 0; i < m_Normals.size(); i++)
    {
        m_Normals[i].Read(reader, version, user, 0);
    }

}

void bhkConvexVerticesShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConvexShape::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown6Floats.size(); i++)
    {
        writer.Write(m_Unknown6Floats[i]);
    }

    writer.Write(m_NumVertices);

    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumNormals);

    for (uint32_t i = 0; i < m_Normals.size(); i++)
    {
        m_Normals[i].Write(writer, version, user, 0);
    }

}
