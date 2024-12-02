#include "BSDecalPlacementVectorExtraData.hpp"

using namespace nejlika::geometry;

void BSDecalPlacementVectorExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_NumVectorBlocks = reader.Read<short>();

    m_VectorBlocks.resize(m_NumVectorBlocks);
    for (uint32_t i = 0; i < m_VectorBlocks.size(); i++)
    {
        m_VectorBlocks[i].Read(reader, version, user, 0);
    }

}

void BSDecalPlacementVectorExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_NumVectorBlocks);

    for (uint32_t i = 0; i < m_VectorBlocks.size(); i++)
    {
        m_VectorBlocks[i].Write(writer, version, user, 0);
    }

}
