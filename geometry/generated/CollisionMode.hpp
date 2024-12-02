#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum CollisionMode : uint
{
    /**
     * Use Bounding Box
     */
    CM_USE_OBB = 0,
    /**
     * Use Triangles
     */
    CM_USE_TRI = 1,
    /**
     * Use Alternate Bounding Volumes
     */
    CM_USE_ABV = 2,
    /**
     * No Test
     */
    CM_NOTEST = 3,
    /**
     * Use NiBound
     */
    CM_USE_NIBOUND = 4,
};

}
