#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing which float variable in BSLightingShaderProperty to animate.
 *         
 */
enum LightingShaderControlledVariable : uint
{
    /**
     * Unknown Float 2.
     */
    UnknownFloat2 = 0,
    /**
     * Environment Map Scale.
     */
    EnvironmentMapScale = 8,
    /**
     * Glossiness.
     */
    Glossiness = 9,
    /**
     * Specular Strength.
     */
    SpecularStrength = 10,
    /**
     * Emissive Multiple.
     */
    EmissiveMultiple = 11,
    /**
     * Alpha.
     */
    Alpha = 12,
    /**
     * U Offset.
     */
    UOffset = 20,
    /**
     * U Scale.
     */
    UScale = 21,
    /**
     * V Offset.
     */
    VOffset = 22,
    /**
     * V Scale.
     */
    VScale = 23,
};

}
