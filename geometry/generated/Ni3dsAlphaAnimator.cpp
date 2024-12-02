#include "Ni3dsAlphaAnimator.hpp"

using namespace nejlika::geometry;

void Ni3dsAlphaAnimator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1.resize(40);
    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        m_Unknown1[i] = reader.Read<byte>();
    }

    m_Parent.Read(reader, version, user, 0);

    m_Num1 = reader.Read<uint>();

    m_Num2 = reader.Read<uint>();

    m_Unknown2.resize(m_Num1);
    for (uint32_t i = 0; i < m_Unknown2.size(); i++)
    {
        m_Unknown2[i].resize(m_Num2);
        for (uint32_t j = 0; j < m_Unknown2[i].size(); j++)
        {
            m_Unknown2[i][j].resize(2);
            for (uint32_t k = 0; k < m_Unknown2[i][j].size(); k++)
            {
                m_Unknown2[i][j][k] = reader.Read<uint>();
            }
        }
    }

}

void Ni3dsAlphaAnimator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        writer.Write(m_Unknown1[i]);
    }

    m_Parent.Write(writer, version, user, 0);

    writer.Write(m_Num1);

    writer.Write(m_Num2);

    for (uint32_t i = 0; i < m_Unknown2.size(); i++)
    {
        for (uint32_t j = 0; j < m_Unknown2[i].size(); j++)
        {
            for (uint32_t k = 0; k < m_Unknown2[i][j].size(); k++)
            {
                writer.Write(m_Unknown2[i][j][k]);
            }
        }
    }

}
