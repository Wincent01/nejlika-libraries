#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPoint3InterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for material color. Flags are used for color selection in versions below 10.1.0.0.
 *         
 *         Bits 4-5: Target Color (00 = Ambient, 01 = Diffuse, 10 = Specular, 11 = Emissive)
 *     
 */
class NiMaterialColorController : public NiPoint3InterpController
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
