#include "StringPalette.hpp"

using namespace nejlika::geometry;

void StringPalette::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Palette.Read(reader, version, user, 0);

    m_Length = reader.Read<uint>();

}

void StringPalette::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Palette.Write(writer, version, user, 0);

    writer.Write(m_Length);

}
