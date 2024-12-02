#include "NiBSplineFloatInterpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineFloatInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplineInterpolator::Read(reader, version, user, arg);

}

void NiBSplineFloatInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplineInterpolator::Write(writer, version, user, arg);

}
