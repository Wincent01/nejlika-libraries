#include "AdditionalDataBlock.hpp"

using namespace nejlika::geometry;

void AdditionalDataBlock::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_HasData = reader.Read<bool>();

    if (m_HasData)
    {
        m_BlockSize = reader.Read<int>();
    }

    if (m_HasData)
    {
        m_NumBlocks = reader.Read<int>();
    }

    if (m_HasData)
    {
        m_BlockOffsets.resize(m_NumBlocks);
        for (uint32_t i = 0; i < m_BlockOffsets.size(); i++)
        {
            m_BlockOffsets[i] = reader.Read<int>();
        }
    }

    if (m_HasData)
    {
        m_NumData = reader.Read<int>();
    }

    if (m_HasData)
    {
        m_DataSizes.resize(m_NumData);
        for (uint32_t i = 0; i < m_DataSizes.size(); i++)
        {
            m_DataSizes[i] = reader.Read<int>();
        }
    }

    if (m_HasData)
    {
        m_Data.resize(m_NumData);
        for (uint32_t i = 0; i < m_Data.size(); i++)
        {
            m_Data[i].resize(m_BlockSize);
            for (uint32_t j = 0; j < m_Data[i].size(); j++)
            {
                m_Data[i][j] = reader.Read<byte>();
            }
        }
    }

}

void AdditionalDataBlock::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_HasData);

    if (m_HasData)
    {
        writer.Write(m_BlockSize);
    }

    if (m_HasData)
    {
        writer.Write(m_NumBlocks);
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_BlockOffsets.size(); i++)
        {
            writer.Write(m_BlockOffsets[i]);
        }
    }

    if (m_HasData)
    {
        writer.Write(m_NumData);
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_DataSizes.size(); i++)
        {
            writer.Write(m_DataSizes[i]);
        }
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_Data.size(); i++)
        {
            for (uint32_t j = 0; j < m_Data[i].size(); j++)
            {
                writer.Write(m_Data[i][j]);
            }
        }
    }

}
