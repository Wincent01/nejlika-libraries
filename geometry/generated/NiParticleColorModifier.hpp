#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiColorData.hpp"
#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiParticleColorModifier : public NiParticleModifier
{
protected:
    /**
     * Color data index.
     */
    Pointer<class NiColorData*> m_ColorData;

public:
    const Pointer<class NiColorData*>& GetColorData() const { return m_ColorData; }
    Pointer<class NiColorData*>& GetColorData() { return m_ColorData; }
    void SetColorData(const Pointer<class NiColorData*>& value) { m_ColorData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
