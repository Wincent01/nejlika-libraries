#include "ATextureRenderData.hpp"

using namespace nejlika::geometry;

void ATextureRenderData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_PixelFormat = reader.Read<PixelFormat>();

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_RedMask = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_GreenMask = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_BlueMask = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_AlphaMask = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_BitsPerPixel = reader.Read<byte>();
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_Unknown3Bytes.resize(3);
        for (uint32_t i = 0; i < m_Unknown3Bytes.size(); i++)
        {
            m_Unknown3Bytes[i] = reader.Read<byte>();
        }
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_Unknown8Bytes.resize(8);
        for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
        {
            m_Unknown8Bytes[i] = reader.Read<byte>();
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInt = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_BitsPerPixel = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_UnknownInt2 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_UnknownInt3 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_Flags = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_UnknownInt4 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 6))
    {
        m_UnknownByte1 = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_Channels.resize(4);
        for (uint32_t i = 0; i < m_Channels.size(); i++)
        {
            m_Channels[i].Read(reader, version, user, 0);
        }
    }

    m_Palette.Read(reader, version, user, 0);

    m_NumMipmaps = reader.Read<uint>();

    m_BytesPerPixel = reader.Read<uint>();

    m_Mipmaps.resize(m_NumMipmaps);
    for (uint32_t i = 0; i < m_Mipmaps.size(); i++)
    {
        m_Mipmaps[i].Read(reader, version, user, 0);
    }

}

void ATextureRenderData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_PixelFormat);

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_RedMask);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_GreenMask);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_BlueMask);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_AlphaMask);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_BitsPerPixel);
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        for (uint32_t i = 0; i < m_Unknown3Bytes.size(); i++)
        {
            writer.Write(m_Unknown3Bytes[i]);
        }
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
        {
            writer.Write(m_Unknown8Bytes[i]);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownInt);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_BitsPerPixel);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_UnknownInt3);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_Flags);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_UnknownInt4);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 6))
    {
        writer.Write(m_UnknownByte1);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        for (uint32_t i = 0; i < m_Channels.size(); i++)
        {
            m_Channels[i].Write(writer, version, user, 0);
        }
    }

    m_Palette.Write(writer, version, user, 0);

    writer.Write(m_NumMipmaps);

    writer.Write(m_BytesPerPixel);

    for (uint32_t i = 0; i < m_Mipmaps.size(); i++)
    {
        m_Mipmaps[i].Write(writer, version, user, 0);
    }

}
