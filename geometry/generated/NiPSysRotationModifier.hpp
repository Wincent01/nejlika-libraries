#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that adds rotations to particles.
 *         
 */
class NiPSysRotationModifier : public NiPSysModifier
{
protected:
    /**
     * The initial speed of rotation.
     */
    float m_InitialRotationSpeed;
    /**
     * Adds a ranged randomness to rotation speed.
     */
    float m_InitialRotationSpeedVariation;
    /**
     * Sets the intial angle for particles to be birthed in.
     */
    float m_InitialRotationAngle;
    /**
     * Adds a random range to Initial angle.
     */
    float m_InitialRotationAngleVariation;
    /**
     * Unknown
     */
    bool m_RandomRotSpeedSign;
    /**
     * Unknown.
     */
    bool m_RandomInitialAxis;
    /**
     * Unknown.
     */
    Vector3 m_InitialAxis;

public:
    const float& GetInitialRotationSpeed() const { return m_InitialRotationSpeed; }
    float& GetInitialRotationSpeed() { return m_InitialRotationSpeed; }
    void SetInitialRotationSpeed(const float& value) { m_InitialRotationSpeed = value; }

    const float& GetInitialRotationSpeedVariation() const { return m_InitialRotationSpeedVariation; }
    float& GetInitialRotationSpeedVariation() { return m_InitialRotationSpeedVariation; }
    void SetInitialRotationSpeedVariation(const float& value) { m_InitialRotationSpeedVariation = value; }

    const float& GetInitialRotationAngle() const { return m_InitialRotationAngle; }
    float& GetInitialRotationAngle() { return m_InitialRotationAngle; }
    void SetInitialRotationAngle(const float& value) { m_InitialRotationAngle = value; }

    const float& GetInitialRotationAngleVariation() const { return m_InitialRotationAngleVariation; }
    float& GetInitialRotationAngleVariation() { return m_InitialRotationAngleVariation; }
    void SetInitialRotationAngleVariation(const float& value) { m_InitialRotationAngleVariation = value; }

    const bool& GetRandomRotSpeedSign() const { return m_RandomRotSpeedSign; }
    bool& GetRandomRotSpeedSign() { return m_RandomRotSpeedSign; }
    void SetRandomRotSpeedSign(const bool& value) { m_RandomRotSpeedSign = value; }

    const bool& GetRandomInitialAxis() const { return m_RandomInitialAxis; }
    bool& GetRandomInitialAxis() { return m_RandomInitialAxis; }
    void SetRandomInitialAxis(const bool& value) { m_RandomInitialAxis = value; }

    const Vector3& GetInitialAxis() const { return m_InitialAxis; }
    Vector3& GetInitialAxis() { return m_InitialAxis; }
    void SetInitialAxis(const Vector3& value) { m_InitialAxis = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
