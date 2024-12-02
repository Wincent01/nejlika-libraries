#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Used by NiPoint3InterpControllers to select which type of color in the controlled object that will be animated.
 *         
 */
enum TargetColor : ushort
{
    /**
     * Control the ambient color.
     */
    TC_AMBIENT = 0,
    /**
     * Control the diffuse color.
     */
    TC_DIFFUSE = 1,
    /**
     * Control the specular color.
     */
    TC_SPECULAR = 2,
    /**
     * Control the self illumination color.
     */
    TC_SELF_ILLUM = 3,
};

}
