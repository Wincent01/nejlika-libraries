#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "EffectShaderControlledVariable.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     This controller is used to animate float variables in BSEffectShaderProperty.
 *         
 */
class BSEffectShaderPropertyFloatController : public NiFloatInterpController
{
protected:
    /**
     * Which float variable in BSEffectShaderProperty to animate:
     */
    EffectShaderControlledVariable m_TypeOfControlledVariable;

public:
    const EffectShaderControlledVariable& GetTypeOfControlledVariable() const { return m_TypeOfControlledVariable; }
    EffectShaderControlledVariable& GetTypeOfControlledVariable() { return m_TypeOfControlledVariable; }
    void SetTypeOfControlledVariable(const EffectShaderControlledVariable& value) { m_TypeOfControlledVariable = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
