#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkyrimHavokMaterial.hpp"
#include "SkyrimLayer.hpp"
namespace nejlika::geometry {


/**
 * 
 *     per-chunk material, used in bhkCompressedMeshShapeData
 * 		
 */
class bhkCMSDMaterial : public Construct
{
protected:
    /**
     * Material.
     */
    SkyrimHavokMaterial m_SkyrimMaterial;
    /**
     * Copy of Skyrim Layer from bhkRigidBody. The value is stored as 32-bit integer.
     */
    SkyrimLayer m_SkyrimLayer;

public:
    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const SkyrimLayer& GetSkyrimLayer() const { return m_SkyrimLayer; }
    SkyrimLayer& GetSkyrimLayer() { return m_SkyrimLayer; }
    void SetSkyrimLayer(const SkyrimLayer& value) { m_SkyrimLayer = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
