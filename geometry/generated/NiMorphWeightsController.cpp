#include "NiMorphWeightsController.hpp"

using namespace nejlika::geometry;

void NiMorphWeightsController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

    m_Unknown2 = reader.Read<int>();

    m_NumInterpolators = reader.Read<uint>();

    m_Interpolators.resize(m_NumInterpolators);
    for (uint32_t i = 0; i < m_Interpolators.size(); i++)
    {
        m_Interpolators[i].Read(reader, version, user, 0);
    }

    m_NumTargets = reader.Read<uint>();

    m_TargetNames.resize(m_NumTargets);
    for (uint32_t i = 0; i < m_TargetNames.size(); i++)
    {
        m_TargetNames[i].Read(reader, version, user, 0);
    }

}

void NiMorphWeightsController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

    writer.Write(m_Unknown2);

    writer.Write(m_NumInterpolators);

    for (uint32_t i = 0; i < m_Interpolators.size(); i++)
    {
        m_Interpolators[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumTargets);

    for (uint32_t i = 0; i < m_TargetNames.size(); i++)
    {
        m_TargetNames[i].Write(writer, version, user, 0);
    }

}
