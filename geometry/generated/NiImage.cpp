#include "NiImage.hpp"

using namespace nejlika::geometry;

void NiImage::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UseExternal = reader.Read<byte>();

    if (m_UseExternal!= 0)
    {
        m_FileName.Read(reader, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_ImageData.Read(reader, version, user, 0);
    }

    m_UnknownInt = reader.Read<uint>();

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownFloat = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat = 1285;
    }

}

void NiImage::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UseExternal);

    if (m_UseExternal!= 0)
    {
        m_FileName.Write(writer, version, user, 0);
    }

    if (m_UseExternal== 0)
    {
        m_ImageData.Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt);

    if (version >= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_UnknownFloat);
    }
    else
    {
        //writer.Write(1285);
    }

}
