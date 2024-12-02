#include "NiPSSimulator.hpp"

using namespace nejlika::geometry;

void NiPSSimulator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiMeshModifier::Read(reader, version, user, arg);

    m_NumSimulationSteps = reader.Read<uint>();

    m_SimulationSteps.resize(m_NumSimulationSteps);
    for (uint32_t i = 0; i < m_SimulationSteps.size(); i++)
    {
        m_SimulationSteps[i].Read(reader, version, user, 0);
    }

}

void NiPSSimulator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiMeshModifier::Write(writer, version, user, arg);

    writer.Write(m_NumSimulationSteps);

    for (uint32_t i = 0; i < m_SimulationSteps.size(); i++)
    {
        m_SimulationSteps[i].Write(writer, version, user, 0);
    }

}
