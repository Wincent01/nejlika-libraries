#include "QuaternionXYZW.hpp"

using namespace nejlika::geometry;

void QuaternionXYZW::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_x = reader.Read<float>();

    m_y = reader.Read<float>();

    m_z = reader.Read<float>();

    m_w = reader.Read<float>();

}

void QuaternionXYZW::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_x);

    writer.Write(m_y);

    writer.Write(m_z);

    writer.Write(m_w);

}