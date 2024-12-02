#include "BSPackedAdditionalDataBlock.hpp"

using namespace nejlika::geometry;

void BSPackedAdditionalDataBlock::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_HasData = reader.Read<bool>();

    if (m_HasData)
    {
        m_NumTotalBytes = reader.Read<int>();
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
        m_NumAtoms = reader.Read<int>();
    }

    if (m_HasData)
    {
        m_AtomSizes.resize(m_NumAtoms);
        for (uint32_t i = 0; i < m_AtomSizes.size(); i++)
        {
            m_AtomSizes[i] = reader.Read<int>();
        }
    }

    if (m_HasData)
    {
        m_Data.resize(m_NumTotalBytes);
        for (uint32_t i = 0; i < m_Data.size(); i++)
        {
            m_Data[i] = reader.Read<byte>();
        }
    }

    m_UnknownInt1 = reader.Read<int>();

    m_NumTotalBytesPerElement = reader.Read<int>();

}

void BSPackedAdditionalDataBlock::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_HasData);

    if (m_HasData)
    {
        writer.Write(m_NumTotalBytes);
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
        writer.Write(m_NumAtoms);
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_AtomSizes.size(); i++)
        {
            writer.Write(m_AtomSizes[i]);
        }
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_Data.size(); i++)
        {
            writer.Write(m_Data[i]);
        }
    }

    writer.Write(m_UnknownInt1);

    writer.Write(m_NumTotalBytesPerElement);

}
