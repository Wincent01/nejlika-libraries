#include "Ni3dsParticleSystem.hpp"

using namespace nejlika::geometry;

void Ni3dsParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1.resize(14);
    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        m_Unknown1[i] = reader.Read<byte>();
    }

}

void Ni3dsParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        writer.Write(m_Unknown1[i]);
    }

}
