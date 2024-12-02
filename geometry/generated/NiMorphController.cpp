#include "NiMorphController.hpp"

using namespace nejlika::geometry;

void NiMorphController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

}

void NiMorphController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

}
