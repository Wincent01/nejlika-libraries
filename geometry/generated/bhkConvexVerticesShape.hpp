#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "bhkConvexShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A convex shape built from vertices. Note that if the shape is used in
 *         a non-static object (such as clutter), then they will simply fall
 *         through ground when they are under a bhkListShape.
 *         
 */
class bhkConvexVerticesShape : public bhkConvexShape
{
protected:
    /**
     * Unknown. Must be (0.0,0.0,-0.0,0.0,0.0,-0.0) for arrow detection to work (mind the minus signs, -0.0 is 0x80000000 in hex).
     */
    std::vector<float> m_Unknown6Floats;
    /**
     * Number of vertices.
     */
    uint m_NumVertices;
    /**
     * Vertices. Fourth component is 0. Lexicographically sorted.
     */
    std::vector<Vector4> m_Vertices;
    /**
     * The number of half spaces.
     */
    uint m_NumNormals;
    /**
     * Half spaces as determined by the set of vertices above. First three components define the normal pointing to the exterior, fourth component is the signed distance of the separating plane to the origin: it is minus the dot product of v and n, where v is any vertex on the separating plane, and n is the normal. Lexicographically sorted.
     */
    std::vector<Vector4> m_Normals;

public:
    const std::vector<float>& GetUnknown6Floats() const { return m_Unknown6Floats; }
    std::vector<float>& GetUnknown6Floats() { return m_Unknown6Floats; }
    void SetUnknown6Floats(const std::vector<float>& value) { m_Unknown6Floats = value; }

    const uint& GetNumVertices() const { return m_NumVertices; }
    uint& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const uint& value) { m_NumVertices = value; }

    const std::vector<Vector4>& GetVertices() const { return m_Vertices; }
    std::vector<Vector4>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<Vector4>& value) { m_Vertices = value; }

    const uint& GetNumNormals() const { return m_NumNormals; }
    uint& GetNumNormals() { return m_NumNormals; }
    void SetNumNormals(const uint& value) { m_NumNormals = value; }

    const std::vector<Vector4>& GetNormals() const { return m_Normals; }
    std::vector<Vector4>& GetNormals() { return m_Normals; }
    void SetNormals(const std::vector<Vector4>& value) { m_Normals = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
