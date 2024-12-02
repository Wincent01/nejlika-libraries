#include "NiPSEmitterRotAngleVarCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitterRotAngleVarCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSEmitterRotAngleCtlr::Read(reader, version, user, arg);

}

void NiPSEmitterRotAngleVarCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSEmitterRotAngleCtlr::Write(writer, version, user, arg);

}
