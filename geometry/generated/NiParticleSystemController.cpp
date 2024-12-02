#include "NiParticleSystemController.hpp"

using namespace nejlika::geometry;

void NiParticleSystemController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_OldSpeed = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_Speed = reader.Read<float>();
    }

    m_SpeedRandom = reader.Read<float>();

    m_VerticalDirection = reader.Read<float>();

    m_VerticalAngle = reader.Read<float>();

    m_HorizontalDirection = reader.Read<float>();

    m_HorizontalAngle = reader.Read<float>();

    m_UnknownNormal.Read(reader, version, user, 0);

    m_UnknownColor.Read(reader, version, user, 0);

    m_Size = reader.Read<float>();

    m_EmitStartTime = reader.Read<float>();

    m_EmitStopTime = reader.Read<float>();

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownByte = reader.Read<byte>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_OldEmitRate = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_EmitRate = reader.Read<float>();
    }

    m_Lifetime = reader.Read<float>();

    m_LifetimeRandom = reader.Read<float>();

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_EmitFlags = reader.Read<ushort>();
    }

    m_StartRandom.Read(reader, version, user, 0);

    m_Emitter.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownFloat13 = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownInt1 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownShort3 = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleVelocity.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleUnknownVector.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleLifetime = reader.Read<float>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleLink.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleTimestamp = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleUnknownShort = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleVertexId = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_NumParticles = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_NumValid = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_Particles.resize(m_NumParticles);
        for (uint32_t i = 0; i < m_Particles.size(); i++)
        {
            m_Particles[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownLink.Read(reader, version, user, 0);
    }

    m_ParticleExtra.Read(reader, version, user, 0);

    m_UnknownLink2.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_Trailer = reader.Read<byte>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ColorData.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownFloat1 = reader.Read<float>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownFloats2.resize(m_ParticleUnknownShort);
        for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
        {
            m_UnknownFloats2[i] = reader.Read<float>();
        }
    }

}

void NiParticleSystemController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_OldSpeed);
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        writer.Write(m_Speed);
    }

    writer.Write(m_SpeedRandom);

    writer.Write(m_VerticalDirection);

    writer.Write(m_VerticalAngle);

    writer.Write(m_HorizontalDirection);

    writer.Write(m_HorizontalAngle);

    m_UnknownNormal.Write(writer, version, user, 0);

    m_UnknownColor.Write(writer, version, user, 0);

    writer.Write(m_Size);

    writer.Write(m_EmitStartTime);

    writer.Write(m_EmitStopTime);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownByte);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_OldEmitRate);
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        writer.Write(m_EmitRate);
    }

    writer.Write(m_Lifetime);

    writer.Write(m_LifetimeRandom);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_EmitFlags);
    }

    m_StartRandom.Write(writer, version, user, 0);

    m_Emitter.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownShort2);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownFloat13);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownInt1);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_UnknownShort3);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleVelocity.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleUnknownVector.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_ParticleLifetime);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ParticleLink.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_ParticleTimestamp);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_ParticleUnknownShort);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_ParticleVertexId);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_NumParticles);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_NumValid);
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        for (uint32_t i = 0; i < m_Particles.size(); i++)
        {
            m_Particles[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_UnknownLink.Write(writer, version, user, 0);
    }

    m_ParticleExtra.Write(writer, version, user, 0);

    m_UnknownLink2.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_Trailer);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_ColorData.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_UnknownFloat1);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
        {
            writer.Write(m_UnknownFloats2[i]);
        }
    }

}
