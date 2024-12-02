#include "BSPSysRecycleBoundModifier.hpp"

using namespace nejlika::geometry;

void BSPSysRecycleBoundModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownFloat5 = reader.Read<float>();

    m_UnknownFloat6 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<uint>();

}

void BSPSysRecycleBoundModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownFloat5);

    writer.Write(m_UnknownFloat6);

    writer.Write(m_UnknownInt1);

}
