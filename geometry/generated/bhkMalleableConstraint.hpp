#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiObject.hpp"
#include "HingeDescriptor.hpp"
#include "RagdollDescriptor.hpp"
#include "LimitedHingeDescriptor.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A malleable constraint.
 *         
 */
class bhkMalleableConstraint : public bhkConstraint
{
protected:
    /**
     * Type of constraint.
     */
    uint m_Type;
    /**
     * Unknown.
     */
    uint m_UnknownInt2;
    /**
     * Usually -1?
     */
    Pointer<class NiObject*> m_UnknownLink1;
    /**
     * Usually -1?
     */
    Pointer<class NiObject*> m_UnknownLink2;
    /**
     * Unknown. 1?
     */
    uint m_UnknownInt3;
    HingeDescriptor m_Hinge;
    RagdollDescriptor m_Ragdoll;
    LimitedHingeDescriptor m_LimitedHinge;
    float m_Tau;
    float m_Damping;

public:
    const uint& GetType() const { return m_Type; }
    uint& GetType() { return m_Type; }
    void SetType(const uint& value) { m_Type = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const Pointer<class NiObject*>& GetUnknownLink1() const { return m_UnknownLink1; }
    Pointer<class NiObject*>& GetUnknownLink1() { return m_UnknownLink1; }
    void SetUnknownLink1(const Pointer<class NiObject*>& value) { m_UnknownLink1 = value; }

    const Pointer<class NiObject*>& GetUnknownLink2() const { return m_UnknownLink2; }
    Pointer<class NiObject*>& GetUnknownLink2() { return m_UnknownLink2; }
    void SetUnknownLink2(const Pointer<class NiObject*>& value) { m_UnknownLink2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const HingeDescriptor& GetHinge() const { return m_Hinge; }
    HingeDescriptor& GetHinge() { return m_Hinge; }
    void SetHinge(const HingeDescriptor& value) { m_Hinge = value; }

    const RagdollDescriptor& GetRagdoll() const { return m_Ragdoll; }
    RagdollDescriptor& GetRagdoll() { return m_Ragdoll; }
    void SetRagdoll(const RagdollDescriptor& value) { m_Ragdoll = value; }

    const LimitedHingeDescriptor& GetLimitedHinge() const { return m_LimitedHinge; }
    LimitedHingeDescriptor& GetLimitedHinge() { return m_LimitedHinge; }
    void SetLimitedHinge(const LimitedHingeDescriptor& value) { m_LimitedHinge = value; }

    const float& GetTau() const { return m_Tau; }
    float& GetTau() { return m_Tau; }
    void SetTau(const float& value) { m_Tau = value; }

    const float& GetDamping() const { return m_Damping; }
    float& GetDamping() { return m_Damping; }
    void SetDamping(const float& value) { m_Damping = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
