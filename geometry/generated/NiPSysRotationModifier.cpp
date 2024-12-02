#include "NiPSysRotationModifier.hpp"

using namespace nejlika::geometry;

void NiPSysRotationModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_InitialRotationSpeed = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_InitialRotationSpeedVariation = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_InitialRotationAngle = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_InitialRotationAngleVariation = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_RandomRotSpeedSign = reader.Read<bool>();
    }

    m_RandomInitialAxis = reader.Read<bool>();

    m_InitialAxis.Read(reader, version, user, 0);

}

void NiPSysRotationModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_InitialRotationSpeed);

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_InitialRotationSpeedVariation);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_InitialRotationAngle);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_InitialRotationAngleVariation);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_RandomRotSpeedSign);
    }

    writer.Write(m_RandomInitialAxis);

    m_InitialAxis.Write(writer, version, user, 0);

}
