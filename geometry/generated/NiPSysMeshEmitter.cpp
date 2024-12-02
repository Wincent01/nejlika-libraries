#include "NiPSysMeshEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysMeshEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysEmitter::Read(reader, version, user, arg);

    m_NumEmitterMeshes = reader.Read<uint>();

    m_EmitterMeshes.resize(m_NumEmitterMeshes);
    for (uint32_t i = 0; i < m_EmitterMeshes.size(); i++)
    {
        m_EmitterMeshes[i].Read(reader, version, user, 0);
    }

    m_InitialVelocityType = reader.Read<VelocityType>();

    m_EmissionType = reader.Read<EmitFrom>();

    m_EmissionAxis.Read(reader, version, user, 0);

}

void NiPSysMeshEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysEmitter::Write(writer, version, user, arg);

    writer.Write(m_NumEmitterMeshes);

    for (uint32_t i = 0; i < m_EmitterMeshes.size(); i++)
    {
        m_EmitterMeshes[i].Write(writer, version, user, 0);
    }

    writer.Write(m_InitialVelocityType);

    writer.Write(m_EmissionType);

    m_EmissionAxis.Write(writer, version, user, 0);

}
