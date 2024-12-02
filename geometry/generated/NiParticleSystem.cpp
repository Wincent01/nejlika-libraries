#include "NiParticleSystem.hpp"

using namespace nejlika::geometry;

void NiParticleSystem::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticles::Read(reader, version, user, arg);

    if (user>= 12)
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    if (user>= 12)
    {
        m_UnknownShort3 = reader.Read<ushort>();
    }

    if (user>= 12)
    {
        m_UnknownInt1 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_WorldSpace = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_NumModifiers = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Modifiers.resize(m_NumModifiers);
        for (uint32_t i = 0; i < m_Modifiers.size(); i++)
        {
            m_Modifiers[i].Read(reader, version, user, 0);
        }
    }

}

void NiParticleSystem::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticles::Write(writer, version, user, arg);

    if (user>= 12)
    {
        writer.Write(m_UnknownShort2);
    }

    if (user>= 12)
    {
        writer.Write(m_UnknownShort3);
    }

    if (user>= 12)
    {
        writer.Write(m_UnknownInt1);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_WorldSpace);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_NumModifiers);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        for (uint32_t i = 0; i < m_Modifiers.size(); i++)
        {
            m_Modifiers[i].Write(writer, version, user, 0);
        }
    }

}
