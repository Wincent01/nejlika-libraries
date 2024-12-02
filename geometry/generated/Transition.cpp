#include "Transition.hpp"

using namespace nejlika::geometry;

void Transition::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Animation = reader.Read<int>();

    m_Type = reader.Read<int>();

    if (m_Type == 4) {
        return;
    }

    if (m_Type!= 5)
    {
        m_Duration = reader.Read<float>();
    }

    if (m_Type!= 5)
    {
        m_NumIntermediateAnims = reader.Read<int>();
    }

    if (m_Type!= 5)
    {
        m_IntermediateAnims.resize(m_NumIntermediateAnims);
        for (uint32_t i = 0; i < m_IntermediateAnims.size(); i++)
        {
            m_IntermediateAnims[i].Read(reader, version, user, 0);
        }
    }

    if (m_Type!= 5)
    {
        m_NumTextKeyPairs = reader.Read<int>();
    }

}

void Transition::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Animation);

    writer.Write(m_Type);

    if (m_Type == 4) {
        return;
    }

    if (m_Type!= 5)
    {
        writer.Write(m_Duration);
    }

    if (m_Type!= 5)
    {
        writer.Write(m_NumIntermediateAnims);
    }

    if (m_Type!= 5)
    {
        for (uint32_t i = 0; i < m_IntermediateAnims.size(); i++)
        {
            m_IntermediateAnims[i].Write(writer, version, user, 0);
        }
    }

    if (m_Type!= 5)
    {
        writer.Write(m_NumTextKeyPairs);
    }

}
