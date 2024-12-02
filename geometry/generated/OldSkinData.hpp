#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Used to store skin weights in NiTriShapeSkinController.
 *         
 */
class OldSkinData : public Construct
{
protected:
    /**
     * The amount that this bone affects the vertex.
     */
    float m_VertexWeight;
    /**
     * The index of the vertex that this weight applies to.
     */
    ushort m_VertexIndex;
    /**
     * Unknown.  Perhaps some sort of offset?
     */
    Vector3 m_UnknownVector;

public:
    const float& GetVertexWeight() const { return m_VertexWeight; }
    float& GetVertexWeight() { return m_VertexWeight; }
    void SetVertexWeight(const float& value) { m_VertexWeight = value; }

    const ushort& GetVertexIndex() const { return m_VertexIndex; }
    ushort& GetVertexIndex() { return m_VertexIndex; }
    void SetVertexIndex(const ushort& value) { m_VertexIndex = value; }

    const Vector3& GetUnknownVector() const { return m_UnknownVector; }
    Vector3& GetUnknownVector() { return m_UnknownVector; }
    void SetUnknownVector(const Vector3& value) { m_UnknownVector = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
