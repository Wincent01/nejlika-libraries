#include "BSSegment.hpp"

using namespace nejlika::geometry;

void BSSegment::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_InternalIndex = reader.Read<int>();

    m_Flags = reader.Read<BSSegmentFlags>();

    m_UnknownByte1 = reader.Read<byte>();

}

void BSSegment::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_InternalIndex);

    writer.Write(m_Flags);

    writer.Write(m_UnknownByte1);

}
