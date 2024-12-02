#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle Modifier that uses the wind value from the gamedata to alter the path of particles.
 *         
 */
class BSWindModifier : public NiPSysModifier
{
protected:
    /**
     * The amount of force wind will have on particles.
     */
    float m_Strength;

public:
    const float& GetStrength() const { return m_Strength; }
    float& GetStrength() { return m_Strength; }
    void SetStrength(const float& value) { m_Strength = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
