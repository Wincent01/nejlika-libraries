#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         An unsigned 32-bit integer, describing how transparency is handled in a texture.
 *         
 */
enum AlphaFormat : uint
{
    /**
     * No alpha blending; the texture is fully opaque.
     */
    ALPHA_NONE = 0,
    /**
     * Texture is either fully transparent or fully opaque.  There are no partially transparent areas.
     */
    ALPHA_BINARY = 1,
    /**
     * Full range of alpha values can be used from fully transparent to fully opaque including all partially transparent values in between.
     */
    ALPHA_SMOOTH = 2,
    /**
     * Use default setting.
     */
    ALPHA_DEFAULT = 3,
};

}
