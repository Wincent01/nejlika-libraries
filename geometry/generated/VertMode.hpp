#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, which describes how to apply vertex colors.
 *         
 */
enum VertMode : uint
{
    /**
     * Source Ignore.
     */
    VERT_MODE_SRC_IGNORE = 0,
    /**
     * Source Emissive.
     */
    VERT_MODE_SRC_EMISSIVE = 1,
    /**
     * Source Ambient/Diffuse. (Default)
     */
    VERT_MODE_SRC_AMB_DIF = 2,
};

}
