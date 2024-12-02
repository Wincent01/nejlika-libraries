#include "NiMaterialColorController.hpp"

using namespace nejlika::geometry;

void NiMaterialColorController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPoint3InterpController::Read(reader, version, user, arg);

}

void NiMaterialColorController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPoint3InterpController::Write(writer, version, user, arg);

}
