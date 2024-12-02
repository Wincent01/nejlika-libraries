#include "NiBSPArrayController.hpp"

using namespace nejlika::geometry;

void NiBSPArrayController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleSystemController::Read(reader, version, user, arg);

}

void NiBSPArrayController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleSystemController::Write(writer, version, user, arg);

}
