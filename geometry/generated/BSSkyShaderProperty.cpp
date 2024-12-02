#include "BSSkyShaderProperty.hpp"

using namespace nejlika::geometry;

void BSSkyShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_ShaderFlags1 = reader.Read<SkyrimShaderPropertyFlags1>();

    m_ShaderFlags2 = reader.Read<SkyrimShaderPropertyFlags2>();

    m_UVOffset.Read(reader, version, user, 0);

    m_UVScale.Read(reader, version, user, 0);

    m_SourceTexture.Read(reader, version, user, 0);

    m_SkyObjectType = reader.Read<SkyObjectType>();

}

void BSSkyShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_ShaderFlags1);

    writer.Write(m_ShaderFlags2);

    m_UVOffset.Write(writer, version, user, 0);

    m_UVScale.Write(writer, version, user, 0);

    m_SourceTexture.Write(writer, version, user, 0);

    writer.Write(m_SkyObjectType);

}
