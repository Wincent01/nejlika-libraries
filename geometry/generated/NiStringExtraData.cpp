#include "NiStringExtraData.hpp"

using namespace nejlika::geometry;

void NiStringExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_BytesRemaining = reader.Read<uint>();
    }

    m_StringData.Read(reader, version, user, 0);

}

void NiStringExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_BytesRemaining);
    }

    m_StringData.Write(writer, version, user, 0);

}
