#include "NiMeshModifier.hpp"

using namespace nejlika::geometry;

void NiMeshModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumSubmitPoints = reader.Read<uint>();

    m_SubmitPoints.resize(m_NumSubmitPoints);
    for (uint32_t i = 0; i < m_SubmitPoints.size(); i++)
    {
        m_SubmitPoints[i] = reader.Read<SyncPoint>();
    }

    m_NumCompletePoints = reader.Read<uint>();

    m_CompletePoints.resize(m_NumCompletePoints);
    for (uint32_t i = 0; i < m_CompletePoints.size(); i++)
    {
        m_CompletePoints[i] = reader.Read<SyncPoint>();
    }

}

void NiMeshModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumSubmitPoints);

    for (uint32_t i = 0; i < m_SubmitPoints.size(); i++)
    {
        writer.Write(m_SubmitPoints[i]);
    }

    writer.Write(m_NumCompletePoints);

    for (uint32_t i = 0; i < m_CompletePoints.size(); i++)
    {
        writer.Write(m_CompletePoints[i]);
    }

}
