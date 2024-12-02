#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "MotorDescriptor.hpp"
namespace nejlika::geometry {


/**
 * 
 *         This constraint defines a cone in which an object can rotate. The shape of the cone can be controlled in two (orthogonal) directions.
 *         
 */
class RagdollDescriptor : public Construct
{
protected:
    /**
     * The point where the constraint is attached to its parent rigidbody.
     */
    Vector4 m_PivotA;
    /**
     * Defines the orthogonal plane in which the body can move, the orthogonal directions in which the shape can be controlled (the direction orthogonal on this one and Twist A).
     */
    Vector4 m_PlaneA;
    /**
     * Central directed axis of the cone in which the object can rotate. Orthogonal on Plane A.
     */
    Vector4 m_TwistA;
    /**
     * The point where the constraint is attached to the other rigidbody.
     */
    Vector4 m_PivotB;
    /**
     * Defines the orthogonal plane in which the shape can be controlled (the direction orthogonal on this one and Twist B).
     */
    Vector4 m_PlaneB;
    /**
     * Central directed axis of the cone in which the object can rotate. Orthogonal on Plane B.
     */
    Vector4 m_TwistB;
    /**
     * Defines the orthogonal directions in which the shape can be controlled (namely in this direction, and in the direction orthogonal on this one and Twist A).
     */
    Vector4 m_MotorA;
    /**
     * Defines the orthogonal directions in which the shape can be controlled (namely in this direction, and in the direction orthogonal on this one and Twist A).
     */
    Vector4 m_MotorB;
    /**
     * Maximum angle the object can rotate around the vector orthogonal on Plane A and Twist A relative to the Twist A vector. Note that Cone Min Angle is not stored, but is simply minus this angle.
     */
    float m_ConeMaxAngle;
    /**
     * Minimum angle the object can rotate around Plane A, relative to Twist A.
     */
    float m_PlaneMinAngle;
    /**
     * Maximum angle the object can rotate around Plane A, relative to Twist A.
     */
    float m_PlaneMaxAngle;
    /**
     * Minimum angle the object can rotate around Twist A, relative to Plane A.
     */
    float m_TwistMinAngle;
    /**
     * Maximum angle the object can rotate around Twist A, relative to Plane A.
     */
    float m_TwistMaxAngle;
    /**
     * Maximum friction, typically 0 or 10. In Fallout 3, typically 100.
     */
    float m_MaxFriction;
    /**
     * Unknown
     */
    bool m_EnableMotor;
    MotorDescriptor m_Motor;

public:
    const Vector4& GetPivotA() const { return m_PivotA; }
    Vector4& GetPivotA() { return m_PivotA; }
    void SetPivotA(const Vector4& value) { m_PivotA = value; }

    const Vector4& GetPlaneA() const { return m_PlaneA; }
    Vector4& GetPlaneA() { return m_PlaneA; }
    void SetPlaneA(const Vector4& value) { m_PlaneA = value; }

    const Vector4& GetTwistA() const { return m_TwistA; }
    Vector4& GetTwistA() { return m_TwistA; }
    void SetTwistA(const Vector4& value) { m_TwistA = value; }

    const Vector4& GetPivotB() const { return m_PivotB; }
    Vector4& GetPivotB() { return m_PivotB; }
    void SetPivotB(const Vector4& value) { m_PivotB = value; }

    const Vector4& GetPlaneB() const { return m_PlaneB; }
    Vector4& GetPlaneB() { return m_PlaneB; }
    void SetPlaneB(const Vector4& value) { m_PlaneB = value; }

    const Vector4& GetTwistB() const { return m_TwistB; }
    Vector4& GetTwistB() { return m_TwistB; }
    void SetTwistB(const Vector4& value) { m_TwistB = value; }

    const Vector4& GetMotorA() const { return m_MotorA; }
    Vector4& GetMotorA() { return m_MotorA; }
    void SetMotorA(const Vector4& value) { m_MotorA = value; }

    const Vector4& GetMotorB() const { return m_MotorB; }
    Vector4& GetMotorB() { return m_MotorB; }
    void SetMotorB(const Vector4& value) { m_MotorB = value; }

    const float& GetConeMaxAngle() const { return m_ConeMaxAngle; }
    float& GetConeMaxAngle() { return m_ConeMaxAngle; }
    void SetConeMaxAngle(const float& value) { m_ConeMaxAngle = value; }

    const float& GetPlaneMinAngle() const { return m_PlaneMinAngle; }
    float& GetPlaneMinAngle() { return m_PlaneMinAngle; }
    void SetPlaneMinAngle(const float& value) { m_PlaneMinAngle = value; }

    const float& GetPlaneMaxAngle() const { return m_PlaneMaxAngle; }
    float& GetPlaneMaxAngle() { return m_PlaneMaxAngle; }
    void SetPlaneMaxAngle(const float& value) { m_PlaneMaxAngle = value; }

    const float& GetTwistMinAngle() const { return m_TwistMinAngle; }
    float& GetTwistMinAngle() { return m_TwistMinAngle; }
    void SetTwistMinAngle(const float& value) { m_TwistMinAngle = value; }

    const float& GetTwistMaxAngle() const { return m_TwistMaxAngle; }
    float& GetTwistMaxAngle() { return m_TwistMaxAngle; }
    void SetTwistMaxAngle(const float& value) { m_TwistMaxAngle = value; }

    const float& GetMaxFriction() const { return m_MaxFriction; }
    float& GetMaxFriction() { return m_MaxFriction; }
    void SetMaxFriction(const float& value) { m_MaxFriction = value; }

    const bool& GetEnableMotor() const { return m_EnableMotor; }
    bool& GetEnableMotor() { return m_EnableMotor; }
    void SetEnableMotor(const bool& value) { m_EnableMotor = value; }

    const MotorDescriptor& GetMotor() const { return m_Motor; }
    MotorDescriptor& GetMotor() { return m_Motor; }
    void SetMotor(const MotorDescriptor& value) { m_Motor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
