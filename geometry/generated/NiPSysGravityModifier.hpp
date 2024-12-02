#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "Vector3.hpp"
#include "ForceType.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Adds gravity to a particle system, when linked to a NiNode to use as a Gravity Object.
 *         
 */
class NiPSysGravityModifier : public NiPSysModifier
{
protected:
    /**
     * Refers to a NiNode for gravity location.
     */
    Pointer<class NiNode*> m_GravityObject;
    /**
     * Orientation of gravity.
     */
    Vector3 m_GravityAxis;
    /**
     * Falloff range.
     */
    float m_Decay;
    /**
     * The strength of gravity.
     */
    float m_Strength;
    /**
     * Planar or Spherical type
     */
    ForceType m_ForceType;
    /**
     * Adds a degree of randomness.
     */
    float m_Turbulence;
    /**
     * Range for turbulence.
     */
    float m_TurbulenceScale;
    /**
     * Unknown
     */
    byte m_UnknownByte;

public:
    const Pointer<class NiNode*>& GetGravityObject() const { return m_GravityObject; }
    Pointer<class NiNode*>& GetGravityObject() { return m_GravityObject; }
    void SetGravityObject(const Pointer<class NiNode*>& value) { m_GravityObject = value; }

    const Vector3& GetGravityAxis() const { return m_GravityAxis; }
    Vector3& GetGravityAxis() { return m_GravityAxis; }
    void SetGravityAxis(const Vector3& value) { m_GravityAxis = value; }

    const float& GetDecay() const { return m_Decay; }
    float& GetDecay() { return m_Decay; }
    void SetDecay(const float& value) { m_Decay = value; }

    const float& GetStrength() const { return m_Strength; }
    float& GetStrength() { return m_Strength; }
    void SetStrength(const float& value) { m_Strength = value; }

    const ForceType& GetForceType() const { return m_ForceType; }
    ForceType& GetForceType() { return m_ForceType; }
    void SetForceType(const ForceType& value) { m_ForceType = value; }

    const float& GetTurbulence() const { return m_Turbulence; }
    float& GetTurbulence() { return m_Turbulence; }
    void SetTurbulence(const float& value) { m_Turbulence = value; }

    const float& GetTurbulenceScale() const { return m_TurbulenceScale; }
    float& GetTurbulenceScale() { return m_TurbulenceScale; }
    void SetTurbulenceScale(const float& value) { m_TurbulenceScale = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
