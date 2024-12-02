#include "Animation.hpp"

using namespace nejlika::geometry;

void Animation::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_EventCode = reader.Read<int>();

    if (version <= VERSION_NUMBER(0, 0, 0, 16927488))
    {
        m_Name.Read(reader, version, user, 0);
    }

    m_KFFileName.Read(reader, version, user, 0);

    m_Index = reader.Read<int>();

    m_NumTransitions = reader.Read<int>();

    m_Transitions.resize(m_NumTransitions);
    for (uint32_t i = 0; i < m_Transitions.size(); i++)
    {
        m_Transitions[i].Read(reader, version, user, 0);
    }

}

void Animation::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_EventCode);

    if (version <= VERSION_NUMBER(0, 0, 0, 16927488))
    {
        m_Name.Write(writer, version, user, 0);
    }

    m_KFFileName.Write(writer, version, user, 0);

    writer.Write(m_Index);

    writer.Write(m_NumTransitions);

    for (uint32_t i = 0; i < m_Transitions.size(); i++)
    {
        m_Transitions[i].Write(writer, version, user, 0);
    }

}
