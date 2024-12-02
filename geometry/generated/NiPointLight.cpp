#include "NiPointLight.hpp"

using namespace nejlika::geometry;

void NiPointLight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiLight::Read(reader, version, user, arg);

    m_ConstantAttenuation = reader.Read<float>();

    m_LinearAttenuation = reader.Read<float>();

    m_QuadraticAttenuation = reader.Read<float>();

}

void NiPointLight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiLight::Write(writer, version, user, arg);

    writer.Write(m_ConstantAttenuation);

    writer.Write(m_LinearAttenuation);

    writer.Write(m_QuadraticAttenuation);

}
