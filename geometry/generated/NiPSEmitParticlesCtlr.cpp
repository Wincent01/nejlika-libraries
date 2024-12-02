#include "NiPSEmitParticlesCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitParticlesCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysEmitterCtlr::Read(reader, version, user, arg);

}

void NiPSEmitParticlesCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysEmitterCtlr::Write(writer, version, user, arg);

}
