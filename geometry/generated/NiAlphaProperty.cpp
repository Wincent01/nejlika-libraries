#include "NiAlphaProperty.hpp"

using namespace nejlika::geometry;

void NiAlphaProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    m_Threshold = reader.Read<byte>();

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_UnknownShort1 = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

}

void NiAlphaProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    writer.Write(m_Threshold);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        writer.Write(m_UnknownShort1);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        writer.Write(m_UnknownInt2);
    }

}
