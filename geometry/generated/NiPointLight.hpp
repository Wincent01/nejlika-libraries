#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiLight.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A point light.
 *         
 */
class NiPointLight : public NiLight
{
protected:
    /**
     * Constant Attenuation
     */
    float m_ConstantAttenuation;
    /**
     * Linear Attenuation
     */
    float m_LinearAttenuation;
    /**
     * Quadratic Attenuation (see glLight)
     */
    float m_QuadraticAttenuation;

public:
    const float& GetConstantAttenuation() const { return m_ConstantAttenuation; }
    float& GetConstantAttenuation() { return m_ConstantAttenuation; }
    void SetConstantAttenuation(const float& value) { m_ConstantAttenuation = value; }

    const float& GetLinearAttenuation() const { return m_LinearAttenuation; }
    float& GetLinearAttenuation() { return m_LinearAttenuation; }
    void SetLinearAttenuation(const float& value) { m_LinearAttenuation = value; }

    const float& GetQuadraticAttenuation() const { return m_QuadraticAttenuation; }
    float& GetQuadraticAttenuation() { return m_QuadraticAttenuation; }
    void SetQuadraticAttenuation(const float& value) { m_QuadraticAttenuation = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
