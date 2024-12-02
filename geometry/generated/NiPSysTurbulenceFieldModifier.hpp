#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysFieldModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system modifier, used for controlling the particle velocity in drag space warp.
 *         
 */
class NiPSysTurbulenceFieldModifier : public NiPSysFieldModifier
{
protected:
    /**
     * Frequency of the update.
     */
    float m_Frequency;

public:
    const float& GetFrequency() const { return m_Frequency; }
    float& GetFrequency() { return m_Frequency; }
    void SetFrequency(const float& value) { m_Frequency = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
