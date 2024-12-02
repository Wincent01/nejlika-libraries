#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Triangle.hpp"
#include "Triangle.hpp"
#include "MatchGroup.hpp"
#include "NiTriBasedGeomData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Holds mesh data using a list of singular triangles.
 *         
 */
class NiTriShapeData : public NiTriBasedGeomData
{
protected:
    /**
     * Num Triangles times 3.
     */
    uint m_NumTrianglePoints;
    /**
     * Do we have triangle data?
     */
    bool m_HasTriangles;
    /**
     * Triangle data.
     */
    std::vector<Triangle> m_Triangles;
    /**
     * Number of shared normals groups.
     */
    ushort m_NumMatchGroups;
    /**
     * The shared normals.
     */
    std::vector<MatchGroup> m_MatchGroups;

public:
    const uint& GetNumTrianglePoints() const { return m_NumTrianglePoints; }
    uint& GetNumTrianglePoints() { return m_NumTrianglePoints; }
    void SetNumTrianglePoints(const uint& value) { m_NumTrianglePoints = value; }

    const bool& GetHasTriangles() const { return m_HasTriangles; }
    bool& GetHasTriangles() { return m_HasTriangles; }
    void SetHasTriangles(const bool& value) { m_HasTriangles = value; }

    const std::vector<Triangle>& GetTriangles() const { return m_Triangles; }
    std::vector<Triangle>& GetTriangles() { return m_Triangles; }
    void SetTriangles(const std::vector<Triangle>& value) { m_Triangles = value; }

    const ushort& GetNumMatchGroups() const { return m_NumMatchGroups; }
    ushort& GetNumMatchGroups() { return m_NumMatchGroups; }
    void SetNumMatchGroups(const ushort& value) { m_NumMatchGroups = value; }

    const std::vector<MatchGroup>& GetMatchGroups() const { return m_MatchGroups; }
    std::vector<MatchGroup>& GetMatchGroups() { return m_MatchGroups; }
    void SetMatchGroups(const std::vector<MatchGroup>& value) { m_MatchGroups = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
