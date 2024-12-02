#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Specifies the availiable texture clamp modes.  That is, the behavior of pixels outside the range of the texture.
 *         
 */
enum TexClampMode : uint
{
    /**
     * Clamp in both directions.
     */
    CLAMP_S_CLAMP_T = 0,
    /**
     * Clamp in the S(U) direction but wrap in the T(V) direction.
     */
    CLAMP_S_WRAP_T = 1,
    /**
     * Wrap in the S(U) direction but clamp in the T(V) direction.
     */
    WRAP_S_CLAMP_T = 2,
    /**
     * Wrap in both directions.
     */
    WRAP_S_WRAP_T = 3,
};

}
