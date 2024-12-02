#include "NiKeyBasedInterpolator.hpp"

using namespace nejlika::geometry;

void NiKeyBasedInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpolator::Read(reader, version, user, arg);

}

void NiKeyBasedInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpolator::Write(writer, version, user, arg);

}
