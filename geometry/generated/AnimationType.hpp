#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 * 		Animation type used on this position. This specifies the function of this position.
 * 		
 */
enum AnimationType : ushort
{
    /**
     * Actor use sit animation.
     */
    Sit = 1,
    /**
     * Actor use sleep animation.
     */
    Sleep = 2,
    /**
     * Used for lean animations?
     */
    Lean = 4,
};

}
