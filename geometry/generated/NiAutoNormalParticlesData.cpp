#include "NiAutoNormalParticlesData.hpp"

using namespace nejlika::geometry;

void NiAutoNormalParticlesData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticlesData::Read(reader, version, user, arg);

}

void NiAutoNormalParticlesData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticlesData::Write(writer, version, user, arg);

}
