#include "Color4.hpp"

using namespace nejlika::geometry;

void Color4::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_r = reader.Read<float>();

    m_g = reader.Read<float>();

    m_b = reader.Read<float>();

    m_a = reader.Read<float>();

}

void Color4::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_r);

    writer.Write(m_g);

    writer.Write(m_b);

    writer.Write(m_a);

}
