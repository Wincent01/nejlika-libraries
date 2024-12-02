#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The motion type. Determines quality of motion?
 *         
 */
enum MotionQuality : byte
{
    /**
     * Automatically assigned to MO_QUAL_FIXED, MO_QUAL_KEYFRAMED or MO_QUAL_DEBRIS
     */
    MO_QUAL_INVALID = 0,
    /**
     * Use this for fixed bodies. 
     */
    MO_QUAL_FIXED = 1,
    /**
     * Use this for moving objects with infinite mass.
     */
    MO_QUAL_KEYFRAMED = 2,
    /**
     * Use this for all your debris objects
     */
    MO_QUAL_DEBRIS = 3,
    /**
     * Use this for moving bodies, which should not leave the world.
     */
    MO_QUAL_MOVING = 4,
    /**
     * Use this for all objects, which you cannot afford to tunnel through the world at all
     */
    MO_QUAL_CRITICAL = 5,
    /**
     * Use this for very fast objects 
     */
    MO_QUAL_BULLET = 6,
    /**
     * For user.
     */
    MO_QUAL_USER = 7,
    /**
     * Use this for rigid body character controllers
     */
    MO_QUAL_CHARACTER = 8,
    /**
     * 
     *             Use this for moving objects with infinite mass which should report contact points and Toi-collisions against all other bodies, including other fixed and keyframed bodies.
     *         
     */
    MO_QUAL_KEYFRAMED_REPORT = 9,
};

}
