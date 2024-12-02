#include "NiSkinData.hpp"

using namespace nejlika::geometry;

void NiSkinData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_SkinTransform.Read(reader, version, user, 0);

    m_NumBones = reader.Read<uint>();

    if (version >= VERSION_NUMBER(4, 0, 0, 2) && version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_SkinPartition.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        m_HasVertexWeights = reader.Read<byte>();
    }
    else
    {
        m_HasVertexWeights = 1;
    }

    m_BoneList.resize(m_NumBones);
    for (uint32_t i = 0; i < m_BoneList.size(); i++)
    {
        m_BoneList[i].Read(reader, version, user, m_HasVertexWeights);
    }

}

void NiSkinData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_SkinTransform.Write(writer, version, user, 0);

    writer.Write(m_NumBones);

    if (version >= VERSION_NUMBER(4, 0, 0, 2) && version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_SkinPartition.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        writer.Write(m_HasVertexWeights);
    }
    else
    {
        //writer.Write(1);
    }

    for (uint32_t i = 0; i < m_BoneList.size(); i++)
    {
        m_BoneList[i].Write(writer, version, user, m_HasVertexWeights);
    }

}
