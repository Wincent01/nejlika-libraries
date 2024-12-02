#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiPSSimulatorStep.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Encapsulates a floodgate kernel that simulates particle colliders.
 *         
 */
class NiPSSimulatorCollidersStep : public NiPSSimulatorStep
{
protected:
    /**
     * The number of colliders affecting the particle system.
     */
    uint m_NumColliders;
    /**
     * The colliders affecting the particle system.
     */
    std::vector<Pointer<class NiObject*>> m_Colliders;

public:
    const uint& GetNumColliders() const { return m_NumColliders; }
    uint& GetNumColliders() { return m_NumColliders; }
    void SetNumColliders(const uint& value) { m_NumColliders = value; }

    const std::vector<Pointer<class NiObject*>>& GetColliders() const { return m_Colliders; }
    std::vector<Pointer<class NiObject*>>& GetColliders() { return m_Colliders; }
    void SetColliders(const std::vector<Pointer<class NiObject*>>& value) { m_Colliders = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
