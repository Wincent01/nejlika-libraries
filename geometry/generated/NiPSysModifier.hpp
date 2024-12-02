#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiParticleSystem.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Generic particle system modifier object.
 *         
 */
class NiPSysModifier : public NiObject
{
protected:
    /**
     * The object name.
     */
    string m_Name;
    /**
     * Modifier ID in the particle modifier chain (always a multiple of 1000)?
     */
    uint m_Order;
    /**
     * NiParticleSystem parent of this modifier.
     */
    Pointer<class NiParticleSystem*> m_Target;
    /**
     * Whether the modifier is currently in effect?  Usually true.
     */
    bool m_Active;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const uint& GetOrder() const { return m_Order; }
    uint& GetOrder() { return m_Order; }
    void SetOrder(const uint& value) { m_Order = value; }

    const Pointer<class NiParticleSystem*>& GetTarget() const { return m_Target; }
    Pointer<class NiParticleSystem*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiParticleSystem*>& value) { m_Target = value; }

    const bool& GetActive() const { return m_Active; }
    bool& GetActive() { return m_Active; }
    void SetActive(const bool& value) { m_Active = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
