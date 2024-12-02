#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that adds a blend of object space translation and rotation to particles born in world space.
 *         
 */
class BSParentVelocityModifier : public NiPSysModifier
{
protected:
    /**
     * Amount of blending?
     */
    float m_Damping;

public:
    const float& GetDamping() const { return m_Damping; }
    float& GetDamping() { return m_Damping; }
    void SetDamping(const float& value) { m_Damping = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
