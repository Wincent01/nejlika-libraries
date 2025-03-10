#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifierCtlr.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system modifier controller that deals with boolean data?
 *     
 */
class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
