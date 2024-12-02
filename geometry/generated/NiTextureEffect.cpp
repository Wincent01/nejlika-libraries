#include "NiTextureEffect.hpp"

using namespace nejlika::geometry;

void NiTextureEffect::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiDynamicEffect::Read(reader, version, user, arg);

    m_ModelProjectionMatrix.Read(reader, version, user, 0);

    m_ModelProjectionTransform.Read(reader, version, user, 0);

    m_TextureFiltering = reader.Read<TexFilterMode>();

    m_TextureClamping = reader.Read<TexClampMode>();

    if (version >= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown = reader.Read<short>();
    }

    m_TextureType = reader.Read<EffectType>();

    m_CoordinateGenerationType = reader.Read<CoordGenType>();

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_Image.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 0))
    {
        m_SourceTexture.Read(reader, version, user, 0);
    }

    m_ClippingPlane = reader.Read<byte>();

    m_UnknownVector.Read(reader, version, user, 0);

    m_UnknownFloat = reader.Read<float>();

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_PS2L = reader.Read<short>();
    }
    else
    {
        m_PS2L = 0;
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_PS2K = reader.Read<short>();
    }
    else
    {
        m_PS2K = -75;
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_UnknownShort = reader.Read<ushort>();
    }

}

void NiTextureEffect::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiDynamicEffect::Write(writer, version, user, arg);

    m_ModelProjectionMatrix.Write(writer, version, user, 0);

    m_ModelProjectionTransform.Write(writer, version, user, 0);

    writer.Write(m_TextureFiltering);

    writer.Write(m_TextureClamping);

    if (version >= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown);
    }

    writer.Write(m_TextureType);

    writer.Write(m_CoordinateGenerationType);

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_Image.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 0))
    {
        m_SourceTexture.Write(writer, version, user, 0);
    }

    writer.Write(m_ClippingPlane);

    m_UnknownVector.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat);

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_PS2L);
    }
    else
    {
        //writer.Write(0);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_PS2K);
    }
    else
    {
        //writer.Write(-75);
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        writer.Write(m_UnknownShort);
    }

}
