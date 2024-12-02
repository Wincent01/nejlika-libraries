#include "NiArkAnimationExtraData.hpp"

using namespace nejlika::geometry;

void NiArkAnimationExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownInts.resize(4);
    for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
    {
        m_UnknownInts[i] = reader.Read<int>();
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_UnknownBytes.resize(37);
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            m_UnknownBytes[i] = reader.Read<byte>();
        }
    }

}

void NiArkAnimationExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
    {
        writer.Write(m_UnknownInts[i]);
    }

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            writer.Write(m_UnknownBytes[i]);
        }
    }

}
