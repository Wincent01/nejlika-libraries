#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
#include "HavokMaterial.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "Vector3.hpp"
#include "MoppDataBuildType.hpp"
#include "bhkBvTreeShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Memory optimized partial polytope bounding volume tree shape (not an entity).
 *         
 */
class bhkMoppBvTreeShape : public bhkBvTreeShape
{
protected:
    /**
     * The shape.
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
     * Unknown bytes.
     */
    std::vector<byte> m_Unknown8Bytes;
    /**
     * Unknown float, might be scale.
     */
    float m_UnknownFloat;
    /**
     * Number of bytes for MOPP data.
     */
    uint m_MOPPDataSize;
    /**
     * Origin of the object in mopp coordinates. This is the minimum of all vertices in the packed shape along each axis, minus 0.1.
     */
    Vector3 m_Origin;
    /**
     * The scaling factor to quantize the MOPP: the quantization factor is equal to 256*256 divided by this number. In Oblivion files, scale is taken equal to 256*256*254 / (size + 0.2) where size is the largest dimension of the bounding box of the packed shape.
     */
    float m_Scale;
    /**
     * The tree of bounding volume data (old style, contains more than just the mopp script).
     */
    std::vector<byte> m_OldMOPPData;
    /**
     * Tells if MOPP Data was organized into smaller chunks (PS3) or not (PC)
     */
    MoppDataBuildType m_BuildType;
    /**
     * The tree of bounding volume data.
     */
    std::vector<byte> m_MOPPData;

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

    const std::vector<byte>& GetUnknown8Bytes() const { return m_Unknown8Bytes; }
    std::vector<byte>& GetUnknown8Bytes() { return m_Unknown8Bytes; }
    void SetUnknown8Bytes(const std::vector<byte>& value) { m_Unknown8Bytes = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const uint& GetMOPPDataSize() const { return m_MOPPDataSize; }
    uint& GetMOPPDataSize() { return m_MOPPDataSize; }
    void SetMOPPDataSize(const uint& value) { m_MOPPDataSize = value; }

    const Vector3& GetOrigin() const { return m_Origin; }
    Vector3& GetOrigin() { return m_Origin; }
    void SetOrigin(const Vector3& value) { m_Origin = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const std::vector<byte>& GetOldMOPPData() const { return m_OldMOPPData; }
    std::vector<byte>& GetOldMOPPData() { return m_OldMOPPData; }
    void SetOldMOPPData(const std::vector<byte>& value) { m_OldMOPPData = value; }

    const MoppDataBuildType& GetBuildType() const { return m_BuildType; }
    MoppDataBuildType& GetBuildType() { return m_BuildType; }
    void SetBuildType(const MoppDataBuildType& value) { m_BuildType = value; }

    const std::vector<byte>& GetMOPPData() const { return m_MOPPData; }
    std::vector<byte>& GetMOPPData() { return m_MOPPData; }
    void SetMOPPData(const std::vector<byte>& value) { m_MOPPData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
