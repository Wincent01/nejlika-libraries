#include "NiTransformController.hpp"

using namespace nejlika::geometry;

void NiTransformController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyframeController::Read(reader, version, user, arg);

}

void NiTransformController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyframeController::Write(writer, version, user, arg);

}
