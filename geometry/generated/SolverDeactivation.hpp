#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         A list of possible solver deactivation settings. This value defines how the
 *         solver deactivates objects. The solver works on a per object basis.
 *         Note: Solver deactivation does not save CPU, but reduces creeping of
 *         movable objects in a pile quite dramatically.
 *         
 */
enum SolverDeactivation : byte
{
    /**
     * Invalid
     */
    SOLVER_DEACTIVATION_INVALID = 0,
    /**
     * No solver deactivation
     */
    SOLVER_DEACTIVATION_OFF = 1,
    /**
     * Very conservative deactivation, typically no visible artifacts.
     */
    SOLVER_DEACTIVATION_LOW = 2,
    /**
     * Normal deactivation, no serious visible artifacts in most cases
     */
    SOLVER_DEACTIVATION_MEDIUM = 3,
    /**
     * Fast deactivation, visible artifacts
     */
    SOLVER_DEACTIVATION_HIGH = 4,
    /**
     * Very fast deactivation, visible artifacts
     */
    SOLVER_DEACTIVATION_MAX = 5,
};

}
