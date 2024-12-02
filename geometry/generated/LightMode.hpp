#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing how vertex colors influence lighting.
 *         
 */
enum LightMode : uint
{
    /**
     * Emissive.
     */
    LIGHT_MODE_EMISSIVE = 0,
    /**
     * Emissive + Ambient + Diffuse. (Default)
     */
    LIGHT_MODE_EMI_AMB_DIF = 1,
};

}
