#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FieldType.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle modifier; applies a gravitational field on the particles.
 *         
 */
class NiGravity : public NiParticleModifier
{
protected:
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * The strength/force of this gravity.
     */
    float m_Force;
    /**
     * The force field's type.
     */
    FieldType m_Type;
    /**
     * The position of the mass point relative to the particle system. (TODO: check for versions <= 3.1)
     */
    Vector3 m_Position;
    /**
     * The direction of the applied acceleration.
     */
    Vector3 m_Direction;

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetForce() const { return m_Force; }
    float& GetForce() { return m_Force; }
    void SetForce(const float& value) { m_Force = value; }

    const FieldType& GetType() const { return m_Type; }
    FieldType& GetType() { return m_Type; }
    void SetType(const FieldType& value) { m_Type = value; }

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
