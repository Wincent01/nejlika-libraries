#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing what's inside the segment.
 *         
 */
enum BSSegmentFlags : uint
{
    /**
     * Contains water.
     */
    BSSEG_WATER = 9,
};

}
