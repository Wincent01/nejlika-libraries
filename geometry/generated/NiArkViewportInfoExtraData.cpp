#include "NiArkViewportInfoExtraData.hpp"

using namespace nejlika::geometry;

void NiArkViewportInfoExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownBytes.resize(13);
    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        m_UnknownBytes[i] = reader.Read<byte>();
    }

}

void NiArkViewportInfoExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        writer.Write(m_UnknownBytes[i]);
    }

}
