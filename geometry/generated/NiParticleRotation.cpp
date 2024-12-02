#include "NiParticleRotation.hpp"

using namespace nejlika::geometry;

void NiParticleRotation::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_RandomInitialAxis = reader.Read<byte>();

    m_InitialAxis.Read(reader, version, user, 0);

    m_RotationSpeed = reader.Read<float>();

}

void NiParticleRotation::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    writer.Write(m_RandomInitialAxis);

    m_InitialAxis.Write(writer, version, user, 0);

    writer.Write(m_RotationSpeed);

}
