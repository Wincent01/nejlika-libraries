#include "ByteMatrix.hpp"

using namespace nejlika::geometry;

void ByteMatrix::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_DataSize1 = reader.Read<uint>();

    m_DataSize2 = reader.Read<uint>();

    m_Data.resize(m_DataSize2);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i].resize(m_DataSize1);
        for (uint32_t j = 0; j < m_Data[i].size(); j++)
        {
            m_Data[i][j] = reader.Read<byte>();
        }
    }

}

void ByteMatrix::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_DataSize1);

    writer.Write(m_DataSize2);

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        for (uint32_t j = 0; j < m_Data[i].size(); j++)
        {
            writer.Write(m_Data[i][j]);
        }
    }

}
