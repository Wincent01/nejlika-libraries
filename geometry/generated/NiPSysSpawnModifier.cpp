#include "NiPSysSpawnModifier.hpp"

using namespace nejlika::geometry;

void NiPSysSpawnModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_NumSpawnGenerations = reader.Read<ushort>();

    m_PercentageSpawned = reader.Read<float>();

    m_MinNumToSpawn = reader.Read<ushort>();

    m_MaxNumToSpawn = reader.Read<ushort>();

    m_SpawnSpeedChaos = reader.Read<float>();

    m_SpawnDirChaos = reader.Read<float>();

    m_LifeSpan = reader.Read<float>();

    m_LifeSpanVariation = reader.Read<float>();

    if (version >= VERSION_NUMBER(10, 4, 0, 1) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_UnknownInt = reader.Read<int>();
    }

}

void NiPSysSpawnModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_NumSpawnGenerations);

    writer.Write(m_PercentageSpawned);

    writer.Write(m_MinNumToSpawn);

    writer.Write(m_MaxNumToSpawn);

    writer.Write(m_SpawnSpeedChaos);

    writer.Write(m_SpawnDirChaos);

    writer.Write(m_LifeSpan);

    writer.Write(m_LifeSpanVariation);

    if (version >= VERSION_NUMBER(10, 4, 0, 1) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_UnknownInt);
    }

}
