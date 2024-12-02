#include "NiMultiTargetTransformController.hpp"

using namespace nejlika::geometry;

void NiMultiTargetTransformController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

    m_NumExtraTargets = reader.Read<ushort>();

    m_ExtraTargets.resize(m_NumExtraTargets);
    for (uint32_t i = 0; i < m_ExtraTargets.size(); i++)
    {
        m_ExtraTargets[i].Read(reader, version, user, 0);
    }

}

void NiMultiTargetTransformController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

    writer.Write(m_NumExtraTargets);

    for (uint32_t i = 0; i < m_ExtraTargets.size(); i++)
    {
        m_ExtraTargets[i].Write(writer, version, user, 0);
    }

}
