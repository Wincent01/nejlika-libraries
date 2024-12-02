#include "NiPSysEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_Speed = reader.Read<float>();

    m_SpeedVariation = reader.Read<float>();

    m_Declination = reader.Read<float>();

    m_DeclinationVariation = reader.Read<float>();

    m_PlanarAngle = reader.Read<float>();

    m_PlanarAngleVariation = reader.Read<float>();

    m_InitialColor.Read(reader, version, user, 0);

    m_InitialRadius = reader.Read<float>();

    if (version >= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_RadiusVariation = reader.Read<float>();
    }

    m_LifeSpan = reader.Read<float>();

    m_LifeSpanVariation = reader.Read<float>();

}

void NiPSysEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_Speed);

    writer.Write(m_SpeedVariation);

    writer.Write(m_Declination);

    writer.Write(m_DeclinationVariation);

    writer.Write(m_PlanarAngle);

    writer.Write(m_PlanarAngleVariation);

    m_InitialColor.Write(writer, version, user, 0);

    writer.Write(m_InitialRadius);

    if (version >= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_RadiusVariation);
    }

    writer.Write(m_LifeSpan);

    writer.Write(m_LifeSpanVariation);

}
