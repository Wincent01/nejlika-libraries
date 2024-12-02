#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
#include "HavokMaterial.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "Matrix44.hpp"
#include "bhkShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Transforms a shape.
 *         
 */
class bhkTransformShape : public bhkShape
{
protected:
    /**
     * The shape that this object transforms.
     */
    Pointer<class bhkShape*> m_Shape;
    /**
     * The shape's material.
     */
    HavokMaterial m_Material;
    /**
     * The shape's material.
     */
    SkyrimHavokMaterial m_SkyrimMaterial;
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown8Bytes;
    /**
     * A transform matrix.
     */
    Matrix44 m_Transform;

public:
    const Pointer<class bhkShape*>& GetShape() const { return m_Shape; }
    Pointer<class bhkShape*>& GetShape() { return m_Shape; }
    void SetShape(const Pointer<class bhkShape*>& value) { m_Shape = value; }

    const HavokMaterial& GetMaterial() const { return m_Material; }
    HavokMaterial& GetMaterial() { return m_Material; }
    void SetMaterial(const HavokMaterial& value) { m_Material = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const std::vector<byte>& GetUnknown8Bytes() const { return m_Unknown8Bytes; }
    std::vector<byte>& GetUnknown8Bytes() { return m_Unknown8Bytes; }
    void SetUnknown8Bytes(const std::vector<byte>& value) { m_Unknown8Bytes = value; }

    const Matrix44& GetTransform() const { return m_Transform; }
    Matrix44& GetTransform() { return m_Transform; }
    void SetTransform(const Matrix44& value) { m_Transform = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
