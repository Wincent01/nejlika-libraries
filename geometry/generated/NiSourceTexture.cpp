#include "NiSourceTexture.hpp"

using namespace nejlika::geometry;

void NiSourceTexture::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTexture::Read(reader, version, user, arg);

    m_UseExternal = reader.Read<byte>();

    if (m_UseExternal== 1)
    {
        m_FileName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 1)
    {
        m_UnknownLink.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0) && m_UseExternal== 0)
    {
        m_UnknownByte = reader.Read<byte>();
    }
    else
    {
        m_UnknownByte = 1;
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 0)
    {
        m_FileName.Read(reader, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_PixelData.Read(reader, version, user, 0);
    }

    m_PixelLayout = reader.Read<PixelLayout>();

    m_UseMipmaps = reader.Read<MipMapFormat>();

    m_AlphaFormat = reader.Read<AlphaFormat>();

    m_IsStatic = reader.Read<byte>();

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_DirectRender = reader.Read<bool>();
    }
    else
    {
        m_DirectRender = 1;
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PersistRenderData = reader.Read<bool>();
    }
    else
    {
        m_PersistRenderData = 0;
    }

}

void NiSourceTexture::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTexture::Write(writer, version, user, arg);

    writer.Write(m_UseExternal);

    if (m_UseExternal== 1)
    {
        m_FileName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 1)
    {
        m_UnknownLink.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0) && m_UseExternal== 0)
    {
        writer.Write(m_UnknownByte);
    }
    else
    {
        //writer.Write(1);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 0)
    {
        m_FileName.Write(writer, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_PixelData.Write(writer, version, user, 0);
    }

    writer.Write(m_PixelLayout);

    writer.Write(m_UseMipmaps);

    writer.Write(m_AlphaFormat);

    writer.Write(m_IsStatic);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_DirectRender);
    }
    else
    {
        //writer.Write(1);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_PersistRenderData);
    }
    else
    {
        //writer.Write(0);
    }

}
