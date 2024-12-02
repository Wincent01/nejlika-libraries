#include "BSLightingShaderProperty.hpp"

using namespace nejlika::geometry;

void BSLightingShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (user== 12)
    {
        m_ShaderFlags1 = reader.Read<SkyrimShaderPropertyFlags1>();
    }
    else
    {
        m_ShaderFlags1 = static_cast<SkyrimShaderPropertyFlags1>(2185233153);
    }

    if (user== 12)
    {
        m_ShaderFlags2 = reader.Read<SkyrimShaderPropertyFlags2>();
    }
    else
    {
        m_ShaderFlags2 = static_cast<SkyrimShaderPropertyFlags2>(32801);
    }

    m_UVOffset.Read(reader, version, user, 0);

    m_UVScale.Read(reader, version, user, 0);

    m_TextureSet.Read(reader, version, user, 0);

    m_EmissiveColor.Read(reader, version, user, 0);

    m_EmissiveMultiple = reader.Read<float>();

    m_TextureClampMode = reader.Read<TexClampMode>();

    m_Alpha = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_Glossiness = reader.Read<float>();

    m_SpecularColor.Read(reader, version, user, 0);

    m_SpecularStrength = reader.Read<float>();

    m_LightingEffect1 = reader.Read<float>();

    m_LightingEffect2 = reader.Read<float>();

    if (m_SkyrimShaderType== 1)
    {
        m_EnvironmentMapScale = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 5)
    {
        m_SkinTintColor.Read(reader, version, user, 0);
    }

    if (m_SkyrimShaderType== 6)
    {
        m_HairTintColor.Read(reader, version, user, 0);
    }

    if (m_SkyrimShaderType== 7)
    {
        m_MaxPasses = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 7)
    {
        m_Scale = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 11)
    {
        m_ParallaxInnerLayerThickness = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 11)
    {
        m_ParallaxRefractionScale = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 11)
    {
        m_ParallaxInnerLayerTextureScale.Read(reader, version, user, 0);
    }

    if (m_SkyrimShaderType== 11)
    {
        m_ParallaxEnvmapStrength = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 14)
    {
        m_SparkleParameters.Read(reader, version, user, 0);
    }

    if (m_SkyrimShaderType== 16)
    {
        m_EyeCubemapScale = reader.Read<float>();
    }

    if (m_SkyrimShaderType== 16)
    {
        m_LeftEyeReflectionCenter.Read(reader, version, user, 0);
    }

    if (m_SkyrimShaderType== 16)
    {
        m_RightEyeReflectionCenter.Read(reader, version, user, 0);
    }

}

void BSLightingShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (user== 12)
    {
        writer.Write(m_ShaderFlags1);
    }
    else
    {
        //writer.Write(2185233153);
    }

    if (user== 12)
    {
        writer.Write(m_ShaderFlags2);
    }
    else
    {
        //writer.Write(32801);
    }

    m_UVOffset.Write(writer, version, user, 0);

    m_UVScale.Write(writer, version, user, 0);

    m_TextureSet.Write(writer, version, user, 0);

    m_EmissiveColor.Write(writer, version, user, 0);

    writer.Write(m_EmissiveMultiple);

    writer.Write(m_TextureClampMode);

    writer.Write(m_Alpha);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_Glossiness);

    m_SpecularColor.Write(writer, version, user, 0);

    writer.Write(m_SpecularStrength);

    writer.Write(m_LightingEffect1);

    writer.Write(m_LightingEffect2);

    if (m_SkyrimShaderType== 1)
    {
        writer.Write(m_EnvironmentMapScale);
    }

    if (m_SkyrimShaderType== 5)
    {
        m_SkinTintColor.Write(writer, version, user, 0);
    }

    if (m_SkyrimShaderType== 6)
    {
        m_HairTintColor.Write(writer, version, user, 0);
    }

    if (m_SkyrimShaderType== 7)
    {
        writer.Write(m_MaxPasses);
    }

    if (m_SkyrimShaderType== 7)
    {
        writer.Write(m_Scale);
    }

    if (m_SkyrimShaderType== 11)
    {
        writer.Write(m_ParallaxInnerLayerThickness);
    }

    if (m_SkyrimShaderType== 11)
    {
        writer.Write(m_ParallaxRefractionScale);
    }

    if (m_SkyrimShaderType== 11)
    {
        m_ParallaxInnerLayerTextureScale.Write(writer, version, user, 0);
    }

    if (m_SkyrimShaderType== 11)
    {
        writer.Write(m_ParallaxEnvmapStrength);
    }

    if (m_SkyrimShaderType== 14)
    {
        m_SparkleParameters.Write(writer, version, user, 0);
    }

    if (m_SkyrimShaderType== 16)
    {
        writer.Write(m_EyeCubemapScale);
    }

    if (m_SkyrimShaderType== 16)
    {
        m_LeftEyeReflectionCenter.Write(writer, version, user, 0);
    }

    if (m_SkyrimShaderType== 16)
    {
        m_RightEyeReflectionCenter.Write(writer, version, user, 0);
    }

}
