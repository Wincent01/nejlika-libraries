#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysSpawnModifier.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown particle modifier.
 *         
 */
class NiPSysAgeDeathModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown.
     */
    bool m_SpawnOnDeath;
    /**
     * Link to NiPSysSpawnModifier object?
     */
    Pointer<class NiPSysSpawnModifier*> m_SpawnModifier;

public:
    const bool& GetSpawnOnDeath() const { return m_SpawnOnDeath; }
    bool& GetSpawnOnDeath() { return m_SpawnOnDeath; }
    void SetSpawnOnDeath(const bool& value) { m_SpawnOnDeath = value; }

    const Pointer<class NiPSysSpawnModifier*>& GetSpawnModifier() const { return m_SpawnModifier; }
    Pointer<class NiPSysSpawnModifier*>& GetSpawnModifier() { return m_SpawnModifier; }
    void SetSpawnModifier(const Pointer<class NiPSysSpawnModifier*>& value) { m_SpawnModifier = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
