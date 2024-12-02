#include "NiGravity.hpp"

using namespace nejlika::geometry;

void NiGravity::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticleModifier::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownFloat1 = reader.Read<float>();
    }

    m_Force = reader.Read<float>();

    m_Type = reader.Read<FieldType>();

    m_Position.Read(reader, version, user, 0);

    m_Direction.Read(reader, version, user, 0);

}

void NiGravity::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticleModifier::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownFloat1);
    }

    writer.Write(m_Force);

    writer.Write(m_Type);

    m_Position.Write(writer, version, user, 0);

    m_Direction.Write(writer, version, user, 0);

}
