#include "NiTransformData.hpp"

using namespace nejlika::geometry;

void NiTransformData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyframeData::Read(reader, version, user, arg);

}

void NiTransformData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyframeData::Write(writer, version, user, arg);

}
