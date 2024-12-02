#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing how mipmaps are handled in a texture.
 *         
 */
enum MipMapFormat : uint
{
    /**
     * Texture does not use mip maps.
     */
    MIP_FMT_NO = 0,
    /**
     * Texture uses mip maps.
     */
    MIP_FMT_YES = 1,
    /**
     * Use default setting.
     */
    MIP_FMT_DEFAULT = 2,
};

}
