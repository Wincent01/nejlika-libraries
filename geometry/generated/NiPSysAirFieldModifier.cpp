#include "NiPSysAirFieldModifier.hpp"

using namespace nejlika::geometry;

void NiPSysAirFieldModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysFieldModifier::Read(reader, version, user, arg);

    m_Direction.Read(reader, version, user, 0);

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownBoolean1 = reader.Read<bool>();

    m_UnknownBoolean2 = reader.Read<bool>();

    m_UnknownBoolean3 = reader.Read<bool>();

    m_UnknownFloat4 = reader.Read<float>();

}

void NiPSysAirFieldModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysFieldModifier::Write(writer, version, user, arg);

    m_Direction.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownBoolean1);

    writer.Write(m_UnknownBoolean2);

    writer.Write(m_UnknownBoolean3);

    writer.Write(m_UnknownFloat4);

}
