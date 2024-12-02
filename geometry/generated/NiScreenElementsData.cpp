#include "NiScreenElementsData.hpp"

using namespace nejlika::geometry;

void NiScreenElementsData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriShapeData::Read(reader, version, user, arg);

    m_MaxPolygons = reader.Read<ushort>();

    m_Polygons.resize(m_MaxPolygons);
    for (uint32_t i = 0; i < m_Polygons.size(); i++)
    {
        m_Polygons[i].Read(reader, version, user, 0);
    }

    m_PolygonIndices.resize(m_MaxPolygons);
    for (uint32_t i = 0; i < m_PolygonIndices.size(); i++)
    {
        m_PolygonIndices[i] = reader.Read<ushort>();
    }

    m_UnknownUShort1 = reader.Read<ushort>();

    m_NumPolygons = reader.Read<ushort>();

    m_UsedVertices = reader.Read<ushort>();

    m_UnknownUShort2 = reader.Read<ushort>();

    m_UsedTrianglePoints = reader.Read<ushort>();

    m_UnknownUShort3 = reader.Read<ushort>();

}

void NiScreenElementsData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriShapeData::Write(writer, version, user, arg);

    writer.Write(m_MaxPolygons);

    for (uint32_t i = 0; i < m_Polygons.size(); i++)
    {
        m_Polygons[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_PolygonIndices.size(); i++)
    {
        writer.Write(m_PolygonIndices[i]);
    }

    writer.Write(m_UnknownUShort1);

    writer.Write(m_NumPolygons);

    writer.Write(m_UsedVertices);

    writer.Write(m_UnknownUShort2);

    writer.Write(m_UsedTrianglePoints);

    writer.Write(m_UnknownUShort3);

}
