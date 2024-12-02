#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown particle modifier.
 *         
 */
class NiPSysSpawnModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown.
     */
    ushort m_NumSpawnGenerations;
    /**
     * Unknown.
     */
    float m_PercentageSpawned;
    /**
     * Unknown.
     */
    ushort m_MinNumToSpawn;
    /**
     * Unknown.
     */
    ushort m_MaxNumToSpawn;
    /**
     * Unknown.
     */
    float m_SpawnSpeedChaos;
    /**
     * Unknown.
     */
    float m_SpawnDirChaos;
    /**
     * Unknown.
     */
    float m_LifeSpan;
    /**
     * Unknown.
     */
    float m_LifeSpanVariation;
    /**
     * Unknown
     */
    int m_UnknownInt;

public:
    const ushort& GetNumSpawnGenerations() const { return m_NumSpawnGenerations; }
    ushort& GetNumSpawnGenerations() { return m_NumSpawnGenerations; }
    void SetNumSpawnGenerations(const ushort& value) { m_NumSpawnGenerations = value; }

    const float& GetPercentageSpawned() const { return m_PercentageSpawned; }
    float& GetPercentageSpawned() { return m_PercentageSpawned; }
    void SetPercentageSpawned(const float& value) { m_PercentageSpawned = value; }

    const ushort& GetMinNumToSpawn() const { return m_MinNumToSpawn; }
    ushort& GetMinNumToSpawn() { return m_MinNumToSpawn; }
    void SetMinNumToSpawn(const ushort& value) { m_MinNumToSpawn = value; }

    const ushort& GetMaxNumToSpawn() const { return m_MaxNumToSpawn; }
    ushort& GetMaxNumToSpawn() { return m_MaxNumToSpawn; }
    void SetMaxNumToSpawn(const ushort& value) { m_MaxNumToSpawn = value; }

    const float& GetSpawnSpeedChaos() const { return m_SpawnSpeedChaos; }
    float& GetSpawnSpeedChaos() { return m_SpawnSpeedChaos; }
    void SetSpawnSpeedChaos(const float& value) { m_SpawnSpeedChaos = value; }

    const float& GetSpawnDirChaos() const { return m_SpawnDirChaos; }
    float& GetSpawnDirChaos() { return m_SpawnDirChaos; }
    void SetSpawnDirChaos(const float& value) { m_SpawnDirChaos = value; }

    const float& GetLifeSpan() const { return m_LifeSpan; }
    float& GetLifeSpan() { return m_LifeSpan; }
    void SetLifeSpan(const float& value) { m_LifeSpan = value; }

    const float& GetLifeSpanVariation() const { return m_LifeSpanVariation; }
    float& GetLifeSpanVariation() { return m_LifeSpanVariation; }
    void SetLifeSpanVariation(const float& value) { m_LifeSpanVariation = value; }

    const int& GetUnknownInt() const { return m_UnknownInt; }
    int& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const int& value) { m_UnknownInt = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
