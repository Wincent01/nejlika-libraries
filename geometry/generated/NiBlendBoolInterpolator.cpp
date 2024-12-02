#include "NiBlendBoolInterpolator.hpp"

using namespace nejlika::geometry;

void NiBlendBoolInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBlendInterpolator::Read(reader, version, user, arg);

    m_BoolValue = reader.Read<byte>();

}

void NiBlendBoolInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBlendInterpolator::Write(writer, version, user, arg);

    writer.Write(m_BoolValue);

}
