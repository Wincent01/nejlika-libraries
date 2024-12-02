#include "NiArkTextureExtraData.hpp"

using namespace nejlika::geometry;

void NiArkTextureExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownInts1.resize(2);
    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        m_UnknownInts1[i] = reader.Read<int>();
    }

    m_UnknownByte = reader.Read<byte>();

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_UnknownInt2 = reader.Read<int>();
    }

    m_NumTextures = reader.Read<int>();

    m_Textures.resize(m_NumTextures);
    for (uint32_t i = 0; i < m_Textures.size(); i++)
    {
        m_Textures[i].Read(reader, version, user, 0);
    }

}

void NiArkTextureExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        writer.Write(m_UnknownInts1[i]);
    }

    writer.Write(m_UnknownByte);

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        writer.Write(m_UnknownInt2);
    }

    writer.Write(m_NumTextures);

    for (uint32_t i = 0; i < m_Textures.size(); i++)
    {
        m_Textures[i].Write(writer, version, user, 0);
    }

}
