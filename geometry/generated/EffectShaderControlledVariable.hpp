#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing which float variable in BSEffectShaderProperty to animate.
 *         
 */
enum EffectShaderControlledVariable : uint
{
    /**
     * EmissiveMultiple.
     */
    EffectShaderControlledVariableEmissiveMultiple = 0,
    /**
     * Falloff Start Angle (degrees).
     */
    FalloffStartAngledegrees = 1,
    /**
     * Falloff Stop Angle (degrees).
     */
    FalloffStopAngledegrees = 2,
    /**
     * Falloff Start Opacity.
     */
    FalloffStartOpacity = 3,
    /**
     * Falloff Stop Opacity.
     */
    FalloffStopOpacity = 4,
    /**
     * Alpha Transparency (Emissive alpha?).
     */
    AlphaTransparencyEmissiveAlpha = 5,
    /**
     * U Offset.
     */
    EffectShaderControlledVariableUOffset = 6,
    /**
     * U Scale.
     */
    EffectShaderControlledVariableUScale = 7,
    /**
     * V Offset.
     */
    EffectShaderControlledVariableVOffset = 8,
    /**
     * V Scale.
     */
    EffectShaderControlledVariableVScale = 9,
};

}
