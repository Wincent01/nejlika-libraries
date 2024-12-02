#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Sets how objects are to be cloned.
 *         
 */
enum CloningBehavior : uint
{
    /**
     * Share this object pointer with the newly cloned scene.
     */
    CLONING_SHARE = 0,
    /**
     * Create an exact duplicate of this object for use with the newly cloned scene.
     */
    CLONING_COPY = 1,
    /**
     * Create a copy of this object for use with the newly cloned stream, leaving some of the data to be written later.
     */
    CLONING_BLANK_COPY = 2,
};

}
