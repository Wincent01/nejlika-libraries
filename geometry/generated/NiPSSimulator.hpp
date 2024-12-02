#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSSimulatorStep.hpp"
#include "NiMeshModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         The mesh modifier that performs all particle system simulation.
 *         
 */
class NiPSSimulator : public NiMeshModifier
{
protected:
    /**
     * The number of simulation steps in this modifier.
     */
    uint m_NumSimulationSteps;
    /**
     * Links to the simulation steps.
     */
    std::vector<Pointer<class NiPSSimulatorStep*>> m_SimulationSteps;

public:
    const uint& GetNumSimulationSteps() const { return m_NumSimulationSteps; }
    uint& GetNumSimulationSteps() { return m_NumSimulationSteps; }
    void SetNumSimulationSteps(const uint& value) { m_NumSimulationSteps = value; }

    const std::vector<Pointer<class NiPSSimulatorStep*>>& GetSimulationSteps() const { return m_SimulationSteps; }
    std::vector<Pointer<class NiPSSimulatorStep*>>& GetSimulationSteps() { return m_SimulationSteps; }
    void SetSimulationSteps(const std::vector<Pointer<class NiPSSimulatorStep*>>& value) { m_SimulationSteps = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
