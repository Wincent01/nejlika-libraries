#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Specifies the pixel format used by the NiPixelData object to store a texture.
 *         
 */
enum PixelFormat : uint
{
    /**
     * 24-bit color: uses 8 bit to store each red, blue, and green component.
     */
    PX_FMT_RGB8 = 0,
    /**
     * 32-bit color with alpha: uses 8 bits to store each red, blue, green, and alpha component.
     */
    PX_FMT_RGBA8 = 1,
    /**
     * 8-bit palette index: uses 8 bits to store an index into the palette stored in a NiPalette object.
     */
    PX_FMT_PAL8 = 2,
    /**
     * DXT1 compressed texture.
     */
    PX_FMT_DXT1 = 4,
    /**
     * DXT5 compressed texture.
     */
    PX_FMT_DXT5 = 5,
    /**
     * DXT5 compressed texture. It is not clear what the difference is with PX_FMT_DXT5.
     */
    PX_FMT_DXT5_ALT = 6,
};

}
