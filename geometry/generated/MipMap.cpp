#include "MipMap.hpp"

using namespace nejlika::geometry;

void MipMap::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Width = reader.Read<uint>();

    m_Height = reader.Read<uint>();

    m_Offset = reader.Read<uint>();

}

void MipMap::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Width);

    writer.Write(m_Height);

    writer.Write(m_Offset);

}
