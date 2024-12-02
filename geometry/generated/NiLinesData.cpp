#include "NiLinesData.hpp"

using namespace nejlika::geometry;

void NiLinesData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiGeometryData::Read(reader, version, user, arg);

    m_Lines.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Lines.size(); i++)
    {
        m_Lines[i] = reader.Read<bool>();
    }

}

void NiLinesData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiGeometryData::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Lines.size(); i++)
    {
        writer.Write(m_Lines[i]);
    }

}
