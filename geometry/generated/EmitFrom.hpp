#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Controls which parts of the mesh that the particles are emitted from.
 *         
 */
enum EmitFrom : uint
{
    /**
     * Emit particles from the vertices of the mesh.
     */
    EMIT_FROM_VERTICES = 0,
    /**
     * Emit particles from the center of the faces of the mesh.
     */
    EMIT_FROM_FACE_CENTER = 1,
    /**
     * Emit particles from the center of the edges of the mesh.
     */
    EMIT_FROM_EDGE_CENTER = 2,
    /**
     * Perhaps randomly emit particles from anywhere on the faces of the mesh?
     */
    EMIT_FROM_FACE_SURFACE = 3,
    /**
     * Perhaps randomly emit particles from anywhere on the edges of the mesh?
     */
    EMIT_FROM_EDGE_SURFACE = 4,
};

}
