#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines how the raw image data is stored in NiRawImageData.
 *         
 */
enum ImageType : uint
{
    /**
     * Colors store red, blue, and green components.
     */
    RGB = 1,
    /**
     * Colors store red, blue, green, and alpha components.
     */
    RGBA = 2,
};

}
