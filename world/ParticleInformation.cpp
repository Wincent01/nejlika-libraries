#include "ParticleInformation.hpp"

using namespace nejlika::world;

nejlika::world::ParticleInformation::ParticleInformation(nejlika::Reader &io, uint32_t version)
{
    const uint32_t particleCount = io.Read<uint32_t>();

    m_Particles.reserve(particleCount);

    for (uint32_t i = 0; i < particleCount; i++)
    {
        m_Particles.push_back(Particle(io, version));
    }
}

void nejlika::world::ParticleInformation::Save(nejlika::Writer &io, uint32_t version) const
{
    io.Write<uint32_t>(m_Particles.size());

    for (const Particle &particle : m_Particles)
    {
        particle.Save(io, version);
    }
}

std::vector<nejlika::world::Particle> &nejlika::world::ParticleInformation::GetParticles()
{
    return m_Particles;
}

nejlika::world::ParticleInformation::~ParticleInformation()
{
}
