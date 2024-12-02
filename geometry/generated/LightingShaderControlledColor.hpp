#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing which color in BSLightingShaderProperty to animate.
 *         
 */
enum LightingShaderControlledColor : uint
{
    /**
     * Specular Color.
     */
    SpecularColor = 0,
    /**
     * Emissive Color.
     */
    EmissiveColor = 1,
};

}
