#include "BSRefractionStrengthController.hpp"

using namespace nejlika::geometry;

void BSRefractionStrengthController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

}

void BSRefractionStrengthController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

}
