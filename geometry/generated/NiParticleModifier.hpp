#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiParticleModifier.hpp"
#include "NiParticleSystemController.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system modifier.
 *         
 */
class NiParticleModifier : public NiObject
{
protected:
    /**
     * Next particle modifier.
     */
    Pointer<class NiParticleModifier*> m_NextModifier;
    /**
     * Points to the particle system controller parent.
     */
    Pointer<class NiParticleSystemController*> m_Controller;

public:
    const Pointer<class NiParticleModifier*>& GetNextModifier() const { return m_NextModifier; }
    Pointer<class NiParticleModifier*>& GetNextModifier() { return m_NextModifier; }
    void SetNextModifier(const Pointer<class NiParticleModifier*>& value) { m_NextModifier = value; }

    const Pointer<class NiParticleSystemController*>& GetController() const { return m_Controller; }
    Pointer<class NiParticleSystemController*>& GetController() { return m_Controller; }
    void SetController(const Pointer<class NiParticleSystemController*>& value) { m_Controller = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
