#include "NiFloatsExtraData.hpp"

using namespace nejlika::geometry;

void NiFloatsExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumFloats = reader.Read<uint>();

    m_Data.resize(m_NumFloats);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i] = reader.Read<float>();
    }

}

void NiFloatsExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumFloats);

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        writer.Write(m_Data[i]);
    }

}
