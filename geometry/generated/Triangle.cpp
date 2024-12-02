#include "Triangle.hpp"

using namespace nejlika::geometry;

void Triangle::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_v1 = reader.Read<ushort>();

    m_v2 = reader.Read<ushort>();

    m_v3 = reader.Read<ushort>();

}

void Triangle::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_v1);

    writer.Write(m_v2);

    writer.Write(m_v3);

}
