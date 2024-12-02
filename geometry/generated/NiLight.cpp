#include "NiLight.hpp"

using namespace nejlika::geometry;

void NiLight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiDynamicEffect::Read(reader, version, user, arg);

    m_Dimmer = reader.Read<float>();

    m_AmbientColor.Read(reader, version, user, 0);

    m_DiffuseColor.Read(reader, version, user, 0);

    m_SpecularColor.Read(reader, version, user, 0);

}

void NiLight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiDynamicEffect::Write(writer, version, user, arg);

    writer.Write(m_Dimmer);

    m_AmbientColor.Write(writer, version, user, 0);

    m_DiffuseColor.Write(writer, version, user, 0);

    m_SpecularColor.Write(writer, version, user, 0);

}
