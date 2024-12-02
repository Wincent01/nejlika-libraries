#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing the apply mode of a texture.
 *         
 */
enum ApplyMode : uint
{
    /**
     * Replaces existing color
     */
    APPLY_REPLACE = 0,
    /**
     * For placing images on the object like stickers.
     */
    APPLY_DECAL = 1,
    /**
     * Modulates existing color. (Default)
     */
    APPLY_MODULATE = 2,
    /**
     * PS2 Only.  Function Unknown.
     */
    APPLY_HILIGHT = 3,
    /**
     * Parallax Flag in some Oblivion meshes.
     */
    APPLY_HILIGHT2 = 4,
};

}
