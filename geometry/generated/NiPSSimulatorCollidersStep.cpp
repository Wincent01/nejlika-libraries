#include "NiPSSimulatorCollidersStep.hpp"

using namespace nejlika::geometry;

void NiPSSimulatorCollidersStep::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSimulatorStep::Read(reader, version, user, arg);

    m_NumColliders = reader.Read<uint>();

    m_Colliders.resize(m_NumColliders);
    for (uint32_t i = 0; i < m_Colliders.size(); i++)
    {
        m_Colliders[i].Read(reader, version, user, 0);
    }

}

void NiPSSimulatorCollidersStep::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSimulatorStep::Write(writer, version, user, arg);

    writer.Write(m_NumColliders);

    for (uint32_t i = 0; i < m_Colliders.size(); i++)
    {
        m_Colliders[i].Write(writer, version, user, 0);
    }

}
