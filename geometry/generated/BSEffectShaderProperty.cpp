#include "BSEffectShaderProperty.hpp"

using namespace nejlika::geometry;

void BSEffectShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_ShaderFlags1 = reader.Read<SkyrimShaderPropertyFlags1>();

    m_ShaderFlags2 = reader.Read<SkyrimShaderPropertyFlags2>();

    m_UVOffset.Read(reader, version, user, 0);

    m_UVScale.Read(reader, version, user, 0);

    m_SourceTexture.Read(reader, version, user, 0);

    m_TextureClampMode = reader.Read<uint>();

    m_FalloffStartAngle = reader.Read<float>();

    m_FalloffStopAngle = reader.Read<float>();

    m_FalloffStartOpacity = reader.Read<float>();

    m_FalloffStopOpacity = reader.Read<float>();

    m_EmissiveColor.Read(reader, version, user, 0);

    m_EmissiveMultiple = reader.Read<float>();

    m_SoftFalloffDepth = reader.Read<float>();

    m_GreyscaleTexture.Read(reader, version, user, 0);

}

void BSEffectShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_ShaderFlags1);

    writer.Write(m_ShaderFlags2);

    m_UVOffset.Write(writer, version, user, 0);

    m_UVScale.Write(writer, version, user, 0);

    m_SourceTexture.Write(writer, version, user, 0);

    writer.Write(m_TextureClampMode);

    writer.Write(m_FalloffStartAngle);

    writer.Write(m_FalloffStopAngle);

    writer.Write(m_FalloffStartOpacity);

    writer.Write(m_FalloffStopOpacity);

    m_EmissiveColor.Write(writer, version, user, 0);

    writer.Write(m_EmissiveMultiple);

    writer.Write(m_SoftFalloffDepth);

    m_GreyscaleTexture.Write(writer, version, user, 0);

}
