#include "TBC.hpp"

using namespace nejlika::geometry;

void TBC::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_t = reader.Read<float>();

    m_b = reader.Read<float>();

    m_c = reader.Read<float>();

}

void TBC::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_t);

    writer.Write(m_b);

    writer.Write(m_c);

}
