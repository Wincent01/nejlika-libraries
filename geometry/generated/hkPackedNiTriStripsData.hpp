#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "hkTriangle.hpp"
#include "Vector3.hpp"
#include "OblivionSubShape.hpp"
#include "bhkShapeCollection.hpp"
namespace nejlika::geometry {


/**
 * 
 *         NiTriStripsData for havok data?
 *         
 */
class hkPackedNiTriStripsData : public bhkShapeCollection
{
protected:
    /**
     * Number of triangles?
     */
    uint m_NumTriangles;
    /**
     * The physics triangles?
     */
    std::vector<hkTriangle> m_Triangles;
    /**
     * Number of vertices.
     */
    uint m_NumVertices;
    /**
     * Unknown.
     */
    byte m_UnknownByte1;
    /**
     * The vertices?
     */
    std::vector<Vector3> m_Vertices;
    /**
     * Number of subparts.
     */
    ushort m_NumSubShapes;
    /**
     * The subparts.
     */
    std::vector<OblivionSubShape> m_SubShapes;

public:
    const uint& GetNumTriangles() const { return m_NumTriangles; }
    uint& GetNumTriangles() { return m_NumTriangles; }
    void SetNumTriangles(const uint& value) { m_NumTriangles = value; }

    const std::vector<hkTriangle>& GetTriangles() const { return m_Triangles; }
    std::vector<hkTriangle>& GetTriangles() { return m_Triangles; }
    void SetTriangles(const std::vector<hkTriangle>& value) { m_Triangles = value; }

    const uint& GetNumVertices() const { return m_NumVertices; }
    uint& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const uint& value) { m_NumVertices = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const std::vector<Vector3>& GetVertices() const { return m_Vertices; }
    std::vector<Vector3>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<Vector3>& value) { m_Vertices = value; }

    const ushort& GetNumSubShapes() const { return m_NumSubShapes; }
    ushort& GetNumSubShapes() { return m_NumSubShapes; }
    void SetNumSubShapes(const ushort& value) { m_NumSubShapes = value; }

    const std::vector<OblivionSubShape>& GetSubShapes() const { return m_SubShapes; }
    std::vector<OblivionSubShape>& GetSubShapes() { return m_SubShapes; }
    void SetSubShapes(const std::vector<OblivionSubShape>& value) { m_SubShapes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
