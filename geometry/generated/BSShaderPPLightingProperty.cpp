#include "BSShaderPPLightingProperty.hpp"

using namespace nejlika::geometry;

void BSShaderPPLightingProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderLightingProperty::Read(reader, version, user, arg);

    m_TextureSet.Read(reader, version, user, 0);

    if ((user== 11) && (0> 14))
    {
        m_UnknownFloat2 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat2 = 00;
    }

    if ((user== 11) && (0> 14))
    {
        m_RefractionPeriod = reader.Read<int>();
    }
    else
    {
        m_RefractionPeriod = 0;
    }

    if ((user== 11) && (0> 24))
    {
        m_UnknownFloat4 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat4 = 40;
    }

    if ((user== 11) && (0> 24))
    {
        m_UnknownFloat5 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat5 = 10;
    }

    if (user>= 12)
    {
        m_EmissiveColor.Read(reader, version, user, 0);
    }

}

void BSShaderPPLightingProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderLightingProperty::Write(writer, version, user, arg);

    m_TextureSet.Write(writer, version, user, 0);

    if ((user== 11) && (0> 14))
    {
        writer.Write(m_UnknownFloat2);
    }
    else
    {
        //writer.Write(00);
    }

    if ((user== 11) && (0> 14))
    {
        writer.Write(m_RefractionPeriod);
    }
    else
    {
        //writer.Write(0);
    }

    if ((user== 11) && (0> 24))
    {
        writer.Write(m_UnknownFloat4);
    }
    else
    {
        //writer.Write(40);
    }

    if ((user== 11) && (0> 24))
    {
        writer.Write(m_UnknownFloat5);
    }
    else
    {
        //writer.Write(10);
    }

    if (user>= 12)
    {
        m_EmissiveColor.Write(writer, version, user, 0);
    }

}
