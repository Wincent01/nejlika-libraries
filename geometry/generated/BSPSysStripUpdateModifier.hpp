#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific (mesh?) Particle System Modifier.
 *         
 */
class BSPSysStripUpdateModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown
     */
    float m_UpdateDeltaTime;

public:
    const float& GetUpdateDeltaTime() const { return m_UpdateDeltaTime; }
    float& GetUpdateDeltaTime() { return m_UpdateDeltaTime; }
    void SetUpdateDeltaTime(const float& value) { m_UpdateDeltaTime = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
