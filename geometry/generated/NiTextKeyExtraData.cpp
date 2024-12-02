#include "NiTextKeyExtraData.hpp"

using namespace nejlika::geometry;

void NiTextKeyExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_UnknownInt1 = reader.Read<uint>();
    }

    m_NumTextKeys = reader.Read<uint>();

    m_TextKeys.resize(m_NumTextKeys);
    for (uint32_t i = 0; i < m_TextKeys.size(); i++)
    {
        m_TextKeys[i].Read(reader, version, user, 1);
    }

}

void NiTextKeyExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_UnknownInt1);
    }

    writer.Write(m_NumTextKeys);

    for (uint32_t i = 0; i < m_TextKeys.size(); i++)
    {
        m_TextKeys[i].Write(writer, version, user, 1);
    }

}
