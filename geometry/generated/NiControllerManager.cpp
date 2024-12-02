#include "NiControllerManager.hpp"

using namespace nejlika::geometry;

void NiControllerManager::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_Cumulative = reader.Read<bool>();

    m_NumControllerSequences = reader.Read<uint>();

    m_ControllerSequences.resize(m_NumControllerSequences);
    for (uint32_t i = 0; i < m_ControllerSequences.size(); i++)
    {
        m_ControllerSequences[i].Read(reader, version, user, 0);
    }

    m_ObjectPalette.Read(reader, version, user, 0);

}

void NiControllerManager::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_Cumulative);

    writer.Write(m_NumControllerSequences);

    for (uint32_t i = 0; i < m_ControllerSequences.size(); i++)
    {
        m_ControllerSequences[i].Write(writer, version, user, 0);
    }

    m_ObjectPalette.Write(writer, version, user, 0);

}
