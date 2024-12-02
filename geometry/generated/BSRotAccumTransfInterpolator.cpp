#include "BSRotAccumTransfInterpolator.hpp"

using namespace nejlika::geometry;

void BSRotAccumTransfInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTransformInterpolator::Read(reader, version, user, arg);

}

void BSRotAccumTransfInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTransformInterpolator::Write(writer, version, user, arg);

}
