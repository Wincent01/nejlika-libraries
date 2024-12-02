#include "BSTreeNode.hpp"

using namespace nejlika::geometry;

void BSTreeNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_NumBones1 = reader.Read<uint>();

    m_Bones1.resize(m_NumBones1);
    for (uint32_t i = 0; i < m_Bones1.size(); i++)
    {
        m_Bones1[i].Read(reader, version, user, 0);
    }

    m_NumBones2 = reader.Read<uint>();

    m_Bones.resize(m_NumBones2);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Read(reader, version, user, 0);
    }

}

void BSTreeNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_NumBones1);

    for (uint32_t i = 0; i < m_Bones1.size(); i++)
    {
        m_Bones1[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumBones2);

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Write(writer, version, user, 0);
    }

}
