#include "FurniturePosition.hpp"

using namespace nejlika::geometry;

void FurniturePosition::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Offset.Read(reader, version, user, 0);

    if (user<= 11)
    {
        m_Orientation = reader.Read<ushort>();
    }

    if (user<= 11)
    {
        m_PositionRef1 = reader.Read<byte>();
    }

    if (user<= 11)
    {
        m_PositionRef2 = reader.Read<byte>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_Heading = reader.Read<float>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_AnimationType = reader.Read<AnimationType>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_EntryProperties = reader.Read<FurnitureEntryPoints>();
    }

}

void FurniturePosition::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Offset.Write(writer, version, user, 0);

    if (user<= 11)
    {
        writer.Write(m_Orientation);
    }

    if (user<= 11)
    {
        writer.Write(m_PositionRef1);
    }

    if (user<= 11)
    {
        writer.Write(m_PositionRef2);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_Heading);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_AnimationType);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_EntryProperties);
    }

}
