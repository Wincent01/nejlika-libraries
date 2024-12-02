#include "NiStencilProperty.hpp"

using namespace nejlika::geometry;

void NiStencilProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StencilEnabled = reader.Read<byte>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StencilFunction = reader.Read<StencilCompareMode>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StencilRef = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StencilMask = reader.Read<uint>();
    }
    else
    {
        m_StencilMask = 4294967295;
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_FailAction = reader.Read<StencilAction>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_ZFailAction = reader.Read<StencilAction>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PassAction = reader.Read<StencilAction>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_DrawMode = reader.Read<FaceDrawMode>();
    }
    else
    {
        m_DrawMode = static_cast<FaceDrawMode>(DRAW_BOTH);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Flags = reader.Read<Flags>();
    }
    else
    {
        m_Flags = 19840;
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_StencilRef = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_StencilMask = reader.Read<uint>();
    }
    else
    {
        m_StencilMask = 4294967295;
    }

}

void NiStencilProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        writer.Write(m_Flags);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_StencilEnabled);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_StencilFunction);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_StencilRef);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_StencilMask);
    }
    else
    {
        //writer.Write(4294967295);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_FailAction);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_ZFailAction);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_PassAction);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_DrawMode);
    }
    else
    {
        //writer.Write(DRAW_BOTH);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_Flags);
    }
    else
    {
        //writer.Write(19840);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_StencilRef);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_StencilMask);
    }
    else
    {
        //writer.Write(4294967295);
    }

}
