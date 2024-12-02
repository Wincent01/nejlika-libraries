#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The type of information that's store in a texture used by a NiTextureEffect.
 *         
 */
enum EffectType : uint
{
    /**
     * Apply a projected light texture.
     */
    EFFECT_PROJECTED_LIGHT = 0,
    /**
     * Apply a projected shaddow texture.
     */
    EFFECT_PROJECTED_SHADOW = 1,
    /**
     * Apply an environment map texture.
     */
    EFFECT_ENVIRONMENT_MAP = 2,
    /**
     * Apply a fog map texture.
     */
    EFFECT_FOG_MAP = 3,
};

}
