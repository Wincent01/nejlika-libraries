#include "NiKeyframeData.hpp"

using namespace nejlika::geometry;

void NiKeyframeData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumRotationKeys = reader.Read<uint>();

    if (m_NumRotationKeys!= 0)
    {
        m_RotationType = reader.Read<KeyType>();
    }

    if (m_RotationType!= 4)
    {
        m_QuaternionKeys.resize(m_NumRotationKeys);
        for (uint32_t i = 0; i < m_QuaternionKeys.size(); i++)
        {
            m_QuaternionKeys[i].Read(reader, version, user, m_RotationType);
        }
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0) && m_RotationType== 4)
    {
        m_UnknownFloat = reader.Read<float>();
    }

    if (m_RotationType== 4)
    {
        m_XYZRotations.resize(3);
        for (uint32_t i = 0; i < m_XYZRotations.size(); i++)
        {
            m_XYZRotations[i].Read(reader, version, user, 0);
        }
    }

    m_Translations.Read(reader, version, user, 0);

    m_Scales.Read(reader, version, user, 0);

}

void NiKeyframeData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumRotationKeys);

    if (m_NumRotationKeys!= 0)
    {
        writer.Write(m_RotationType);
    }

    if (m_RotationType!= 4)
    {
        for (uint32_t i = 0; i < m_QuaternionKeys.size(); i++)
        {
            m_QuaternionKeys[i].Write(writer, version, user, m_RotationType);
        }
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0) && m_RotationType== 4)
    {
        writer.Write(m_UnknownFloat);
    }

    if (m_RotationType== 4)
    {
        for (uint32_t i = 0; i < m_XYZRotations.size(); i++)
        {
            m_XYZRotations[i].Write(writer, version, user, 0);
        }
    }

    m_Translations.Write(writer, version, user, 0);

    m_Scales.Write(writer, version, user, 0);

}
