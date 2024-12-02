#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum PropagationMode : uint
{
    /**
     * On Success
     */
    PROPAGATE_ON_SUCCESS = 0,
    /**
     * On Failure
     */
    PROPAGATE_ON_FAILURE = 1,
    /**
     * Always
     */
    PROPAGATE_ALWAYS = 2,
    /**
     * Never
     */
    PROPAGATE_NEVER = 3,
};

}
