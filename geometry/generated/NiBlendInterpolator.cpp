#include "NiBlendInterpolator.hpp"

using namespace nejlika::geometry;

void NiBlendInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpolator::Read(reader, version, user, arg);

    m_UnknownShort = reader.Read<ushort>();

    m_UnknownInt = reader.Read<uint>();

}

void NiBlendInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpolator::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort);

    writer.Write(m_UnknownInt);

}
