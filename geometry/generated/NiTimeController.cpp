#include "NiTimeController.hpp"

using namespace nejlika::geometry;

void NiTimeController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NextController.Read(reader, version, user, 0);

    m_Flags = reader.Read<Flags>();

    m_Frequency = reader.Read<float>();

    m_Phase = reader.Read<float>();

    m_StartTime = reader.Read<float>();

    m_StopTime = reader.Read<float>();

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_Target.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownInteger = reader.Read<uint>();
    }

}

void NiTimeController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_NextController.Write(writer, version, user, 0);

    writer.Write(m_Flags);

    writer.Write(m_Frequency);

    writer.Write(m_Phase);

    writer.Write(m_StartTime);

    writer.Write(m_StopTime);

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_Target.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_UnknownInteger);
    }

}
