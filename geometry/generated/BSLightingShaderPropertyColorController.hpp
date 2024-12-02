#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "LightingShaderControlledColor.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     This controller is used to animate colors in BSLightingShaderProperty.
 * 		
 */
class BSLightingShaderPropertyColorController : public NiFloatInterpController
{
protected:
    /**
     * Which color in BSLightingShaderProperty to animate:
     */
    LightingShaderControlledColor m_TypeOfControlledColor;

public:
    const LightingShaderControlledColor& GetTypeOfControlledColor() const { return m_TypeOfControlledColor; }
    LightingShaderControlledColor& GetTypeOfControlledColor() { return m_TypeOfControlledColor; }
    void SetTypeOfControlledColor(const LightingShaderControlledColor& value) { m_TypeOfControlledColor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
