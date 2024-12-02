#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The animation cyle behavior.
 *         
 */
enum CycleType : uint
{
    /**
     * Loop
     */
    CYCLE_LOOP = 0,
    /**
     * Reverse
     */
    CYCLE_REVERSE = 1,
    /**
     * Clamp
     */
    CYCLE_CLAMP = 2,
};

}
