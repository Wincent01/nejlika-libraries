#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPointLight.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A spot.
 *         
 */
class NiSpotLight : public NiPointLight
{
protected:
    /**
     * The opening angle of the spot.
     */
    float m_CutoffAngle;
    /**
     * Unknown
     */
    float m_UnknownFloat;
    /**
     * Describes the distribution of light. (see: glLight)
     */
    float m_Exponent;

public:
    const float& GetCutoffAngle() const { return m_CutoffAngle; }
    float& GetCutoffAngle() { return m_CutoffAngle; }
    void SetCutoffAngle(const float& value) { m_CutoffAngle = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const float& GetExponent() const { return m_Exponent; }
    float& GetExponent() { return m_Exponent; }
    void SetExponent(const float& value) { m_Exponent = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
