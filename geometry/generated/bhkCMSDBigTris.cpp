#include "bhkCMSDBigTris.hpp"

using namespace nejlika::geometry;

void bhkCMSDBigTris::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Triangle1 = reader.Read<ushort>();

    m_Triangle2 = reader.Read<ushort>();

    m_Triangle3 = reader.Read<ushort>();

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownShort1 = reader.Read<ushort>();

}

void bhkCMSDBigTris::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Triangle1);

    writer.Write(m_Triangle2);

    writer.Write(m_Triangle3);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownShort1);

}
