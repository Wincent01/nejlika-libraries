#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiParticleRotation : public NiParticleModifier
{
protected:
    /**
     * Unknown.
     */
    byte m_RandomInitialAxis;
    /**
     * Unknown.
     */
    Vector3 m_InitialAxis;
    /**
     * Unknown.
     */
    float m_RotationSpeed;

public:
    const byte& GetRandomInitialAxis() const { return m_RandomInitialAxis; }
    byte& GetRandomInitialAxis() { return m_RandomInitialAxis; }
    void SetRandomInitialAxis(const byte& value) { m_RandomInitialAxis = value; }

    const Vector3& GetInitialAxis() const { return m_InitialAxis; }
    Vector3& GetInitialAxis() { return m_InitialAxis; }
    void SetInitialAxis(const Vector3& value) { m_InitialAxis = value; }

    const float& GetRotationSpeed() const { return m_RotationSpeed; }
    float& GetRotationSpeed() { return m_RotationSpeed; }
    void SetRotationSpeed(const float& value) { m_RotationSpeed = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
