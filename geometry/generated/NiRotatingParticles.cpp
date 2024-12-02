#include "NiRotatingParticles.hpp"

using namespace nejlika::geometry;

void NiRotatingParticles::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticles::Read(reader, version, user, arg);

}

void NiRotatingParticles::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticles::Write(writer, version, user, arg);

}
