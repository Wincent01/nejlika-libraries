#include "NiSkinningMeshModifier.hpp"

using namespace nejlika::geometry;

void NiSkinningMeshModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiMeshModifier::Read(reader, version, user, arg);

    m_Flags = reader.Read<ushort>();

    m_SkeletonRoot.Read(reader, version, user, 0);

    m_SkeletonTransform.Read(reader, version, user, 0);

    m_NumBones = reader.Read<uint>();

    m_Bones.resize(m_NumBones);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Read(reader, version, user, 0);
    }

    m_BoneTransforms.resize(m_NumBones);
    for (uint32_t i = 0; i < m_BoneTransforms.size(); i++)
    {
        m_BoneTransforms[i].Read(reader, version, user, 0);
    }

    if ((m_Flags& 2)!=0)
    {
        m_BoneBounds.resize(m_NumBones);
        for (uint32_t i = 0; i < m_BoneBounds.size(); i++)
        {
            m_BoneBounds[i].Read(reader, version, user, 0);
        }
    }

}

void NiSkinningMeshModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiMeshModifier::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    m_SkeletonRoot.Write(writer, version, user, 0);

    m_SkeletonTransform.Write(writer, version, user, 0);

    writer.Write(m_NumBones);

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_BoneTransforms.size(); i++)
    {
        m_BoneTransforms[i].Write(writer, version, user, 0);
    }

    if ((m_Flags& 2)!=0)
    {
        for (uint32_t i = 0; i < m_BoneBounds.size(); i++)
        {
            m_BoneBounds[i].Write(writer, version, user, 0);
        }
    }

}
