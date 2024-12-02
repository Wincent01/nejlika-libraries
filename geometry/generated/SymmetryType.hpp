#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines symetry type used by NiPSysBombModifier.
 *         
 */
enum SymmetryType : uint
{
    /**
     * Spherical Symmetry.
     */
    SPHERICAL_SYMMETRY = 0,
    /**
     * Cylindrical Symmetry.
     */
    CYLINDRICAL_SYMMETRY = 1,
    /**
     * Planar Symmetry.
     */
    PLANAR_SYMMETRY = 2,
};

}
