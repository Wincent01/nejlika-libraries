#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiParticleSystem.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system.
 *     
 */
class NiMeshParticleSystem : public NiParticleSystem
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
