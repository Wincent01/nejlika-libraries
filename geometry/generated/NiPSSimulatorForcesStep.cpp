#include "NiPSSimulatorForcesStep.hpp"

using namespace nejlika::geometry;

void NiPSSimulatorForcesStep::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSimulatorStep::Read(reader, version, user, arg);

    m_NumForces = reader.Read<uint>();

    m_Forces.resize(m_NumForces);
    for (uint32_t i = 0; i < m_Forces.size(); i++)
    {
        m_Forces[i].Read(reader, version, user, 0);
    }

}

void NiPSSimulatorForcesStep::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSimulatorStep::Write(writer, version, user, arg);

    writer.Write(m_NumForces);

    for (uint32_t i = 0; i < m_Forces.size(); i++)
    {
        m_Forces[i].Write(writer, version, user, 0);
    }

}
