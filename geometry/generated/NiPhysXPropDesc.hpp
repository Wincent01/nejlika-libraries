#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPhysXActorDesc.hpp"
#include "NiPhysXD6JointDesc.hpp"
#include "physXMaterialRef.hpp"
#include "string.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXPropDesc : public NiObject
{
protected:
    /**
     * Number of NiPhysXActorDesc references
     */
    int m_NumDests;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiPhysXActorDesc*>> m_ActorDescs;
    /**
     * Unknown
     */
    uint m_NumJoints;
    /**
     * PhysX Joint Descriptions
     */
    std::vector<Pointer<class NiPhysXD6JointDesc*>> m_JointDescs;
    /**
     * Unknown
     */
    int m_UnknownInt1;
    /**
     * Unknown
     */
    uint m_NumMaterials;
    /**
     * PhysX Material Descriptions
     */
    std::vector<physXMaterialRef> m_MaterialDescs;
    /**
     * Unknown
     */
    uint m_UnknownInt2;
    /**
     * Unknown
     */
    uint m_UnknownInt3;
    /**
     * Unknown
     */
    string m_UnknownString4;
    /**
     * Unknown
     */
    uint m_UnknownInt5;
    /**
     * Unknown
     */
    byte m_UnknownByte6;

public:
    const int& GetNumDests() const { return m_NumDests; }
    int& GetNumDests() { return m_NumDests; }
    void SetNumDests(const int& value) { m_NumDests = value; }

    const std::vector<Pointer<class NiPhysXActorDesc*>>& GetActorDescs() const { return m_ActorDescs; }
    std::vector<Pointer<class NiPhysXActorDesc*>>& GetActorDescs() { return m_ActorDescs; }
    void SetActorDescs(const std::vector<Pointer<class NiPhysXActorDesc*>>& value) { m_ActorDescs = value; }

    const uint& GetNumJoints() const { return m_NumJoints; }
    uint& GetNumJoints() { return m_NumJoints; }
    void SetNumJoints(const uint& value) { m_NumJoints = value; }

    const std::vector<Pointer<class NiPhysXD6JointDesc*>>& GetJointDescs() const { return m_JointDescs; }
    std::vector<Pointer<class NiPhysXD6JointDesc*>>& GetJointDescs() { return m_JointDescs; }
    void SetJointDescs(const std::vector<Pointer<class NiPhysXD6JointDesc*>>& value) { m_JointDescs = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const uint& GetNumMaterials() const { return m_NumMaterials; }
    uint& GetNumMaterials() { return m_NumMaterials; }
    void SetNumMaterials(const uint& value) { m_NumMaterials = value; }

    const std::vector<physXMaterialRef>& GetMaterialDescs() const { return m_MaterialDescs; }
    std::vector<physXMaterialRef>& GetMaterialDescs() { return m_MaterialDescs; }
    void SetMaterialDescs(const std::vector<physXMaterialRef>& value) { m_MaterialDescs = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const string& GetUnknownString4() const { return m_UnknownString4; }
    string& GetUnknownString4() { return m_UnknownString4; }
    void SetUnknownString4(const string& value) { m_UnknownString4 = value; }

    const uint& GetUnknownInt5() const { return m_UnknownInt5; }
    uint& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const uint& value) { m_UnknownInt5 = value; }

    const byte& GetUnknownByte6() const { return m_UnknownByte6; }
    byte& GetUnknownByte6() { return m_UnknownByte6; }
    void SetUnknownByte6(const byte& value) { m_UnknownByte6 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
