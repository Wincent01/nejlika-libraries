#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines the way that UV texture coordinates are generated.
 *         
 */
enum CoordGenType : uint
{
    /**
     * Use plannar mapping.
     */
    CG_WORLD_PARALLEL = 0,
    /**
     * Use perspective mapping.
     */
    CG_WORLD_PERSPECTIVE = 1,
    /**
     * Use spherical mapping.
     */
    CG_SPHERE_MAP = 2,
    /**
     * Use specular cube mapping.
     */
    CG_SPECULAR_CUBE_MAP = 3,
    /**
     * Use Diffuse cube mapping.
     */
    CG_DIFFUSE_CUBE_MAP = 4,
};

}
