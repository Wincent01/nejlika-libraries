#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Used by NiGeometryData to control the volatility of the mesh.  While they appear to be flags they behave as an enum.
 *         
 */
enum ConsistencyType : ushort
{
    /**
     * Mutable Mesh
     */
    CT_MUTABLE = 0,
    /**
     * Static Mesh
     */
    CT_STATIC = 16384,
    /**
     * Volatile Mesh
     */
    CT_VOLATILE = 32768,
};

}
