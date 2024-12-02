#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkEntity.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node.
 *         
 */
class bhkBreakableConstraint : public bhkConstraint
{
protected:
    std::vector<int> m_UnknownInts1;
    /**
     * Unknown
     */
    short m_UnknownShort1;
    /**
     * A count or flag?
     */
    uint m_UnknownInt1;
    /**
     * Number of bodies affected by this constraint.
     */
    uint m_NumEntities2;
    /**
     * The entities affected by this constraint.
     */
    std::vector<Pointer<class bhkEntity*>> m_Entities2;
    /**
     * Usually 1. Higher values indicate higher priority of this constraint?
     */
    uint m_Priority2;
    /**
     * Unknown
     */
    uint m_UnknownInt2;
    /**
     * Unknown
     */
    Vector3 m_Position;
    /**
     * Unknown
     */
    Vector3 m_Rotation;
    /**
     * Unknown
     */
    uint m_UnknownInt3;
    /**
     * Unknown
     */
    float m_Threshold;
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    byte m_RemoveIfBroken;

public:
    const std::vector<int>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<int>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<int>& value) { m_UnknownInts1 = value; }

    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetNumEntities2() const { return m_NumEntities2; }
    uint& GetNumEntities2() { return m_NumEntities2; }
    void SetNumEntities2(const uint& value) { m_NumEntities2 = value; }

    const std::vector<Pointer<class bhkEntity*>>& GetEntities2() const { return m_Entities2; }
    std::vector<Pointer<class bhkEntity*>>& GetEntities2() { return m_Entities2; }
    void SetEntities2(const std::vector<Pointer<class bhkEntity*>>& value) { m_Entities2 = value; }

    const uint& GetPriority2() const { return m_Priority2; }
    uint& GetPriority2() { return m_Priority2; }
    void SetPriority2(const uint& value) { m_Priority2 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const Vector3& GetPosition() const { return m_Position; }
    Vector3& GetPosition() { return m_Position; }
    void SetPosition(const Vector3& value) { m_Position = value; }

    const Vector3& GetRotation() const { return m_Rotation; }
    Vector3& GetRotation() { return m_Rotation; }
    void SetRotation(const Vector3& value) { m_Rotation = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const float& GetThreshold() const { return m_Threshold; }
    float& GetThreshold() { return m_Threshold; }
    void SetThreshold(const float& value) { m_Threshold = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const byte& GetRemoveIfBroken() const { return m_RemoveIfBroken; }
    byte& GetRemoveIfBroken() { return m_RemoveIfBroken; }
    void SetRemoveIfBroken(const byte& value) { m_RemoveIfBroken = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
