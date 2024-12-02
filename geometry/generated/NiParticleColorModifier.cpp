#include "NiParticleColorModifier.hpp"

using namespace nejlika::geometry;

void NiParticleColorModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_ColorData.Read(reader, version, user, 0);

}

void NiParticleColorModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    m_ColorData.Write(writer, version, user, 0);

}
