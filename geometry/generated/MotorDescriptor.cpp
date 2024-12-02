#include "MotorDescriptor.hpp"

using namespace nejlika::geometry;

void MotorDescriptor::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownFloat5 = reader.Read<float>();

    m_UnknownFloat6 = reader.Read<float>();

    m_UnknownByte1 = reader.Read<byte>();

}

void MotorDescriptor::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownFloat5);

    writer.Write(m_UnknownFloat6);

    writer.Write(m_UnknownByte1);

}
