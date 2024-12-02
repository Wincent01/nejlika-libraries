#include "NiParticleGrowFade.hpp"

using namespace nejlika::geometry;

void NiParticleGrowFade::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_Grow = reader.Read<float>();

    m_Fade = reader.Read<float>();

}

void NiParticleGrowFade::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    writer.Write(m_Grow);

    writer.Write(m_Fade);

}
