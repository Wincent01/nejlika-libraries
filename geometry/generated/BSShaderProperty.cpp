#include "BSShaderProperty.hpp"

using namespace nejlika::geometry;

void BSShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    m_ShaderType = reader.Read<BSShaderType>();

    m_ShaderFlags = reader.Read<BSShaderFlags>();

    m_UnknownInt2 = reader.Read<int>();

    if (user== 11)
    {
        m_EnvmapScale = reader.Read<float>();
    }
    else
    {
        m_EnvmapScale = 10;
    }

}

void BSShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    writer.Write(m_ShaderType);

    writer.Write(m_ShaderFlags);

    writer.Write(m_UnknownInt2);

    if (user== 11)
    {
        writer.Write(m_EnvmapScale);
    }
    else
    {
        //writer.Write(10);
    }

}
