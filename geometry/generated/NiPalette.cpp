#include "NiPalette.hpp"

using namespace nejlika::geometry;

void NiPalette::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownByte = reader.Read<byte>();

    m_NumEntries = reader.Read<uint>();

    m_Palette.resize(256);
    for (uint32_t i = 0; i < m_Palette.size(); i++)
    {
        m_Palette[i].Read(reader, version, user, 0);
    }

}

void NiPalette::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownByte);

    writer.Write(m_NumEntries);

    for (uint32_t i = 0; i < m_Palette.size(); i++)
    {
        m_Palette[i].Write(writer, version, user, 0);
    }

}
