#include "NiPSysGravityModifier.hpp"

using namespace nejlika::geometry;

void NiPSysGravityModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_GravityObject.Read(reader, version, user, 0);

    m_GravityAxis.Read(reader, version, user, 0);

    m_Decay = reader.Read<float>();

    m_Strength = reader.Read<float>();

    m_ForceType = reader.Read<ForceType>();

    m_Turbulence = reader.Read<float>();

    m_TurbulenceScale = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user>= 11)
    {
        m_UnknownByte = reader.Read<byte>();
    }

}

void NiPSysGravityModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    m_GravityObject.Write(writer, version, user, 0);

    m_GravityAxis.Write(writer, version, user, 0);

    writer.Write(m_Decay);

    writer.Write(m_Strength);

    writer.Write(m_ForceType);

    writer.Write(m_Turbulence);

    writer.Write(m_TurbulenceScale);

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user>= 11)
    {
        writer.Write(m_UnknownByte);
    }

}
