#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "HavokMaterial.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "Vector3.hpp"
#include "NiTriStripsData.hpp"
#include "OblivionColFilter.hpp"
#include "bhkShapeCollection.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A shape constructed from a bunch of strips.
 *         
 */
class bhkNiTriStripsShape : public bhkShapeCollection
{
protected:
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
    uint m_UnknownInt1;
    /**
     * Unknown.
     */
    std::vector<uint> m_UnknownInts1;
    /**
     * Unknown
     */
    uint m_UnknownInt2;
    /**
     * Scale. Usually (1.0, 1.0, 1.0).
     */
    Vector3 m_Scale;
    /**
     * Unknown.
     */
    uint m_UnknownInt3;
    /**
     * The number of strips data objects referenced.
     */
    uint m_NumStripsData;
    /**
     * Refers to a bunch of NiTriStripsData objects that make up this shape.
     */
    std::vector<Pointer<class NiTriStripsData*>> m_StripsData;
    /**
     * Number of Havok Layers, equal to Number of strips data objects.
     */
    uint m_NumDataLayers;
    /**
     * Havok Layers for each strip data.
     */
    std::vector<OblivionColFilter> m_DataLayers;

public:
    const HavokMaterial& GetMaterial() const { return m_Material; }
    HavokMaterial& GetMaterial() { return m_Material; }
    void SetMaterial(const HavokMaterial& value) { m_Material = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const std::vector<uint>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<uint>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<uint>& value) { m_UnknownInts1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const Vector3& GetScale() const { return m_Scale; }
    Vector3& GetScale() { return m_Scale; }
    void SetScale(const Vector3& value) { m_Scale = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const uint& GetNumStripsData() const { return m_NumStripsData; }
    uint& GetNumStripsData() { return m_NumStripsData; }
    void SetNumStripsData(const uint& value) { m_NumStripsData = value; }

    const std::vector<Pointer<class NiTriStripsData*>>& GetStripsData() const { return m_StripsData; }
    std::vector<Pointer<class NiTriStripsData*>>& GetStripsData() { return m_StripsData; }
    void SetStripsData(const std::vector<Pointer<class NiTriStripsData*>>& value) { m_StripsData = value; }

    const uint& GetNumDataLayers() const { return m_NumDataLayers; }
    uint& GetNumDataLayers() { return m_NumDataLayers; }
    void SetNumDataLayers(const uint& value) { m_NumDataLayers = value; }

    const std::vector<OblivionColFilter>& GetDataLayers() const { return m_DataLayers; }
    std::vector<OblivionColFilter>& GetDataLayers() { return m_DataLayers; }
    void SetDataLayers(const std::vector<OblivionColFilter>& value) { m_DataLayers = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
