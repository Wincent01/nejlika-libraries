#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines the way the billboard will react to the camera.
 *         
 */
enum BillboardMode : ushort
{
    /**
     * The billboard will always face the camera.
     */
    ALWAYS_FACE_CAMERA = 0,
    /**
     * The billboard will only rotate around the up axis.
     */
    ROTATE_ABOUT_UP = 1,
    /**
     * Rigid Face Camera.
     */
    RIGID_FACE_CAMERA = 2,
    /**
     * Always Face Center.
     */
    ALWAYS_FACE_CENTER = 3,
    /**
     * Rigid Face Center.
     */
    RIGID_FACE_CENTER = 4,
    /**
     * The billboard will only rotate around the up axis (same as ROTATE_ABOUT_UP?).
     */
    ROTATE_ABOUT_UP2 = 9,
};

}
