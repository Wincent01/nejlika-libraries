#include "ByteColor3.hpp"

using namespace nejlika::geometry;

void ByteColor3::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_r = reader.Read<byte>();

    m_g = reader.Read<byte>();

    m_b = reader.Read<byte>();

}

void ByteColor3::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_r);

    writer.Write(m_g);

    writer.Write(m_b);

}
