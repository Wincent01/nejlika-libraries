#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiSingleInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A controller that interpolates floating point numbers?
 *     
 */
class NiBoolInterpController : public NiSingleInterpController
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
