#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "Vector3.hpp"
#include "DecayType.hpp"
#include "SymmetryType.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that uses a NiNode to use as a "Bomb Object" to alter the path of particles.
 *         
 */
class NiPSysBombModifier : public NiPSysModifier
{
protected:
    /**
     * Link to a NiNode for bomb to function.
     */
    Pointer<class NiNode*> m_BombObject;
    /**
     * Orientation of bomb object.
     */
    Vector3 m_BombAxis;
    /**
     * Falloff rate of the bomb object.
     */
    float m_Decay;
    /**
     * DeltaV /  Strength?
     */
    float m_DeltaV;
    /**
     * Decay type
     */
    DecayType m_DecayType;
    /**
     * Shape/symmetry of the bomb object.
     */
    SymmetryType m_SymmetryType;

public:
    const Pointer<class NiNode*>& GetBombObject() const { return m_BombObject; }
    Pointer<class NiNode*>& GetBombObject() { return m_BombObject; }
    void SetBombObject(const Pointer<class NiNode*>& value) { m_BombObject = value; }

    const Vector3& GetBombAxis() const { return m_BombAxis; }
    Vector3& GetBombAxis() { return m_BombAxis; }
    void SetBombAxis(const Vector3& value) { m_BombAxis = value; }

    const float& GetDecay() const { return m_Decay; }
    float& GetDecay() { return m_Decay; }
    void SetDecay(const float& value) { m_Decay = value; }

    const float& GetDeltaV() const { return m_DeltaV; }
    float& GetDeltaV() { return m_DeltaV; }
    void SetDeltaV(const float& value) { m_DeltaV = value; }

    const DecayType& GetDecayType() const { return m_DecayType; }
    DecayType& GetDecayType() { return m_DecayType; }
    void SetDecayType(const DecayType& value) { m_DecayType = value; }

    const SymmetryType& GetSymmetryType() const { return m_SymmetryType; }
    SymmetryType& GetSymmetryType() { return m_SymmetryType; }
    void SetSymmetryType(const SymmetryType& value) { m_SymmetryType = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
