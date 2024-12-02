#include "ExtraMeshDataEpicMickey2.hpp"

using namespace nejlika::geometry;

void ExtraMeshDataEpicMickey2::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Start = reader.Read<int>();

    m_End = reader.Read<int>();

    m_UnknownShorts.resize(10);
    for (uint32_t i = 0; i < m_UnknownShorts.size(); i++)
    {
        m_UnknownShorts[i] = reader.Read<short>();
    }

}

void ExtraMeshDataEpicMickey2::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Start);

    writer.Write(m_End);

    for (uint32_t i = 0; i < m_UnknownShorts.size(); i++)
    {
        writer.Write(m_UnknownShorts[i]);
    }

}
