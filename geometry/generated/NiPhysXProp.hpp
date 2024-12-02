#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiPhysXTransformDest.hpp"
#include "NiPhysXPropDesc.hpp"
#include "NiObjectNET.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXProp : public NiObjectNET
{
protected:
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    uint m_UnknownInt1;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiObject*>> m_UnknownRefs1;
    /**
     * Number of NiPhysXTransformDest references
     */
    int m_NumDests;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiPhysXTransformDest*>> m_TransformDests;
    /**
     * Unknown
     */
    byte m_UnknownByte;
    /**
     * Unknown
     */
    int m_UnknownInt;
    /**
     * PhysX Property Description.
     */
    Pointer<class NiPhysXPropDesc*> m_PropDescription;

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const std::vector<Pointer<class NiObject*>>& GetUnknownRefs1() const { return m_UnknownRefs1; }
    std::vector<Pointer<class NiObject*>>& GetUnknownRefs1() { return m_UnknownRefs1; }
    void SetUnknownRefs1(const std::vector<Pointer<class NiObject*>>& value) { m_UnknownRefs1 = value; }

    const int& GetNumDests() const { return m_NumDests; }
    int& GetNumDests() { return m_NumDests; }
    void SetNumDests(const int& value) { m_NumDests = value; }

    const std::vector<Pointer<class NiPhysXTransformDest*>>& GetTransformDests() const { return m_TransformDests; }
    std::vector<Pointer<class NiPhysXTransformDest*>>& GetTransformDests() { return m_TransformDests; }
    void SetTransformDests(const std::vector<Pointer<class NiPhysXTransformDest*>>& value) { m_TransformDests = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const int& GetUnknownInt() const { return m_UnknownInt; }
    int& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const int& value) { m_UnknownInt = value; }

    const Pointer<class NiPhysXPropDesc*>& GetPropDescription() const { return m_PropDescription; }
    Pointer<class NiPhysXPropDesc*>& GetPropDescription() { return m_PropDescription; }
    void SetPropDescription(const Pointer<class NiPhysXPropDesc*>& value) { m_PropDescription = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
