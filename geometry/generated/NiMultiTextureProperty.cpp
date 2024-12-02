#include "NiMultiTextureProperty.hpp"

using namespace nejlika::geometry;

void NiMultiTextureProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    m_UnknownInt = reader.Read<uint>();

    m_TextureElements.resize(5);
    for (uint32_t i = 0; i < m_TextureElements.size(); i++)
    {
        m_TextureElements[i].Read(reader, version, user, 0);
    }

}

void NiMultiTextureProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    writer.Write(m_UnknownInt);

    for (uint32_t i = 0; i < m_TextureElements.size(); i++)
    {
        m_TextureElements[i].Write(writer, version, user, 0);
    }

}
