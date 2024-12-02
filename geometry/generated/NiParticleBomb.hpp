#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "DecayType.hpp"
#include "SymmetryType.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle modifier.
 *         
 */
class NiParticleBomb : public NiParticleModifier
{
protected:
    /**
     * Unknown.
     */
    float m_Decay;
    /**
     * Unknown.
     */
    float m_Duration;
    /**
     * Unknown.
     */
    float m_DeltaV;
    /**
     * Unknown.
     */
    float m_Start;
    /**
     * Unknown.
     */
    DecayType m_DecayType;
    /**
     * Unknown.
     */
    SymmetryType m_SymmetryType;
    /**
     * The position of the mass point relative to the particle system?
     */
    Vector3 m_Position;
    /**
     * The direction of the applied acceleration?
     */
    Vector3 m_Direction;

public:
    const float& GetDecay() const { return m_Decay; }
    float& GetDecay() { return m_Decay; }
    void SetDecay(const float& value) { m_Decay = value; }

    const float& GetDuration() const { return m_Duration; }
    float& GetDuration() { return m_Duration; }
    void SetDuration(const float& value) { m_Duration = value; }

    const float& GetDeltaV() const { return m_DeltaV; }
    float& GetDeltaV() { return m_DeltaV; }
    void SetDeltaV(const float& value) { m_DeltaV = value; }

    const float& GetStart() const { return m_Start; }
    float& GetStart() { return m_Start; }
    void SetStart(const float& value) { m_Start = value; }

    const DecayType& GetDecayType() const { return m_DecayType; }
    DecayType& GetDecayType() { return m_DecayType; }
    void SetDecayType(const DecayType& value) { m_DecayType = value; }

    const SymmetryType& GetSymmetryType() const { return m_SymmetryType; }
    SymmetryType& GetSymmetryType() { return m_SymmetryType; }
    void SetSymmetryType(const SymmetryType& value) { m_SymmetryType = value; }

    const Vector3& GetPosition() const { return m_Position; }
    Vector3& GetPosition() { return m_Position; }
    void SetPosition(const Vector3& value) { m_Position = value; }

    const Vector3& GetDirection() const { return m_Direction; }
    Vector3& GetDirection() { return m_Direction; }
    void SetDirection(const Vector3& value) { m_Direction = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
