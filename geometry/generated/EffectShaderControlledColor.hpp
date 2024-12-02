#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing which color in BSEffectShaderProperty to animate.
 *         
 */
enum EffectShaderControlledColor : uint
{
    /**
     * Emissive Color.
     */
    EffectShaderControlledColorEmissiveColor = 0,
};

}
