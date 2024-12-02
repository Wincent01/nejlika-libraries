#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines decay function.  Used by NiPSysBombModifier.
 *         
 */
enum DecayType : uint
{
    /**
     * No decay.
     */
    DECAY_NONE = 0,
    /**
     * Linear decay.
     */
    DECAY_LINEAR = 1,
    /**
     * Exponential decay.
     */
    DECAY_EXPONENTIAL = 2,
};

}
