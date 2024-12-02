#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum DeactivatorType : byte
{
    /**
     * Invalid
     */
    DEACTIVATOR_INVALID = 0,
    /**
     * This will force the rigid body to never deactivate.
     */
    DEACTIVATOR_NEVER = 1,
    /**
     * Tells Havok to use a spatial deactivation scheme. This makes use of high and low frequencies of positional motion to determine when deactivation should occur.
     */
    DEACTIVATOR_SPATIAL = 2,
};

}
