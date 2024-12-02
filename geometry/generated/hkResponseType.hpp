#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum hkResponseType : byte
{
    /**
     * Invalid Response
     */
    RESPONSE_INVALID = 0,
    /**
     * Do normal collision resolution
     */
    RESPONSE_SIMPLE_CONTACT = 1,
    /**
     * No collision resolution is performed but listeners are called
     */
    RESPONSE_REPORTING = 2,
    /**
     * Do nothing, ignore all the results.
     */
    RESPONSE_NONE = 3,
};

}
