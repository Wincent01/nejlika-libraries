#include "Region.hpp"

using namespace nejlika::geometry;

void Region::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_StartIndex = reader.Read<uint>();

    m_NumIndices = reader.Read<uint>();

}

void Region::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_StartIndex);

    writer.Write(m_NumIndices);

}
