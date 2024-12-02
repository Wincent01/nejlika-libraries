#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiColorData.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that adds keyframe data to modify color/alpha values of particles over time.
 *         
 */
class NiPSysColorModifier : public NiPSysModifier
{
protected:
    /**
     * Refers to NiColorData object.
     */
    Pointer<class NiColorData*> m_Data;

public:
    const Pointer<class NiColorData*>& GetData() const { return m_Data; }
    Pointer<class NiColorData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiColorData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
