#include "TexCoord.hpp"

using namespace nejlika::geometry;

void TexCoord::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_u = reader.Read<float>();

    m_v = reader.Read<float>();

}

void TexCoord::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_u);

    writer.Write(m_v);

}
