#include "NiPSEmitterPlanarAngleVarCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitterPlanarAngleVarCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSEmitterPlanarAngleCtlr::Read(reader, version, user, arg);

}

void NiPSEmitterPlanarAngleVarCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSEmitterPlanarAngleCtlr::Write(writer, version, user, arg);

}
