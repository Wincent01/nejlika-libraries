#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum BoundVolumeType : uint
{
    /**
     * Default
     */
    BASE_BV = 4294967295,
    /**
     * Sphere
     */
    SPHERE_BV = 0,
    /**
     * Box
     */
    BOX_BV = 1,
    /**
     * Capsule
     */
    CAPSULE_BV = 2,
    /**
     * Union
     */
    UNION_BV = 4,
    /**
     * Half Space
     */
    HALFSPACE_BV = 5,
};

}
