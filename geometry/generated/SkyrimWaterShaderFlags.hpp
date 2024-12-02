#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Skyrim water shader property flags
 *         
 */
enum SkyrimWaterShaderFlags : byte
{
    /**
     * Unknown
     */
    SWSF1_UNKNOWN0 = 0,
    /**
     * Bypasses refraction map when set to 1
     */
    SWSF1_Bypass_Refraction_Map = 1,
    /**
     * Main water Layer on/off
     */
    SWSF1_Water_Toggle = 2,
    /**
     * Unknown
     */
    SWSF1_UNKNOWN3 = 3,
    /**
     * Unknown
     */
    SWSF1_UNKNOWN4 = 4,
    /**
     * Unknown
     */
    SWSF1_UNKNOWN5 = 5,
    /**
     * Reflection layer 2 on/off. (is this scene reflection?)
     */
    SWSF1_Highlight_Layer_Toggle = 6,
    /**
     * Water layer on/off
     */
    SWSF1_Enabled = 7,
};

}
