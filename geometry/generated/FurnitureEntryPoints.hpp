#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 * 		Furniture entry points. It specifies the direction(s) from where the actor is able to enter (and leave) the position.
 * 		
 */
enum FurnitureEntryPoints : ushort
{
    /**
     * front entry point
     */
    Front = 0,
    /**
     * behind entry point
     */
    Behind = 1,
    /**
     * right entry point
     */
    Right = 2,
    /**
     * left entry point
     */
    Left = 3,
    /**
     * up entry point - unknown function. Used on some beds in Skyrim, probably for blocking of sleeping position.
     */
    Up = 4,
};

}
