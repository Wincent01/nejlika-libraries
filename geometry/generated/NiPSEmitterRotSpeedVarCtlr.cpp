#include "NiPSEmitterRotSpeedVarCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitterRotSpeedVarCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSEmitterRotSpeedCtlr::Read(reader, version, user, arg);

}

void NiPSEmitterRotSpeedVarCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSEmitterRotSpeedCtlr::Write(writer, version, user, arg);

}
