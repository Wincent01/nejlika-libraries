#include "NiStringsExtraData.hpp"

using namespace nejlika::geometry;

void NiStringsExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumStrings = reader.Read<uint>();

    m_Data.resize(m_NumStrings);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i].Read(reader, version, user, 0);
    }

}

void NiStringsExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumStrings);

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i].Write(writer, version, user, 0);
    }

}
