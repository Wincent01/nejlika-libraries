#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum ChannelConvention : uint
{
    /**
     * Fixed
     */
    CC_FIXED = 0,
    /**
     * Palettized
     */
    CC_INDEX = 3,
    /**
     * Compressed
     */
    CC_COMPRESSED = 4,
    /**
     * Empty
     */
    CC_EMPTY = 5,
};

}
