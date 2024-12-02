#include "NiTexturingProperty.hpp"

using namespace nejlika::geometry;

void NiTexturingProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_ApplyMode = reader.Read<ApplyMode>();
    }
    else
    {
        m_ApplyMode = static_cast<ApplyMode>(APPLY_MODULATE);
    }

    m_TextureCount = reader.Read<uint>();

    m_HasBaseTexture = reader.Read<bool>();

    if (m_HasBaseTexture)
    {
        m_BaseTexture.Read(reader, version, user, 0);
    }

    m_HasDarkTexture = reader.Read<bool>();

    if (m_HasDarkTexture)
    {
        m_DarkTexture.Read(reader, version, user, 0);
    }

    m_HasDetailTexture = reader.Read<bool>();

    if (m_HasDetailTexture)
    {
        m_DetailTexture.Read(reader, version, user, 0);
    }

    m_HasGlossTexture = reader.Read<bool>();

    if (m_HasGlossTexture)
    {
        m_GlossTexture.Read(reader, version, user, 0);
    }

    m_HasGlowTexture = reader.Read<bool>();

    if (m_HasGlowTexture)
    {
        m_GlowTexture.Read(reader, version, user, 0);
    }

    m_HasBumpMapTexture = reader.Read<bool>();

    if (m_HasBumpMapTexture)
    {
        m_BumpMapTexture.Read(reader, version, user, 0);
    }

    if (m_HasBumpMapTexture)
    {
        m_BumpMapLumaScale = reader.Read<float>();
    }

    if (m_HasBumpMapTexture)
    {
        m_BumpMapLumaOffset = reader.Read<float>();
    }

    if (m_HasBumpMapTexture)
    {
        m_BumpMapMatrix.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_HasNormalTexture = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_HasNormalTexture)
    {
        m_NormalTexture.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_HasUnknown2Texture = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_HasUnknown2Texture)
    {
        m_Unknown2Texture.Read(reader, version, user, 0);
    }

    if (m_HasUnknown2Texture)
    {
        m_Unknown2Float = reader.Read<float>();
    }

    m_HasDecal0Texture = reader.Read<bool>();

    if (m_HasDecal0Texture)
    {
        m_Decal0Texture.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 8)
    {
        m_HasDecal1Texture = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 10)
    {
        m_HasDecal1Texture = reader.Read<bool>();
    }

    if (m_HasDecal1Texture)
    {
        m_Decal1Texture.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 9)
    {
        m_HasDecal2Texture = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 11)
    {
        m_HasDecal2Texture = reader.Read<bool>();
    }

    if (m_HasDecal2Texture)
    {
        m_Decal2Texture.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 10)
    {
        m_HasDecal3Texture = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 12)
    {
        m_HasDecal3Texture = reader.Read<bool>();
    }

    if (m_HasDecal3Texture)
    {
        m_Decal3Texture.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_NumShaderTextures = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_ShaderTextures.resize(m_NumShaderTextures);
        for (uint32_t i = 0; i < m_ShaderTextures.size(); i++)
        {
            m_ShaderTextures[i].Read(reader, version, user, 0);
        }
    }

}

void NiTexturingProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        writer.Write(m_Flags);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_Flags);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_ApplyMode);
    }
    else
    {
        //writer.Write(APPLY_MODULATE);
    }

    writer.Write(m_TextureCount);

    writer.Write(m_HasBaseTexture);

    if (m_HasBaseTexture)
    {
        m_BaseTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_HasDarkTexture);

    if (m_HasDarkTexture)
    {
        m_DarkTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_HasDetailTexture);

    if (m_HasDetailTexture)
    {
        m_DetailTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_HasGlossTexture);

    if (m_HasGlossTexture)
    {
        m_GlossTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_HasGlowTexture);

    if (m_HasGlowTexture)
    {
        m_GlowTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_HasBumpMapTexture);

    if (m_HasBumpMapTexture)
    {
        m_BumpMapTexture.Write(writer, version, user, 0);
    }

    if (m_HasBumpMapTexture)
    {
        writer.Write(m_BumpMapLumaScale);
    }

    if (m_HasBumpMapTexture)
    {
        writer.Write(m_BumpMapLumaOffset);
    }

    if (m_HasBumpMapTexture)
    {
        m_BumpMapMatrix.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_HasNormalTexture);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_HasNormalTexture)
    {
        m_NormalTexture.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_HasUnknown2Texture);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_HasUnknown2Texture)
    {
        m_Unknown2Texture.Write(writer, version, user, 0);
    }

    if (m_HasUnknown2Texture)
    {
        writer.Write(m_Unknown2Float);
    }

    writer.Write(m_HasDecal0Texture);

    if (m_HasDecal0Texture)
    {
        m_Decal0Texture.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 8)
    {
        writer.Write(m_HasDecal1Texture);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 10)
    {
        writer.Write(m_HasDecal1Texture);
    }

    if (m_HasDecal1Texture)
    {
        m_Decal1Texture.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 9)
    {
        writer.Write(m_HasDecal2Texture);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 11)
    {
        writer.Write(m_HasDecal2Texture);
    }

    if (m_HasDecal2Texture)
    {
        m_Decal2Texture.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 1, 0, 3) && m_TextureCount>= 10)
    {
        writer.Write(m_HasDecal3Texture);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_TextureCount>= 12)
    {
        writer.Write(m_HasDecal3Texture);
    }

    if (m_HasDecal3Texture)
    {
        m_Decal3Texture.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_NumShaderTextures);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_ShaderTextures.size(); i++)
        {
            m_ShaderTextures[i].Write(writer, version, user, 0);
        }
    }

}
