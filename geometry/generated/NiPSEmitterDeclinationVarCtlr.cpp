#include "NiPSEmitterDeclinationVarCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitterDeclinationVarCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSEmitterDeclinationCtlr::Read(reader, version, user, arg);

}

void NiPSEmitterDeclinationVarCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSEmitterDeclinationCtlr::Write(writer, version, user, arg);

}
