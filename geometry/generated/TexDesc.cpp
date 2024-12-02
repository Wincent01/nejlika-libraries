#include "TexDesc.hpp"

using namespace nejlika::geometry;

void TexDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Source.Read(reader, version, user, 0);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_ClampMode = reader.Read<TexClampMode>();
    }
    else
    {
        m_ClampMode = static_cast<TexClampMode>(WRAP_S_WRAP_T);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_FilterMode = reader.Read<TexFilterMode>();
    }
    else
    {
        m_FilterMode = static_cast<TexFilterMode>(FILTER_TRILERP);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (version >= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_UnknownShort = reader.Read<short>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_UVSet = reader.Read<uint>();
    }
    else
    {
        m_UVSet = 0;
    }

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_PS2L = reader.Read<short>();
    }
    else
    {
        m_PS2L = 0;
    }

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_PS2K = reader.Read<short>();
    }
    else
    {
        m_PS2K = -75;
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_Unknown1 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasTextureTransform = reader.Read<bool>();
    }
    else
    {
        m_HasTextureTransform = false;
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_Translation.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_Tiling.Read(reader, version, user, 0);
    }
    else
    {
        //m_Tiling = { 10, 10 };
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_WRotation = reader.Read<float>();
    }
    else
    {
        m_WRotation = 00;
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_TransformType = reader.Read<uint>();
    }
    else
    {
        m_TransformType = 0;
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_CenterOffset.Read(reader, version, user, 0);
    }

}

void TexDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Source.Write(writer, version, user, 0);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_ClampMode);
    }
    else
    {
        //writer.Write(WRAP_S_WRAP_T);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_FilterMode);
    }
    else
    {
        //writer.Write(FILTER_TRILERP);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_Flags);
    }

    if (version >= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_UnknownShort);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_UVSet);
    }
    else
    {
        //writer.Write(0);
    }

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_PS2L);
    }
    else
    {
        //writer.Write(0);
    }

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_PS2K);
    }
    else
    {
        //writer.Write(-75);
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        writer.Write(m_Unknown1);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasTextureTransform);
    }
    else
    {
        //writer.Write(false);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_Translation.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_Tiling.Write(writer, version, user, 0);
    }
    else
    {
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        writer.Write(m_WRotation);
    }
    else
    {
        //writer.Write(00);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        writer.Write(m_TransformType);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasTextureTransform)
    {
        m_CenterOffset.Write(writer, version, user, 0);
    }

}
