#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         This particle system modifier controls the particle size. If it is present the particles start with size 0.0 . Then they grow to their original size and stay there until they fade to zero size again at the end of their lifetime cycle.
 *         
 */
class NiParticleGrowFade : public NiParticleModifier
{
protected:
    /**
     * The time from the beginning of the particle lifetime during which the particle grows.
     */
    float m_Grow;
    /**
     * The time from the end of the particle lifetime during which the particle fades.
     */
    float m_Fade;

public:
    const float& GetGrow() const { return m_Grow; }
    float& GetGrow() { return m_Grow; }
    void SetGrow(const float& value) { m_Grow = value; }

    const float& GetFade() const { return m_Fade; }
    float& GetFade() { return m_Fade; }
    void SetFade(const float& value) { m_Fade = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
