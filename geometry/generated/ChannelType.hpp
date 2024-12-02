#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum ChannelType : uint
{
    /**
     * Red
     */
    CHNL_RED = 0,
    /**
     * Green
     */
    CHNL_GREEN = 1,
    /**
     * Blue
     */
    CHNL_BLUE = 2,
    /**
     * Alpha
     */
    CHNL_ALPHA = 3,
    /**
     * Compressed
     */
    CHNL_COMPRESSED = 4,
    /**
     * Index
     */
    CHNL_INDEX = 16,
    /**
     * Empty
     */
    CHNL_EMPTY = 19,
};

}
