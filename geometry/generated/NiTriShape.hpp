#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeom.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A shape node that refers to singular triangle data.
 *     
 */
class NiTriShape : public NiTriBasedGeom
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
