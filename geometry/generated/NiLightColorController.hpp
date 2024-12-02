#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPoint3InterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Light color animation controller.
 *     
 */
class NiLightColorController : public NiPoint3InterpController
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
