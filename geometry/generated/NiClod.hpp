#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeom.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A shape node that holds continuous level of detail information.
 *         Seems to be specific to Freedom Force.
 *     
 */
class NiClod : public NiTriBasedGeom
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
