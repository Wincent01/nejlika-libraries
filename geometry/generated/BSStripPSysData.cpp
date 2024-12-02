#include "BSStripPSysData.hpp"

using namespace nejlika::geometry;

void BSStripPSysData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysData::Read(reader, version, user, arg);

    m_UnknownShort5 = reader.Read<short>();

    m_UnknownByte6 = reader.Read<byte>();

    m_UnknownInt7 = reader.Read<int>();

    m_UnknownFloat8 = reader.Read<float>();

}

void BSStripPSysData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysData::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort5);

    writer.Write(m_UnknownByte6);

    writer.Write(m_UnknownInt7);

    writer.Write(m_UnknownFloat8);

}
