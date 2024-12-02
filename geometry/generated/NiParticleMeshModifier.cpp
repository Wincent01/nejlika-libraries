#include "NiParticleMeshModifier.hpp"

using namespace nejlika::geometry;

void NiParticleMeshModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_NumParticleMeshes = reader.Read<uint>();

    m_ParticleMeshes.resize(m_NumParticleMeshes);
    for (uint32_t i = 0; i < m_ParticleMeshes.size(); i++)
    {
        m_ParticleMeshes[i].Read(reader, version, user, 0);
    }

}

void NiParticleMeshModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    writer.Write(m_NumParticleMeshes);

    for (uint32_t i = 0; i < m_ParticleMeshes.size(); i++)
    {
        m_ParticleMeshes[i].Write(writer, version, user, 0);
    }

}
