#include "Matrix33.hpp"

using namespace nejlika::geometry;

void Matrix33::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_m11 = reader.Read<float>();

    m_m21 = reader.Read<float>();

    m_m31 = reader.Read<float>();

    m_m12 = reader.Read<float>();

    m_m22 = reader.Read<float>();

    m_m32 = reader.Read<float>();

    m_m13 = reader.Read<float>();

    m_m23 = reader.Read<float>();

    m_m33 = reader.Read<float>();

}

void Matrix33::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_m11);

    writer.Write(m_m21);

    writer.Write(m_m31);

    writer.Write(m_m12);

    writer.Write(m_m22);

    writer.Write(m_m32);

    writer.Write(m_m13);

    writer.Write(m_m23);

    writer.Write(m_m33);

}
