#include "NiPSSimulatorFinalStep.hpp"

using namespace nejlika::geometry;

void NiPSSimulatorFinalStep::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSimulatorStep::Read(reader, version, user, arg);

}

void NiPSSimulatorFinalStep::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSimulatorStep::Write(writer, version, user, arg);

}
