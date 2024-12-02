#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The motion system. 4 (Box) is used for everything movable. 7 (Keyframed) is used on statics and animated stuff.
 * 
 *         
 */
enum MotionSystem : byte
{
    /**
     * Invalid
     */
    MO_SYS_INVALID = 0,
    /**
     * A fully-simulated, movable rigid body. At construction time the engine checks the input inertia and selects MO_SYS_SPHERE_INERTIA or MO_SYS_BOX_INERTIA as appropriate.
     */
    MO_SYS_DYNAMIC = 1,
    /**
     * Simulation is performed using a sphere inertia tensor.
     */
    MO_SYS_SPHERE = 2,
    /**
     * This is the same as MO_SYS_SPHERE_INERTIA, except that simulation of the rigid body is "softened".
     */
    MO_SYS_SPHERE_INERTIA = 3,
    /**
     * Simulation is performed using a box inertia tensor.
     */
    MO_SYS_BOX = 4,
    /**
     * This is the same as MO_SYS_BOX_INERTIA, except that simulation of the rigid body is "softened".
     */
    MO_SYS_BOX_STABILIZED = 5,
    /**
     * Simulation is not performed as a normal rigid body. The keyframed rigid body has an infinite mass when viewed by the rest of the system. (used for creatures)
     */
    MO_SYS_KEYFRAMED = 6,
    /**
     * This motion type is used for the static elements of a game scene, e.g. the landscape. Faster than MO_SYS_KEYFRAMED at velocity 0. (used for weapons)
     */
    MO_SYS_FIXED = 7,
    /**
     * A box inertia motion which is optimized for thin boxes and has less stability problems
     */
    MO_SYS_THIN_BOX = 8,
    /**
     * A specialized motion used for character controllers
     */
    MO_SYS_CHARACTER = 9,
};

}
