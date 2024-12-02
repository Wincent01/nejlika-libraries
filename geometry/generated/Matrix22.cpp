#include "Matrix22.hpp"

using namespace nejlika::geometry;

void Matrix22::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_m11 = reader.Read<float>();

    m_m21 = reader.Read<float>();

    m_m12 = reader.Read<float>();

    m_m22 = reader.Read<float>();

}

void Matrix22::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_m11);

    writer.Write(m_m21);

    writer.Write(m_m12);

    writer.Write(m_m22);

}
