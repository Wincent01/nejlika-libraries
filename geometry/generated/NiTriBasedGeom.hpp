#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiGeometry.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes a mesh, built from triangles.
 *     
 */
class NiTriBasedGeom : public NiGeometry
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
