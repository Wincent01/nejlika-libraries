#include "BSShaderNoLightingProperty.hpp"

using namespace nejlika::geometry;

void BSShaderNoLightingProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderLightingProperty::Read(reader, version, user, arg);

    m_FileName.Read(reader, version, user, 0);

    if ((user>= 11) && (0> 26))
    {
        m_UnknownFloat2 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat2 = 10;
    }

    if ((user>= 11) && (0> 26))
    {
        m_UnknownFloat3 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat3 = 00;
    }

    if ((user>= 11) && (0> 26))
    {
        m_UnknownFloat4 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat4 = 10;
    }

    if ((user>= 11) && (0> 26))
    {
        m_UnknownFloat5 = reader.Read<float>();
    }
    else
    {
        m_UnknownFloat5 = 00;
    }

}

void BSShaderNoLightingProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderLightingProperty::Write(writer, version, user, arg);

    m_FileName.Write(writer, version, user, 0);

    if ((user>= 11) && (0> 26))
    {
        writer.Write(m_UnknownFloat2);
    }
    else
    {
        //writer.Write(10);
    }

    if ((user>= 11) && (0> 26))
    {
        writer.Write(m_UnknownFloat3);
    }
    else
    {
        //writer.Write(00);
    }

    if ((user>= 11) && (0> 26))
    {
        writer.Write(m_UnknownFloat4);
    }
    else
    {
        //writer.Write(10);
    }

    if ((user>= 11) && (0> 26))
    {
        writer.Write(m_UnknownFloat5);
    }
    else
    {
        //writer.Write(00);
    }

}
