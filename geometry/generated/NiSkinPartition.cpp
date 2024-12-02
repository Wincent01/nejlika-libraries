#include "NiSkinPartition.hpp"

using namespace nejlika::geometry;

void NiSkinPartition::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumSkinPartitionBlocks = reader.Read<uint>();

    m_SkinPartitionBlocks.resize(m_NumSkinPartitionBlocks);
    for (uint32_t i = 0; i < m_SkinPartitionBlocks.size(); i++)
    {
        m_SkinPartitionBlocks[i].Read(reader, version, user, 0);
    }

}

void NiSkinPartition::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumSkinPartitionBlocks);

    for (uint32_t i = 0; i < m_SkinPartitionBlocks.size(); i++)
    {
        m_SkinPartitionBlocks[i].Write(writer, version, user, 0);
    }

}
