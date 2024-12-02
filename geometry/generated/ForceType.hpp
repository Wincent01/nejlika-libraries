#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The type of force?  May be more valid values.
 *         
 */
enum ForceType : uint
{
    FORCE_PLANAR = 0,
    FORCE_SPHERICAL = 1,
    FORCE_UNKNOWN = 2,
};

}
