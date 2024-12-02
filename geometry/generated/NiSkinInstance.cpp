#include "NiSkinInstance.hpp"

using namespace nejlika::geometry;

void NiSkinInstance::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_SkinPartition.Read(reader, version, user, 0);
    }

    m_SkeletonRoot.Read(reader, version, user, 0);

    m_NumBones = reader.Read<uint>();

    m_Bones.resize(m_NumBones);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Read(reader, version, user, 0);
    }

}

void NiSkinInstance::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_SkinPartition.Write(writer, version, user, 0);
    }

    m_SkeletonRoot.Write(writer, version, user, 0);

    writer.Write(m_NumBones);

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Write(writer, version, user, 0);
    }

}
