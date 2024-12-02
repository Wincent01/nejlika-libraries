#include "NiControllerSequence.hpp"

using namespace nejlika::geometry;

void NiControllerSequence::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSequence::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Weight = reader.Read<float>();
    }
    else
    {
        m_Weight = 10;
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_TextKeys.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_CycleType = reader.Read<CycleType>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownInt0 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Frequency = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_StartTime = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_UnknownFloat2 = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_StopTime = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownByte = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Manager.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_TargetName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StringPalette.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0>= 24) && (0<= 28))
    {
        m_AnimNotes.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0> 28))
    {
        m_UnknownShort1 = reader.Read<short>();
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9))
    {
        m_UnknownInt3 = reader.Read<uint>();
    }
    else
    {
        m_UnknownInt3 = 64;
    }

}

void NiControllerSequence::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSequence::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_Weight);
    }
    else
    {
        //writer.Write(10);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_TextKeys.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_CycleType);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_UnknownInt0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_Frequency);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_StartTime);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_UnknownFloat2);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_StopTime);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_UnknownByte);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Manager.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_TargetName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_StringPalette.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0>= 24) && (0<= 28))
    {
        m_AnimNotes.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0> 28))
    {
        writer.Write(m_UnknownShort1);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9))
    {
        writer.Write(m_UnknownInt3);
    }
    else
    {
        //writer.Write(64);
    }

}
