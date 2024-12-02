#include "NiSpotLight.hpp"

using namespace nejlika::geometry;

void NiSpotLight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPointLight::Read(reader, version, user, arg);

    m_CutoffAngle = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_UnknownFloat = reader.Read<float>();
    }

    m_Exponent = reader.Read<float>();

}

void NiSpotLight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPointLight::Write(writer, version, user, arg);

    writer.Write(m_CutoffAngle);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_UnknownFloat);
    }

    writer.Write(m_Exponent);

}
