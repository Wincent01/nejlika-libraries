#include "NiParticleBomb.hpp"

using namespace nejlika::geometry;

void NiParticleBomb::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    m_Decay = reader.Read<float>();

    m_Duration = reader.Read<float>();

    m_DeltaV = reader.Read<float>();

    m_Start = reader.Read<float>();

    m_DecayType = reader.Read<DecayType>();

    if (version >= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_SymmetryType = reader.Read<SymmetryType>();
    }

    m_Position.Read(reader, version, user, 0);

    m_Direction.Read(reader, version, user, 0);

}

void NiParticleBomb::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    writer.Write(m_Decay);

    writer.Write(m_Duration);

    writer.Write(m_DeltaV);

    writer.Write(m_Start);

    writer.Write(m_DecayType);

    if (version >= VERSION_NUMBER(4, 1, 0, 12))
    {
        writer.Write(m_SymmetryType);
    }

    m_Position.Write(writer, version, user, 0);

    m_Direction.Write(writer, version, user, 0);

}
