#include "hkPackedNiTriStripsData.hpp"

using namespace nejlika::geometry;

void hkPackedNiTriStripsData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShapeCollection::Read(reader, version, user, arg);

    m_NumTriangles = reader.Read<uint>();

    m_Triangles.resize(m_NumTriangles);
    for (uint32_t i = 0; i < m_Triangles.size(); i++)
    {
        m_Triangles[i].Read(reader, version, user, 0);
    }

    m_NumVertices = reader.Read<uint>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_UnknownByte1 = reader.Read<byte>();
    }

    m_Vertices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_NumSubShapes = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_SubShapes.resize(m_NumSubShapes);
        for (uint32_t i = 0; i < m_SubShapes.size(); i++)
        {
            m_SubShapes[i].Read(reader, version, user, 0);
        }
    }

}

void hkPackedNiTriStripsData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShapeCollection::Write(writer, version, user, arg);

    writer.Write(m_NumTriangles);

    for (uint32_t i = 0; i < m_Triangles.size(); i++)
    {
        m_Triangles[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumVertices);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_UnknownByte1);
    }

    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_NumSubShapes);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        for (uint32_t i = 0; i < m_SubShapes.size(); i++)
        {
            m_SubShapes[i].Write(writer, version, user, 0);
        }
    }

}
