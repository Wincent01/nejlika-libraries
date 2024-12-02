#include "ControllerLink.hpp"

using namespace nejlika::geometry;

void ControllerLink::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TargetName.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Controller.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Interpolator.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Controller.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownLink2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownShort0 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && (user>= 10))
    {
        m_Priority = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StringPalette.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_NodeName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_NodeName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_NodeNameOffset = reader.Read<StringOffset>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_PropertyType.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_PropertyType.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PropertyTypeOffset = reader.Read<StringOffset>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_ControllerType.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_ControllerType.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_ControllerTypeOffset = reader.Read<StringOffset>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Variable1.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Variable1.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Variable1Offset = reader.Read<StringOffset>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Variable2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Variable2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Variable2Offset = reader.Read<StringOffset>();
    }

}

void ControllerLink::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TargetName.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Controller.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Interpolator.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Controller.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownLink2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_UnknownShort0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && (user>= 10))
    {
        writer.Write(m_Priority);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StringPalette.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_NodeName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_NodeName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_NodeNameOffset);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_PropertyType.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_PropertyType.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_PropertyTypeOffset);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_ControllerType.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_ControllerType.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_ControllerTypeOffset);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Variable1.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Variable1.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_Variable1Offset);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Variable2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Variable2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_Variable2Offset);
    }

}
