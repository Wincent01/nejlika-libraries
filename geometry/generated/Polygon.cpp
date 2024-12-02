#include "Polygon.hpp"

using namespace nejlika::geometry;

void Polygon::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumVertices = reader.Read<ushort>();

    m_VertexOffset = reader.Read<ushort>();

    m_NumTriangles = reader.Read<ushort>();

    m_TriangleOffset = reader.Read<ushort>();

}

void Polygon::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumVertices);

    writer.Write(m_VertexOffset);

    writer.Write(m_NumTriangles);

    writer.Write(m_TriangleOffset);

}
