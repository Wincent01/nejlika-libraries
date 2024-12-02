#include "BSStripParticleSystem.hpp"

using namespace nejlika::geometry;

void BSStripParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleSystem::Read(reader, version, user, arg);

}

void BSStripParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleSystem::Write(writer, version, user, arg);

}
