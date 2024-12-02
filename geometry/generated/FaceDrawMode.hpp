#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         This enum lists the different face culling options.
 *         
 */
enum FaceDrawMode : uint
{
    /**
     * use application defaults?
     */
    DRAW_CCW_OR_BOTH = 0,
    /**
     * Draw counter clock wise faces, cull clock wise faces. This is the default for most (all?) Nif Games so far.
     */
    DRAW_CCW = 1,
    /**
     * Draw clock wise faces, cull counter clock wise faces. This will flip all the faces.
     */
    DRAW_CW = 2,
    /**
     * Draw double sided faces.
     */
    DRAW_BOTH = 3,
};

}
