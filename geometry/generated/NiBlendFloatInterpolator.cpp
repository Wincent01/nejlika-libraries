#include "NiBlendFloatInterpolator.hpp"

using namespace nejlika::geometry;

void NiBlendFloatInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBlendInterpolator::Read(reader, version, user, arg);

    m_FloatValue = reader.Read<float>();

}

void NiBlendFloatInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBlendInterpolator::Write(writer, version, user, arg);

    writer.Write(m_FloatValue);

}
