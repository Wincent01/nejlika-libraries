#include "NiBlendTransformInterpolator.hpp"

using namespace nejlika::geometry;

void NiBlendTransformInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBlendInterpolator::Read(reader, version, user, arg);

}

void NiBlendTransformInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBlendInterpolator::Write(writer, version, user, arg);

}
