#include "TexSource.hpp"

using namespace nejlika::geometry;

void TexSource::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
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

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 0)
    {
        m_FileName.Read(reader, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_PixelData.Read(reader, version, user, 0);
    }

}

void TexSource::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
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

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_UseExternal== 0)
    {
        m_FileName.Write(writer, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_PixelData.Write(writer, version, user, 0);
    }

}
