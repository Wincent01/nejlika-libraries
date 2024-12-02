#include "NiBSplineCompTransformEvaluator.hpp"

using namespace nejlika::geometry;

void NiBSplineCompTransformEvaluator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

}

void NiBSplineCompTransformEvaluator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

}
