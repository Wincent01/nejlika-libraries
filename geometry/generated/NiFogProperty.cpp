#include "NiFogProperty.hpp"

using namespace nejlika::geometry;

void NiFogProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    m_FogDepth = reader.Read<float>();

    m_FogColor.Read(reader, version, user, 0);

}

void NiFogProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    writer.Write(m_FogDepth);

    m_FogColor.Write(writer, version, user, 0);

}
