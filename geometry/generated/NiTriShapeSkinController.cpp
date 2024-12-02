#include "NiTriShapeSkinController.hpp"

using namespace nejlika::geometry;

void NiTriShapeSkinController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_NumBones = reader.Read<uint>();

    m_VertexCounts.resize(m_NumBones);
    for (uint32_t i = 0; i < m_VertexCounts.size(); i++)
    {
        m_VertexCounts[i] = reader.Read<uint>();
    }

    m_Bones.resize(m_NumBones);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Read(reader, version, user, 0);
    }

    m_BoneData.resize(m_NumBones);
    for (uint32_t i = 0; i < m_BoneData.size(); i++)
    {
        m_BoneData[i].resize(m_VertexCounts[i]);
        for (uint32_t j = 0; j < m_BoneData[i].size(); j++)
        {
            m_BoneData[i][j].Read(reader, version, user, 0);
        }
    }

}

void NiTriShapeSkinController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_NumBones);

    for (uint32_t i = 0; i < m_VertexCounts.size(); i++)
    {
        writer.Write(m_VertexCounts[i]);
    }

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_BoneData.size(); i++)
    {
        for (uint32_t j = 0; j < m_BoneData[i].size(); j++)
        {
            m_BoneData[i][j].Write(writer, version, user, 0);
        }
    }

}
