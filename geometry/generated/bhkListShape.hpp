#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
#include "HavokMaterial.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "bhkShapeCollection.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A list of shapes.
 * 
 *         Do not put a bhkPackedNiTriStripsShape in the Sub Shapes. Use a
 *         separate collision nodes without a list shape for those.
 * 
 *         Also, shapes collected in a bhkListShape may not have the correct
 *         walking noise, so only use it for non-walkable objects.
 *         
 */
class bhkListShape : public bhkShapeCollection
{
protected:
    /**
     * The number of sub shapes referenced.
     */
    uint m_NumSubShapes;
    /**
     * List of shapes.
     */
    std::vector<Pointer<class bhkShape*>> m_SubShapes;
    /**
     * The shape's material.
     */
    HavokMaterial m_Material;
    /**
     * The shape's material.
     */
    SkyrimHavokMaterial m_SkyrimMaterial;
    /**
     * Unknown. Set to (0.0,0.0,-0.0,0.0,0.0,-0.0), where -0.0 is 0x80000000 in hex.
     */
    std::vector<float> m_UnknownFloats;
    /**
     * Count.
     */
    uint m_NumUnknownInts;
    /**
     * Unknown.
     */
    std::vector<uint> m_UnknownInts;

public:
    const uint& GetNumSubShapes() const { return m_NumSubShapes; }
    uint& GetNumSubShapes() { return m_NumSubShapes; }
    void SetNumSubShapes(const uint& value) { m_NumSubShapes = value; }

    const std::vector<Pointer<class bhkShape*>>& GetSubShapes() const { return m_SubShapes; }
    std::vector<Pointer<class bhkShape*>>& GetSubShapes() { return m_SubShapes; }
    void SetSubShapes(const std::vector<Pointer<class bhkShape*>>& value) { m_SubShapes = value; }

    const HavokMaterial& GetMaterial() const { return m_Material; }
    HavokMaterial& GetMaterial() { return m_Material; }
    void SetMaterial(const HavokMaterial& value) { m_Material = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const std::vector<float>& GetUnknownFloats() const { return m_UnknownFloats; }
    std::vector<float>& GetUnknownFloats() { return m_UnknownFloats; }
    void SetUnknownFloats(const std::vector<float>& value) { m_UnknownFloats = value; }

    const uint& GetNumUnknownInts() const { return m_NumUnknownInts; }
    uint& GetNumUnknownInts() { return m_NumUnknownInts; }
    void SetNumUnknownInts(const uint& value) { m_NumUnknownInts = value; }

    const std::vector<uint>& GetUnknownInts() const { return m_UnknownInts; }
    std::vector<uint>& GetUnknownInts() { return m_UnknownInts; }
    void SetUnknownInts(const std::vector<uint>& value) { m_UnknownInts = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
