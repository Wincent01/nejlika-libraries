#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "hkResponseType.hpp"
#include "OblivionLayer.hpp"
#include "SkyrimLayer.hpp"
#include "Vector4.hpp"
#include "QuaternionXYZW.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "InertiaMatrix.hpp"
#include "Vector4.hpp"
#include "MotionSystem.hpp"
#include "DeactivatorType.hpp"
#include "SolverDeactivation.hpp"
#include "MotionQuality.hpp"
#include "bhkSerializable.hpp"
#include "bhkEntity.hpp"
namespace nejlika::geometry {


/**
 * 
 *         This is the default body type for all "normal" usable and static world objects. The "T" suffix
 *         marks this body as active for translation and rotation, a normal bhkRigidBody ignores those
 *         properties. Because the properties are equal, a bhkRigidBody may be renamed
 *         into a bhkRigidBodyT and vice-versa.
 *         
 */
class bhkRigidBody : public bhkEntity
{
protected:
    /**
     * Unknown. Could be 2 shorts corresponding to Unknown 7 Shorts[1] and [2].
     */
    int m_UnknownInt1;
    /**
     * Unknown.
     */
    int m_UnknownInt2;
    /**
     * Unknown. Could be 3 floats.
     */
    std::vector<int> m_Unknown3Ints;
    /**
     * The collision response. See hkResponseType for hkpWorld default implementations.
     */
    hkResponseType m_CollisionResponse;
    /**
     * Unknown
     */
    byte m_UnknownByte;
    /**
     * Lowers the frequency for processContactCallbacks. A value of 5 means that a callback is raised every 5th frame.
     */
    ushort m_ProcessContactCallbackDelay;
    /**
     * Unknown.
     */
    std::vector<ushort> m_Unknown2Shorts;
    /**
     * Copy of Layer value?
     */
    OblivionLayer m_LayerCopy;
    /**
     * Copy of Col Filter value?
     */
    byte m_ColFilterCopy;
    /**
     * Copy of Skyrim Layer value?
     */
    SkyrimLayer m_SkyrimLayerCopy;
    /**
     * Copy of Flags & Part number?
     */
    byte m_FlagsAndPartNumberCopy;
    /**
     * 
     *             Unknown.
     *             Oblivion defaults: 0 21280 2481 62977 65535 44 0
     *             Skyrim defaults: 0 56896 1343 0 0 1 65535 (fourth and fifth element *must* be zero)
     *         
     */
    std::vector<ushort> m_Unknown7Shorts;
    /**
     *  A vector that moves the body by the specified amount. Only enabled in bhkRigidBodyT objects.
     */
    Vector4 m_Translation;
    /**
     * The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT objects.
     */
    QuaternionXYZW m_Rotation;
    /**
     * Linear velocity.
     */
    Vector4 m_LinearVelocity;
    /**
     * Angular velocity.
     */
    Vector4 m_AngularVelocity;
    /**
     * Defines how the mass is distributed among the body.
     */
    InertiaMatrix m_Inertia;
    /**
     *  This seems to be used to relocate the object's center of mass. Useful for balancing objects in contraints.
     */
    Vector4 m_Center;
    /**
     * The body's mass in kg. A mass of zero represents an immovable object.
     */
    float m_Mass;
    /**
     *  Damping value for linear movement. A value that is too small fixes the object in place.
     */
    float m_LinearDamping;
    /**
     *  Damping value for angular movement.
     */
    float m_AngularDamping;
    float m_UnknownTimeFactorOrGravityFactor1;
    float m_UnknownTimeFactorOrGravityFactor2;
    /**
     * The body's friction.
     */
    float m_Friction;
    float m_RollingFrictionMultiplier;
    /**
     * 
     *             The body's restitution (elasticity).
     *             If the restitution is not 0.0 the object will need extra CPU for all new collisions.
     *             Try to set restitution to 0 for maximum performance (e.g. collapsing buildings)
     *         
     */
    float m_Restitution;
    /**
     * Maximal linear velocity.
     */
    float m_MaxLinearVelocity;
    /**
     * Maximal angular velocity. Pi x 10?
     */
    float m_MaxAngularVelocity;
    /**
     * 
     *             The maximum allowed penetration for this object.
     *             This is a hint to the engine to see how much CPU the engine should invest to keep this object from penetrating.
     *             A good choice is 5% - 20% of the smallest diameter of the object.
     *         
     */
    float m_PenetrationDepth;
    /**
     * Motion system? Overrides Quality when on Keyframed?
     */
    MotionSystem m_MotionSystem;
    /**
     * The initial deactivator type of the body.
     */
    DeactivatorType m_DeactivatorType;
    /**
     * Usually set to 1 for fixed objects, or set to 2 for moving ones.  Seems to always be same as Unknown Byte 1.
     */
    SolverDeactivation m_SolverDeactivation;
    /**
     * The motion type. Determines quality of motion?
     */
    MotionQuality m_QualityType;
    /**
     * Unknown.
     */
    uint m_UnknownInt6;
    /**
     * Unknown.
     */
    uint m_UnknownInt7;
    /**
     * Unknown.
     */
    uint m_UnknownInt8;
    /**
     * Unknown. Skyrim only.
     */
    uint m_UnknownInt81;
    /**
     *  The number of constraints this object is bound to.
     */
    uint m_NumConstraints;
    /**
     * Unknown.
     */
    std::vector<Pointer<class bhkSerializable*>> m_Constraints;
    /**
     * 0 = do not respond to wind, 1 = respond to wind (?)
     */
    uint m_UnknownInt9;
    ushort m_UnknownInt91;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const std::vector<int>& GetUnknown3Ints() const { return m_Unknown3Ints; }
    std::vector<int>& GetUnknown3Ints() { return m_Unknown3Ints; }
    void SetUnknown3Ints(const std::vector<int>& value) { m_Unknown3Ints = value; }

    const hkResponseType& GetCollisionResponse() const { return m_CollisionResponse; }
    hkResponseType& GetCollisionResponse() { return m_CollisionResponse; }
    void SetCollisionResponse(const hkResponseType& value) { m_CollisionResponse = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const ushort& GetProcessContactCallbackDelay() const { return m_ProcessContactCallbackDelay; }
    ushort& GetProcessContactCallbackDelay() { return m_ProcessContactCallbackDelay; }
    void SetProcessContactCallbackDelay(const ushort& value) { m_ProcessContactCallbackDelay = value; }

    const std::vector<ushort>& GetUnknown2Shorts() const { return m_Unknown2Shorts; }
    std::vector<ushort>& GetUnknown2Shorts() { return m_Unknown2Shorts; }
    void SetUnknown2Shorts(const std::vector<ushort>& value) { m_Unknown2Shorts = value; }

    const OblivionLayer& GetLayerCopy() const { return m_LayerCopy; }
    OblivionLayer& GetLayerCopy() { return m_LayerCopy; }
    void SetLayerCopy(const OblivionLayer& value) { m_LayerCopy = value; }

    const byte& GetColFilterCopy() const { return m_ColFilterCopy; }
    byte& GetColFilterCopy() { return m_ColFilterCopy; }
    void SetColFilterCopy(const byte& value) { m_ColFilterCopy = value; }

    const SkyrimLayer& GetSkyrimLayerCopy() const { return m_SkyrimLayerCopy; }
    SkyrimLayer& GetSkyrimLayerCopy() { return m_SkyrimLayerCopy; }
    void SetSkyrimLayerCopy(const SkyrimLayer& value) { m_SkyrimLayerCopy = value; }

    const byte& GetFlagsAndPartNumberCopy() const { return m_FlagsAndPartNumberCopy; }
    byte& GetFlagsAndPartNumberCopy() { return m_FlagsAndPartNumberCopy; }
    void SetFlagsAndPartNumberCopy(const byte& value) { m_FlagsAndPartNumberCopy = value; }

    const std::vector<ushort>& GetUnknown7Shorts() const { return m_Unknown7Shorts; }
    std::vector<ushort>& GetUnknown7Shorts() { return m_Unknown7Shorts; }
    void SetUnknown7Shorts(const std::vector<ushort>& value) { m_Unknown7Shorts = value; }

    const Vector4& GetTranslation() const { return m_Translation; }
    Vector4& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector4& value) { m_Translation = value; }

    const QuaternionXYZW& GetRotation() const { return m_Rotation; }
    QuaternionXYZW& GetRotation() { return m_Rotation; }
    void SetRotation(const QuaternionXYZW& value) { m_Rotation = value; }

    const Vector4& GetLinearVelocity() const { return m_LinearVelocity; }
    Vector4& GetLinearVelocity() { return m_LinearVelocity; }
    void SetLinearVelocity(const Vector4& value) { m_LinearVelocity = value; }

    const Vector4& GetAngularVelocity() const { return m_AngularVelocity; }
    Vector4& GetAngularVelocity() { return m_AngularVelocity; }
    void SetAngularVelocity(const Vector4& value) { m_AngularVelocity = value; }

    const InertiaMatrix& GetInertia() const { return m_Inertia; }
    InertiaMatrix& GetInertia() { return m_Inertia; }
    void SetInertia(const InertiaMatrix& value) { m_Inertia = value; }

    const Vector4& GetCenter() const { return m_Center; }
    Vector4& GetCenter() { return m_Center; }
    void SetCenter(const Vector4& value) { m_Center = value; }

    const float& GetMass() const { return m_Mass; }
    float& GetMass() { return m_Mass; }
    void SetMass(const float& value) { m_Mass = value; }

    const float& GetLinearDamping() const { return m_LinearDamping; }
    float& GetLinearDamping() { return m_LinearDamping; }
    void SetLinearDamping(const float& value) { m_LinearDamping = value; }

    const float& GetAngularDamping() const { return m_AngularDamping; }
    float& GetAngularDamping() { return m_AngularDamping; }
    void SetAngularDamping(const float& value) { m_AngularDamping = value; }

    const float& GetUnknownTimeFactorOrGravityFactor1() const { return m_UnknownTimeFactorOrGravityFactor1; }
    float& GetUnknownTimeFactorOrGravityFactor1() { return m_UnknownTimeFactorOrGravityFactor1; }
    void SetUnknownTimeFactorOrGravityFactor1(const float& value) { m_UnknownTimeFactorOrGravityFactor1 = value; }

    const float& GetUnknownTimeFactorOrGravityFactor2() const { return m_UnknownTimeFactorOrGravityFactor2; }
    float& GetUnknownTimeFactorOrGravityFactor2() { return m_UnknownTimeFactorOrGravityFactor2; }
    void SetUnknownTimeFactorOrGravityFactor2(const float& value) { m_UnknownTimeFactorOrGravityFactor2 = value; }

    const float& GetFriction() const { return m_Friction; }
    float& GetFriction() { return m_Friction; }
    void SetFriction(const float& value) { m_Friction = value; }

    const float& GetRollingFrictionMultiplier() const { return m_RollingFrictionMultiplier; }
    float& GetRollingFrictionMultiplier() { return m_RollingFrictionMultiplier; }
    void SetRollingFrictionMultiplier(const float& value) { m_RollingFrictionMultiplier = value; }

    const float& GetRestitution() const { return m_Restitution; }
    float& GetRestitution() { return m_Restitution; }
    void SetRestitution(const float& value) { m_Restitution = value; }

    const float& GetMaxLinearVelocity() const { return m_MaxLinearVelocity; }
    float& GetMaxLinearVelocity() { return m_MaxLinearVelocity; }
    void SetMaxLinearVelocity(const float& value) { m_MaxLinearVelocity = value; }

    const float& GetMaxAngularVelocity() const { return m_MaxAngularVelocity; }
    float& GetMaxAngularVelocity() { return m_MaxAngularVelocity; }
    void SetMaxAngularVelocity(const float& value) { m_MaxAngularVelocity = value; }

    const float& GetPenetrationDepth() const { return m_PenetrationDepth; }
    float& GetPenetrationDepth() { return m_PenetrationDepth; }
    void SetPenetrationDepth(const float& value) { m_PenetrationDepth = value; }

    const MotionSystem& GetMotionSystem() const { return m_MotionSystem; }
    MotionSystem& GetMotionSystem() { return m_MotionSystem; }
    void SetMotionSystem(const MotionSystem& value) { m_MotionSystem = value; }

    const DeactivatorType& GetDeactivatorType() const { return m_DeactivatorType; }
    DeactivatorType& GetDeactivatorType() { return m_DeactivatorType; }
    void SetDeactivatorType(const DeactivatorType& value) { m_DeactivatorType = value; }

    const SolverDeactivation& GetSolverDeactivation() const { return m_SolverDeactivation; }
    SolverDeactivation& GetSolverDeactivation() { return m_SolverDeactivation; }
    void SetSolverDeactivation(const SolverDeactivation& value) { m_SolverDeactivation = value; }

    const MotionQuality& GetQualityType() const { return m_QualityType; }
    MotionQuality& GetQualityType() { return m_QualityType; }
    void SetQualityType(const MotionQuality& value) { m_QualityType = value; }

    const uint& GetUnknownInt6() const { return m_UnknownInt6; }
    uint& GetUnknownInt6() { return m_UnknownInt6; }
    void SetUnknownInt6(const uint& value) { m_UnknownInt6 = value; }

    const uint& GetUnknownInt7() const { return m_UnknownInt7; }
    uint& GetUnknownInt7() { return m_UnknownInt7; }
    void SetUnknownInt7(const uint& value) { m_UnknownInt7 = value; }

    const uint& GetUnknownInt8() const { return m_UnknownInt8; }
    uint& GetUnknownInt8() { return m_UnknownInt8; }
    void SetUnknownInt8(const uint& value) { m_UnknownInt8 = value; }

    const uint& GetUnknownInt81() const { return m_UnknownInt81; }
    uint& GetUnknownInt81() { return m_UnknownInt81; }
    void SetUnknownInt81(const uint& value) { m_UnknownInt81 = value; }

    const uint& GetNumConstraints() const { return m_NumConstraints; }
    uint& GetNumConstraints() { return m_NumConstraints; }
    void SetNumConstraints(const uint& value) { m_NumConstraints = value; }

    const std::vector<Pointer<class bhkSerializable*>>& GetConstraints() const { return m_Constraints; }
    std::vector<Pointer<class bhkSerializable*>>& GetConstraints() { return m_Constraints; }
    void SetConstraints(const std::vector<Pointer<class bhkSerializable*>>& value) { m_Constraints = value; }

    const uint& GetUnknownInt9() const { return m_UnknownInt9; }
    uint& GetUnknownInt9() { return m_UnknownInt9; }
    void SetUnknownInt9(const uint& value) { m_UnknownInt9 = value; }

    const ushort& GetUnknownInt91() const { return m_UnknownInt91; }
    ushort& GetUnknownInt91() { return m_UnknownInt91; }
    void SetUnknownInt91(const ushort& value) { m_UnknownInt91 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
