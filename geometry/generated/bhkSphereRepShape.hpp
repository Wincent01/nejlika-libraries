#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "HavokMaterial.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "bhkShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A havok shape, perhaps with a bounding sphere for quick rejection in addition to more detailed shape data?
 *         
 */
class bhkSphereRepShape : public bhkShape
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
     * The radius of the sphere that encloses the shape.
     */
    float m_Radius;

public:
    const HavokMaterial& GetMaterial() const { return m_Material; }
    HavokMaterial& GetMaterial() { return m_Material; }
    void SetMaterial(const HavokMaterial& value) { m_Material = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
