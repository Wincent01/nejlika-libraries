#include "Quaternion.hpp"

using namespace nejlika::geometry;

void Quaternion::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_w = reader.Read<float>();

    m_x = reader.Read<float>();

    m_y = reader.Read<float>();

    m_z = reader.Read<float>();

}

void Quaternion::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_w);

    writer.Write(m_x);

    writer.Write(m_y);

    writer.Write(m_z);

}