#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysCollider.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle Collider object which particles will interact with.
 *         
 */
class NiPSysSphericalCollider : public NiPSysCollider
{
protected:
    /**
     * Defines the radius of the sphere object.
     */
    float m_Radius;

public:
    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
