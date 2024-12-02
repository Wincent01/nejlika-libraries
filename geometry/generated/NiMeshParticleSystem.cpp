#include "NiMeshParticleSystem.hpp"

using namespace nejlika::geometry;

void NiMeshParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleSystem::Read(reader, version, user, arg);

}

void NiMeshParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleSystem::Write(writer, version, user, arg);

}
