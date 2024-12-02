#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Specifies the availiable texture filter modes.  That is, the way pixels within a texture are blended together when textures are displayed on the screen at a size other than their original dimentions.
 *         
 */
enum TexFilterMode : uint
{
    /**
     * Simply uses the nearest pixel.  Very grainy.
     */
    FILTER_NEAREST = 0,
    /**
     * Uses bilinear filtering.
     */
    FILTER_BILERP = 1,
    /**
     * Uses trilinear filtering.
     */
    FILTER_TRILERP = 2,
    /**
     * Uses the nearest pixel from the mipmap that is closest to the display size.
     */
    FILTER_NEAREST_MIPNEAREST = 3,
    /**
     * Blends the two mipmaps closest to the display size linearly, and then uses the nearest pixel from the result.
     */
    FILTER_NEAREST_MIPLERP = 4,
    /**
     * Uses the closest mipmap to the display size and then uses bilinear filtering on the pixels.
     */
    FILTER_BILERP_MIPNEAREST = 5,
};

}
