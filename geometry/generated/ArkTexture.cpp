#include "ArkTexture.hpp"

using namespace nejlika::geometry;

void ArkTexture::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_TextureName.Read(reader, version, user, 0);

    m_UnknownInt3 = reader.Read<int>();

    m_UnknownInt4 = reader.Read<int>();

    m_TexturingProperty.Read(reader, version, user, 0);

    m_UnknownBytes.resize(9);
    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        m_UnknownBytes[i] = reader.Read<byte>();
    }

}

void ArkTexture::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_TextureName.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt3);

    writer.Write(m_UnknownInt4);

    m_TexturingProperty.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        writer.Write(m_UnknownBytes[i]);
    }

}
