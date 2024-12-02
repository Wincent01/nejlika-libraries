#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysFieldModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system modifier, used for controlling the particle
 *         velocity in force field.
 *         
 */
class NiPSysRadialFieldModifier : public NiPSysFieldModifier
{
protected:
    /**
     * Unknown Enums?
     */
    int m_RadialType;

public:
    const int& GetRadialType() const { return m_RadialType; }
    int& GetRadialType() { return m_RadialType; }
    void SetRadialType(const int& value) { m_RadialType = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
