#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "MaterialData.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An object that can be rendered.
 *         
 */
class NiRenderObject : public NiAVObject
{
protected:
    /**
     * The number of materials affecting this renderable object.
     */
    uint m_NumMaterials;
    /**
     * Per-material data.
     */
    std::vector<MaterialData> m_MaterialData;
    /**
     * The index of the currently active material.
     */
    int m_ActiveMaterial;
    /**
     * The initial value for the flag that determines if the internal cached shader is valid.
     */
    bool m_MaterialNeedsUpdateDefault;

public:
    const uint& GetNumMaterials() const { return m_NumMaterials; }
    uint& GetNumMaterials() { return m_NumMaterials; }
    void SetNumMaterials(const uint& value) { m_NumMaterials = value; }

    const std::vector<MaterialData>& GetMaterialData() const { return m_MaterialData; }
    std::vector<MaterialData>& GetMaterialData() { return m_MaterialData; }
    void SetMaterialData(const std::vector<MaterialData>& value) { m_MaterialData = value; }

    const int& GetActiveMaterial() const { return m_ActiveMaterial; }
    int& GetActiveMaterial() { return m_ActiveMaterial; }
    void SetActiveMaterial(const int& value) { m_ActiveMaterial = value; }

    const bool& GetMaterialNeedsUpdateDefault() const { return m_MaterialNeedsUpdateDefault; }
    bool& GetMaterialNeedsUpdateDefault() { return m_MaterialNeedsUpdateDefault; }
    void SetMaterialNeedsUpdateDefault(const bool& value) { m_MaterialNeedsUpdateDefault = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
