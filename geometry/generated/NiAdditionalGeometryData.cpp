#include "NiAdditionalGeometryData.hpp"

using namespace nejlika::geometry;

void NiAdditionalGeometryData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    AbstractAdditionalGeometryData::Read(reader, version, user, arg);

    m_NumVertices = reader.Read<ushort>();

    m_NumBlockInfos = reader.Read<uint>();

    m_BlockInfos.resize(m_NumBlockInfos);
    for (uint32_t i = 0; i < m_BlockInfos.size(); i++)
    {
        m_BlockInfos[i].Read(reader, version, user, 0);
    }

    m_NumBlocks = reader.Read<int>();

    m_Blocks.resize(m_NumBlocks);
    for (uint32_t i = 0; i < m_Blocks.size(); i++)
    {
        m_Blocks[i].Read(reader, version, user, 0);
    }

}

void NiAdditionalGeometryData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    AbstractAdditionalGeometryData::Write(writer, version, user, arg);

    writer.Write(m_NumVertices);

    writer.Write(m_NumBlockInfos);

    for (uint32_t i = 0; i < m_BlockInfos.size(); i++)
    {
        m_BlockInfos[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumBlocks);

    for (uint32_t i = 0; i < m_Blocks.size(); i++)
    {
        m_Blocks[i].Write(writer, version, user, 0);
    }

}
