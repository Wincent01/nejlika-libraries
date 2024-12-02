#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysVolumeEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle emitter that uses points within a sphere shape to emit from.
 *         
 */
class NiPSysSphereEmitter : public NiPSysVolumeEmitter
{
protected:
    /**
     * The radius of the sphere shape
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
