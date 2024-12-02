#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Polygon.hpp"
#include "NiTriShapeData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Two dimensional screen elements.
 *         
 */
class NiScreenElementsData : public NiTriShapeData
{
protected:
    /**
     * Maximum number of polygons?
     */
    ushort m_MaxPolygons;
    /**
     * Polygons
     */
    std::vector<Polygon> m_Polygons;
    /**
     * Polygon Indices
     */
    std::vector<ushort> m_PolygonIndices;
    /**
     * Unknown
     */
    ushort m_UnknownUShort1;
    /**
     * Number of Polygons actually in use
     */
    ushort m_NumPolygons;
    /**
     * Number of in-use vertices
     */
    ushort m_UsedVertices;
    /**
     * Unknown
     */
    ushort m_UnknownUShort2;
    /**
     * Number of in-use triangles
     */
    ushort m_UsedTrianglePoints;
    /**
     * Maximum number of faces
     */
    ushort m_UnknownUShort3;

public:
    const ushort& GetMaxPolygons() const { return m_MaxPolygons; }
    ushort& GetMaxPolygons() { return m_MaxPolygons; }
    void SetMaxPolygons(const ushort& value) { m_MaxPolygons = value; }

    const std::vector<Polygon>& GetPolygons() const { return m_Polygons; }
    std::vector<Polygon>& GetPolygons() { return m_Polygons; }
    void SetPolygons(const std::vector<Polygon>& value) { m_Polygons = value; }

    const std::vector<ushort>& GetPolygonIndices() const { return m_PolygonIndices; }
    std::vector<ushort>& GetPolygonIndices() { return m_PolygonIndices; }
    void SetPolygonIndices(const std::vector<ushort>& value) { m_PolygonIndices = value; }

    const ushort& GetUnknownUShort1() const { return m_UnknownUShort1; }
    ushort& GetUnknownUShort1() { return m_UnknownUShort1; }
    void SetUnknownUShort1(const ushort& value) { m_UnknownUShort1 = value; }

    const ushort& GetNumPolygons() const { return m_NumPolygons; }
    ushort& GetNumPolygons() { return m_NumPolygons; }
    void SetNumPolygons(const ushort& value) { m_NumPolygons = value; }

    const ushort& GetUsedVertices() const { return m_UsedVertices; }
    ushort& GetUsedVertices() { return m_UsedVertices; }
    void SetUsedVertices(const ushort& value) { m_UsedVertices = value; }

    const ushort& GetUnknownUShort2() const { return m_UnknownUShort2; }
    ushort& GetUnknownUShort2() { return m_UnknownUShort2; }
    void SetUnknownUShort2(const ushort& value) { m_UnknownUShort2 = value; }

    const ushort& GetUsedTrianglePoints() const { return m_UsedTrianglePoints; }
    ushort& GetUsedTrianglePoints() { return m_UsedTrianglePoints; }
    void SetUsedTrianglePoints(const ushort& value) { m_UsedTrianglePoints = value; }

    const ushort& GetUnknownUShort3() const { return m_UnknownUShort3; }
    ushort& GetUnknownUShort3() { return m_UnknownUShort3; }
    void SetUnknownUShort3(const ushort& value) { m_UnknownUShort3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
