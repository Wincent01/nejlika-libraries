#include "NiBoolTimelineInterpolator.hpp"

using namespace nejlika::geometry;

void NiBoolTimelineInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBoolInterpolator::Read(reader, version, user, arg);

}

void NiBoolTimelineInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBoolInterpolator::Write(writer, version, user, arg);

}
