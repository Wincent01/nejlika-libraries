#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSSimulatorStep.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Encapsulates a floodgate kernel that updates particle positions and ages. As indicated by its name, this step should be attached last in the NiPSSimulator mesh modifier.
 *     
 */
class NiPSSimulatorFinalStep : public NiPSSimulatorStep
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
