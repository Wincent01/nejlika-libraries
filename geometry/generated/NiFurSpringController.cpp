#include "NiFurSpringController.hpp"

using namespace nejlika::geometry;

void NiFurSpringController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_UnknownFloat = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_NumBones = reader.Read<uint>();

    m_Bones.resize(m_NumBones);
    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Read(reader, version, user, 0);
    }

    m_NumBones2 = reader.Read<uint>();

    m_Bones2.resize(m_NumBones2);
    for (uint32_t i = 0; i < m_Bones2.size(); i++)
    {
        m_Bones2[i].Read(reader, version, user, 0);
    }

}

void NiFurSpringController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_NumBones);

    for (uint32_t i = 0; i < m_Bones.size(); i++)
    {
        m_Bones[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumBones2);

    for (uint32_t i = 0; i < m_Bones2.size(); i++)
    {
        m_Bones2[i].Write(writer, version, user, 0);
    }

}
