#include "NiArkImporterExtraData.hpp"

using namespace nejlika::geometry;

void NiArkImporterExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        m_UnknownInt2 = reader.Read<int>();
    }

    m_ImporterName.Read(reader, version, user, 0);

    m_UnknownBytes.resize(13);
    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        m_UnknownBytes[i] = reader.Read<byte>();
    }

    m_UnknownFloats.resize(7);
    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        m_UnknownFloats[i] = reader.Read<float>();
    }

}

void NiArkImporterExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    if (version <= VERSION_NUMBER(4, 1, 0, 12))
    {
        writer.Write(m_UnknownInt2);
    }

    m_ImporterName.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        writer.Write(m_UnknownBytes[i]);
    }

    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        writer.Write(m_UnknownFloats[i]);
    }

}
