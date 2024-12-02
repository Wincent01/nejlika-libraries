#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "EffectShaderControlledColor.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     This controller is used to animate colors in BSEffectShaderProperty.
 * 		
 */
class BSEffectShaderPropertyColorController : public NiFloatInterpController
{
protected:
    /**
     * Which color in BSEffectShaderProperty to animate:
     */
    EffectShaderControlledColor m_TypeOfControlledColor;

public:
    const EffectShaderControlledColor& GetTypeOfControlledColor() const { return m_TypeOfControlledColor; }
    EffectShaderControlledColor& GetTypeOfControlledColor() { return m_TypeOfControlledColor; }
    void SetTypeOfControlledColor(const EffectShaderControlledColor& value) { m_TypeOfControlledColor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
