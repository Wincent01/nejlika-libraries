#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "Vector4.hpp"
#include "bhkCompressedMeshShapeData.hpp"
#include "bhkShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Compressed collision mesh.
 *         
 */
class bhkCompressedMeshShape : public bhkShape
{
protected:
    /**
     * Points to root node?
     */
    Pointer<class NiAVObject*> m_Target;
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
    std::vector<byte> m_Unknown4Bytes;
    /**
     * Unknown
     */
    Vector4 m_UnknownFloats1;
    /**
     * A shell with that radius is added around the shape.
     */
    float m_Radius;
    /**
     * Scale
     */
    float m_Scale;
    /**
     * Unknown
     */
    float m_UnknownFloat3;
    /**
     * Unknown
     */
    float m_UnknownFloat4;
    /**
     * Unknown
     */
    float m_UnknownFloat5;
    /**
     * The collision mesh data.
     */
    Pointer<class bhkCompressedMeshShapeData*> m_Data;

public:
    const Pointer<class NiAVObject*>& GetTarget() const { return m_Target; }
    Pointer<class NiAVObject*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiAVObject*>& value) { m_Target = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const std::vector<byte>& GetUnknown4Bytes() const { return m_Unknown4Bytes; }
    std::vector<byte>& GetUnknown4Bytes() { return m_Unknown4Bytes; }
    void SetUnknown4Bytes(const std::vector<byte>& value) { m_Unknown4Bytes = value; }

    const Vector4& GetUnknownFloats1() const { return m_UnknownFloats1; }
    Vector4& GetUnknownFloats1() { return m_UnknownFloats1; }
    void SetUnknownFloats1(const Vector4& value) { m_UnknownFloats1 = value; }

    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const float& GetUnknownFloat5() const { return m_UnknownFloat5; }
    float& GetUnknownFloat5() { return m_UnknownFloat5; }
    void SetUnknownFloat5(const float& value) { m_UnknownFloat5 = value; }

    const Pointer<class bhkCompressedMeshShapeData*>& GetData() const { return m_Data; }
    Pointer<class bhkCompressedMeshShapeData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class bhkCompressedMeshShapeData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
