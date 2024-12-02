#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The type of animation interpolation (blending) that will be used on the associated key frames.
 *         
 */
enum BSShaderType : uint
{
    /**
     * Tall Grass Shader
     */
    SHADER_TALL_GRASS = 0,
    /**
     * Standard Lighting Shader
     */
    SHADER_DEFAULT = 1,
    /**
     * Sky Shader
     */
    SHADER_SKY = 10,
    /**
     * Skin Shader
     */
    SHADER_SKIN = 14,
    /**
     * Water Shader
     */
    SHADER_WATER = 17,
    /**
     * Lighting 3.0 Shader
     */
    SHADER_LIGHTING30 = 29,
    /**
     * Tiled Shader
     */
    SHADER_TILE = 32,
    /**
     * No Lighting Shader
     */
    SHADER_NOLIGHTING = 33,
};

}
