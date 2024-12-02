#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysVolumeEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle emitter that uses points within a defined Cylinder shape to emit from.
 *         
 */
class NiPSysCylinderEmitter : public NiPSysVolumeEmitter
{
protected:
    /**
     * Radius of the cylinder shape.
     */
    float m_Radius;
    /**
     * Height of the cylinders shape.
     */
    float m_Height;

public:
    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }

    const float& GetHeight() const { return m_Height; }
    float& GetHeight() { return m_Height; }
    void SetHeight(const float& value) { m_Height = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
