#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "Particle.hpp"

namespace nejlika::world
{

class ParticleInformation
{
public:
    ParticleInformation() = default;

    ParticleInformation(nejlika::Reader& io, uint32_t version);

    void Save(nejlika::Writer& io, uint32_t version) const;

    std::vector<Particle>& GetParticles();

    ~ParticleInformation();

private:
    std::vector<Particle> m_Particles;
};

}