#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "LightingShaderControlledVariable.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     This controller is used to animate float variables in BSLightingShaderProperty.
 * 		
 */
class BSLightingShaderPropertyFloatController : public NiFloatInterpController
{
protected:
    /**
     * Which float variable in BSLightingShaderProperty to animate:
     */
    LightingShaderControlledVariable m_TypeOfControlledVariable;

public:
    const LightingShaderControlledVariable& GetTypeOfControlledVariable() const { return m_TypeOfControlledVariable; }
    LightingShaderControlledVariable& GetTypeOfControlledVariable() { return m_TypeOfControlledVariable; }
    void SetTypeOfControlledVariable(const LightingShaderControlledVariable& value) { m_TypeOfControlledVariable = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}