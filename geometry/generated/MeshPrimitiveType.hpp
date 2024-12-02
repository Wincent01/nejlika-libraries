#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Describes the type of primitives stored in a mesh object.
 *         
 */
enum MeshPrimitiveType : uint
{
    /**
     * Triangle primitive type.
     */
    MESH_PRIMITIVE_TRIANGLES = 0,
    /**
     * Triangle strip primitive type.
     */
    MESH_PRIMITIVE_TRISTRIPS = 1,
    /**
     * Line strip primitive type.
     */
    MESH_PRIMITIVE_LINESTRIPS = 2,
    /**
     * Quadrilateral primitive type.
     */
    MESH_PRIMITIVE_QUADS = 3,
    /**
     * Point primitive type.
     */
    MESH_PRIMITIVE_POINTS = 4,
};

}
