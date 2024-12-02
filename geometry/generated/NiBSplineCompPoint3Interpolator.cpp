#include "NiBSplineCompPoint3Interpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineCompPoint3Interpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplinePoint3Interpolator::Read(reader, version, user, arg);

}

void NiBSplineCompPoint3Interpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplinePoint3Interpolator::Write(writer, version, user, arg);

}
