#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Two dimensional screen elements.
 *         
 */
class Polygon : public Construct
{
protected:
    /**
     * Number of vertices in this polygon
     */
    ushort m_NumVertices;
    /**
     * Vertex Offset
     */
    ushort m_VertexOffset;
    /**
     * Number of faces in this polygon
     */
    ushort m_NumTriangles;
    /**
     * Triangle offset in shape
     */
    ushort m_TriangleOffset;

public:
    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const ushort& GetVertexOffset() const { return m_VertexOffset; }
    ushort& GetVertexOffset() { return m_VertexOffset; }
    void SetVertexOffset(const ushort& value) { m_VertexOffset = value; }

    const ushort& GetNumTriangles() const { return m_NumTriangles; }
    ushort& GetNumTriangles() { return m_NumTriangles; }
    void SetNumTriangles(const ushort& value) { m_NumTriangles = value; }

    const ushort& GetTriangleOffset() const { return m_TriangleOffset; }
    ushort& GetTriangleOffset() { return m_TriangleOffset; }
    void SetTriangleOffset(const ushort& value) { m_TriangleOffset = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
