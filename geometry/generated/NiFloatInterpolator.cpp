#include "NiFloatInterpolator.hpp"

using namespace nejlika::geometry;

void NiFloatInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyBasedInterpolator::Read(reader, version, user, arg);

    m_FloatValue = reader.Read<float>();

    m_Data.Read(reader, version, user, 0);

}

void NiFloatInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyBasedInterpolator::Write(writer, version, user, arg);

    writer.Write(m_FloatValue);

    m_Data.Write(writer, version, user, 0);

}
