#include "NiPSSimulatorMeshAlignStep.hpp"

using namespace nejlika::geometry;

void NiPSSimulatorMeshAlignStep::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSimulatorStep::Read(reader, version, user, arg);

    m_NumRotationKeys = reader.Read<byte>();

    m_RotationKeys.resize(m_NumRotationKeys);
    for (uint32_t i = 0; i < m_RotationKeys.size(); i++)
    {
        m_RotationKeys[i].Read(reader, version, user, 1);
    }

    m_RotationLoopBehavior = reader.Read<PSLoopBehavior>();

}

void NiPSSimulatorMeshAlignStep::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSimulatorStep::Write(writer, version, user, arg);

    writer.Write(m_NumRotationKeys);

    for (uint32_t i = 0; i < m_RotationKeys.size(); i++)
    {
        m_RotationKeys[i].Write(writer, version, user, 1);
    }

    writer.Write(m_RotationLoopBehavior);

}
