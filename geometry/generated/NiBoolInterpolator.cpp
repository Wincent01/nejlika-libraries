#include "NiBoolInterpolator.hpp"

using namespace nejlika::geometry;

void NiBoolInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyBasedInterpolator::Read(reader, version, user, arg);

    m_BoolValue = reader.Read<bool>();

    m_Data.Read(reader, version, user, 0);

}

void NiBoolInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyBasedInterpolator::Write(writer, version, user, arg);

    writer.Write(m_BoolValue);

    m_Data.Write(writer, version, user, 0);

}
