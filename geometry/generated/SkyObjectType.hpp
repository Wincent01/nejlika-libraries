#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Skyrim, sets what sky function this object fulfills in BSSkyShaderProperty.
 *         
 */
enum SkyObjectType : uint
{
    /**
     * BSSM_Sky_Texture
     */
    BSSM_SKY_TEXTURE = 0,
    /**
     * BSSM_Sky_Sunglare
     */
    BSSM_SKY_SUNGLARE = 1,
    /**
     * BSSM_Sky
     */
    BSSM_SKY = 2,
    /**
     * BSSM_Sky_Clouds
     */
    BSSM_SKY_CLOUDS = 3,
    /**
     * BSSM_Sky_Stars
     */
    BSSM_SKY_STARS = 5,
    /**
     * BSSM_Sky_Moon_Stars_Mask
     */
    BSSM_SKY_MOON_STARS_MASK = 7,
};

}
