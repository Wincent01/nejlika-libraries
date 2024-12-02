#include "BSSegmentedTriShape.hpp"

using namespace nejlika::geometry;

void BSSegmentedTriShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriShape::Read(reader, version, user, arg);

    m_NumSegments = reader.Read<int>();

    m_Segment.resize(m_NumSegments);
    for (uint32_t i = 0; i < m_Segment.size(); i++)
    {
        m_Segment[i].Read(reader, version, user, 0);
    }

}

void BSSegmentedTriShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriShape::Write(writer, version, user, arg);

    writer.Write(m_NumSegments);

    for (uint32_t i = 0; i < m_Segment.size(); i++)
    {
        m_Segment[i].Write(writer, version, user, 0);
    }

}
