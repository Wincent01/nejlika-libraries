#include "AdditionalDataInfo.hpp"

using namespace nejlika::geometry;

void AdditionalDataInfo::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_DataType = reader.Read<int>();

    m_NumChannelBytesPerElement = reader.Read<int>();

    m_NumChannelBytes = reader.Read<int>();

    m_NumTotalBytesPerElement = reader.Read<int>();

    m_BlockIndex = reader.Read<int>();

    m_ChannelOffset = reader.Read<int>();

    m_UnknownByte1 = reader.Read<byte>();

}

void AdditionalDataInfo::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_DataType);

    writer.Write(m_NumChannelBytesPerElement);

    writer.Write(m_NumChannelBytes);

    writer.Write(m_NumTotalBytesPerElement);

    writer.Write(m_BlockIndex);

    writer.Write(m_ChannelOffset);

    writer.Write(m_UnknownByte1);

}
