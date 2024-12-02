#include "NiFloatInterpController.hpp"

using namespace nejlika::geometry;

void NiFloatInterpController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSingleInterpController::Read(reader, version, user, arg);

}

void NiFloatInterpController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSingleInterpController::Write(writer, version, user, arg);

}
