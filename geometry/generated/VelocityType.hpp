#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Controls the way the a particle mesh emitter determines the starting speed and direction of the particles that are emitted.
 *         
 */
enum VelocityType : uint
{
    /**
     * Uses the normals of the meshes to determine staring velocity.
     */
    VELOCITY_USE_NORMALS = 0,
    /**
     * Starts particles with a random velocity.
     */
    VELOCITY_USE_RANDOM = 1,
    /**
     * Uses the emission axis to determine initial particle direction?
     */
    VELOCITY_USE_DIRECTION = 2,
};

}
