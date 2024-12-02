#include "NiIntegersExtraData.hpp"

using namespace nejlika::geometry;

void NiIntegersExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumIntegers = reader.Read<uint>();

    m_Data.resize(m_NumIntegers);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i] = reader.Read<uint>();
    }

}

void NiIntegersExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumIntegers);

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        writer.Write(m_Data[i]);
    }

}
