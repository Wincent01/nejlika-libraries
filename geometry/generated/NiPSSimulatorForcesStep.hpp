#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiPSSimulatorStep.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Encapsulates a floodgate kernel that simulates particle forces.
 *         
 */
class NiPSSimulatorForcesStep : public NiPSSimulatorStep
{
protected:
    /**
     * The number of forces affecting the particle system.
     */
    uint m_NumForces;
    /**
     * The forces affecting the particle system.
     */
    std::vector<Pointer<class NiObject*>> m_Forces;

public:
    const uint& GetNumForces() const { return m_NumForces; }
    uint& GetNumForces() { return m_NumForces; }
    void SetNumForces(const uint& value) { m_NumForces = value; }

    const std::vector<Pointer<class NiObject*>>& GetForces() const { return m_Forces; }
    std::vector<Pointer<class NiObject*>>& GetForces() { return m_Forces; }
    void SetForces(const std::vector<Pointer<class NiObject*>>& value) { m_Forces = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
