#include "ChannelData.hpp"

using namespace nejlika::geometry;

void ChannelData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Type = reader.Read<ChannelType>();

    m_Convention = reader.Read<ChannelConvention>();

    m_BitsPerChannel = reader.Read<byte>();

    m_UnknownByte1 = reader.Read<byte>();

}

void ChannelData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Type);

    writer.Write(m_Convention);

    writer.Write(m_BitsPerChannel);

    writer.Write(m_UnknownByte1);

}
