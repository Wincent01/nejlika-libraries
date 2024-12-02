#include "NiMaterialProperty.hpp"

using namespace nejlika::geometry;

void NiMaterialProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (!((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21)))
    {
        m_AmbientColor.Read(reader, version, user, 0);
    }

    if (!((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21)))
    {
        m_DiffuseColor.Read(reader, version, user, 0);
    }

    m_SpecularColor.Read(reader, version, user, 0);

    m_EmissiveColor.Read(reader, version, user, 0);

    m_Glossiness = reader.Read<float>();

    m_Alpha = reader.Read<float>();

    if ((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21))
    {
        m_EmitMulti = reader.Read<float>();
    }
    else
    {
        m_EmitMulti = 10;
    }

}

void NiMaterialProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        writer.Write(m_Flags);
    }

    if (!((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21)))
    {
        m_AmbientColor.Write(writer, version, user, 0);
    }

    if (!((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21)))
    {
        m_DiffuseColor.Write(writer, version, user, 0);
    }

    m_SpecularColor.Write(writer, version, user, 0);

    m_EmissiveColor.Write(writer, version, user, 0);

    writer.Write(m_Glossiness);

    writer.Write(m_Alpha);

    if ((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11) && (0> 21))
    {
        writer.Write(m_EmitMulti);
    }
    else
    {
        //writer.Write(10);
    }

}
