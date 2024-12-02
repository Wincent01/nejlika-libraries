#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkinTransform.hpp"
#include "Vector3.hpp"
#include "SkinWeight.hpp"
#include "SkinWeight.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skinning data component.
 *         
 */
class SkinData : public Construct
{
protected:
    /**
     * Offset of the skin from this bone in bind position.
     */
    SkinTransform m_SkinTransform;
    /**
     * Translation offset of a bounding sphere holding all vertices. (Note that its a Sphere Containing Axis Aligned Box not a minimum volume Sphere)
     */
    Vector3 m_BoundingSphereOffset;
    /**
     * Radius for bounding sphere holding all vertices.
     */
    float m_BoundingSphereRadius;
    /**
     * Unknown, always 0?
     */
    std::vector<short> m_Unknown13Shorts;
    /**
     * Number of weighted vertices.
     */
    ushort m_NumVertices;
    /**
     * The vertex weights.
     */
    std::vector<SkinWeight> m_VertexWeights;

public:
    const SkinTransform& GetSkinTransform() const { return m_SkinTransform; }
    SkinTransform& GetSkinTransform() { return m_SkinTransform; }
    void SetSkinTransform(const SkinTransform& value) { m_SkinTransform = value; }

    const Vector3& GetBoundingSphereOffset() const { return m_BoundingSphereOffset; }
    Vector3& GetBoundingSphereOffset() { return m_BoundingSphereOffset; }
    void SetBoundingSphereOffset(const Vector3& value) { m_BoundingSphereOffset = value; }

    const float& GetBoundingSphereRadius() const { return m_BoundingSphereRadius; }
    float& GetBoundingSphereRadius() { return m_BoundingSphereRadius; }
    void SetBoundingSphereRadius(const float& value) { m_BoundingSphereRadius = value; }

    const std::vector<short>& GetUnknown13Shorts() const { return m_Unknown13Shorts; }
    std::vector<short>& GetUnknown13Shorts() { return m_Unknown13Shorts; }
    void SetUnknown13Shorts(const std::vector<short>& value) { m_Unknown13Shorts = value; }

    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const std::vector<SkinWeight>& GetVertexWeights() const { return m_VertexWeights; }
    std::vector<SkinWeight>& GetVertexWeights() { return m_VertexWeights; }
    void SetVertexWeights(const std::vector<SkinWeight>& value) { m_VertexWeights = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
