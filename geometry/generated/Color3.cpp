#include "Color3.hpp"

using namespace nejlika::geometry;

void Color3::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_r = reader.Read<float>();

    m_g = reader.Read<float>();

    m_b = reader.Read<float>();

}

void Color3::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_r);

    writer.Write(m_g);

    writer.Write(m_b);

}
