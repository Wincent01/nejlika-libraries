#include "MultiTextureElement.hpp"

using namespace nejlika::geometry;

void MultiTextureElement::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_HasImage = reader.Read<bool>();

    if (m_HasImage)
    {
        m_Image.Read(reader, version, user, 0);
    }

    if (m_HasImage)
    {
        m_Clamp = reader.Read<TexClampMode>();
    }
    else
    {
        m_Clamp = static_cast<TexClampMode>(WRAP_S_WRAP_T);
    }

    if (m_HasImage)
    {
        m_Filter = reader.Read<TexFilterMode>();
    }
    else
    {
        m_Filter = static_cast<TexFilterMode>(FILTER_TRILERP);
    }

    if (m_HasImage)
    {
        m_UVSet = reader.Read<uint>();
    }
    else
    {
        m_UVSet = 1;
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && version <= VERSION_NUMBER(10, 2, 0, 0) && m_HasImage)
    {
        m_PS2L = reader.Read<short>();
    }
    else
    {
        m_PS2L = 0;
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && version <= VERSION_NUMBER(10, 2, 0, 0) && m_HasImage)
    {
        m_PS2K = reader.Read<short>();
    }
    else
    {
        m_PS2K = -75;
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && m_HasImage)
    {
        m_UnknownShort3 = reader.Read<short>();
    }
    else
    {
        m_UnknownShort3 = 0;
    }

}

void MultiTextureElement::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_HasImage);

    if (m_HasImage)
    {
        m_Image.Write(writer, version, user, 0);
    }

    if (m_HasImage)
    {
        writer.Write(m_Clamp);
    }
    else
    {
        //writer.Write(WRAP_S_WRAP_T);
    }

    if (m_HasImage)
    {
        writer.Write(m_Filter);
    }
    else
    {
        //writer.Write(FILTER_TRILERP);
    }

    if (m_HasImage)
    {
        writer.Write(m_UVSet);
    }
    else
    {
        //writer.Write(1);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && version <= VERSION_NUMBER(10, 2, 0, 0) && m_HasImage)
    {
        writer.Write(m_PS2L);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && version <= VERSION_NUMBER(10, 2, 0, 0) && m_HasImage)
    {
        writer.Write(m_PS2K);
    }
    else
    {
        //writer.Write(-75);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 3) && m_HasImage)
    {
        writer.Write(m_UnknownShort3);
    }
    else
    {
        //writer.Write(0);
    }

}
