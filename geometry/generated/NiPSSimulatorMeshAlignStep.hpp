#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "QuatKey.hpp"
#include "Quaternion.hpp"
#include "PSLoopBehavior.hpp"
#include "NiPSSimulatorStep.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Encapsulates a floodgate kernel that updates mesh particle alignment and transforms.
 *         
 */
class NiPSSimulatorMeshAlignStep : public NiPSSimulatorStep
{
protected:
    /**
     * The number of rotation keys.
     */
    byte m_NumRotationKeys;
    /**
     * The particle rotation keys.
     */
    std::vector<QuatKey<Quaternion>> m_RotationKeys;
    /**
     * The loop behavior for the rotation keys.
     */
    PSLoopBehavior m_RotationLoopBehavior;

public:
    const byte& GetNumRotationKeys() const { return m_NumRotationKeys; }
    byte& GetNumRotationKeys() { return m_NumRotationKeys; }
    void SetNumRotationKeys(const byte& value) { m_NumRotationKeys = value; }

    const std::vector<QuatKey<Quaternion>>& GetRotationKeys() const { return m_RotationKeys; }
    std::vector<QuatKey<Quaternion>>& GetRotationKeys() { return m_RotationKeys; }
    void SetRotationKeys(const std::vector<QuatKey<Quaternion>>& value) { m_RotationKeys = value; }

    const PSLoopBehavior& GetRotationLoopBehavior() const { return m_RotationLoopBehavior; }
    PSLoopBehavior& GetRotationLoopBehavior() { return m_RotationLoopBehavior; }
    void SetRotationLoopBehavior(const PSLoopBehavior& value) { m_RotationLoopBehavior = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
