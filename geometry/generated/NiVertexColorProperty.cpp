#include "NiVertexColorProperty.hpp"

using namespace nejlika::geometry;

void NiVertexColorProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_VertexMode = reader.Read<VertMode>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_LightingMode = reader.Read<LightMode>();
    }

}

void NiVertexColorProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_VertexMode);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_LightingMode);
    }

}
