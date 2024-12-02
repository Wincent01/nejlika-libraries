#include "NiPSMeshParticleSystem.hpp"

using namespace nejlika::geometry;

void NiPSMeshParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSParticleSystem::Read(reader, version, user, arg);

    m_Unknown23 = reader.Read<int>();

    m_Unknown24 = reader.Read<int>();

    m_Unknown25 = reader.Read<int>();

    m_Unknown26 = reader.Read<byte>();

}

void NiPSMeshParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSParticleSystem::Write(writer, version, user, arg);

    writer.Write(m_Unknown23);

    writer.Write(m_Unknown24);

    writer.Write(m_Unknown25);

    writer.Write(m_Unknown26);

}
