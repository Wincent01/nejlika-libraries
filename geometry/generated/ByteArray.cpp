#include "ByteArray.hpp"

using namespace nejlika::geometry;

void ByteArray::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_DataSize = reader.Read<uint>();

    m_Data.resize(m_DataSize);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i] = reader.Read<byte>();
    }

}

void ByteArray::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_DataSize);

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        writer.Write(m_Data[i]);
    }

}
