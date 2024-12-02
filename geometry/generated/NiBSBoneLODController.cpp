#include "NiBSBoneLODController.hpp"

using namespace nejlika::geometry;

void NiBSBoneLODController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBoneLODController::Read(reader, version, user, arg);

}

void NiBSBoneLODController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBoneLODController::Write(writer, version, user, arg);

}
