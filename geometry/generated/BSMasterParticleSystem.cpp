#include "BSMasterParticleSystem.hpp"

using namespace nejlika::geometry;

void BSMasterParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_MaxEmitterObjects = reader.Read<ushort>();

    m_NumParticleSystems = reader.Read<int>();

    m_ParticleSystems.resize(m_NumParticleSystems);
    for (uint32_t i = 0; i < m_ParticleSystems.size(); i++)
    {
        m_ParticleSystems[i].Read(reader, version, user, 0);
    }

}

void BSMasterParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_MaxEmitterObjects);

    writer.Write(m_NumParticleSystems);

    for (uint32_t i = 0; i < m_ParticleSystems.size(); i++)
    {
        m_ParticleSystems[i].Write(writer, version, user, 0);
    }

}
