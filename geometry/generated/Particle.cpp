#include "Particle.hpp"

using namespace nejlika::geometry;

void Particle::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Velocity.Read(reader, version, user, 0);

    m_UnknownVector.Read(reader, version, user, 0);

    m_Lifetime = reader.Read<float>();

    m_Lifespan = reader.Read<float>();

    m_Timestamp = reader.Read<float>();

    m_UnknownShort = reader.Read<ushort>();

    m_VertexID = reader.Read<ushort>();

}

void Particle::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Velocity.Write(writer, version, user, 0);

    m_UnknownVector.Write(writer, version, user, 0);

    writer.Write(m_Lifetime);

    writer.Write(m_Lifespan);

    writer.Write(m_Timestamp);

    writer.Write(m_UnknownShort);

    writer.Write(m_VertexID);

}
