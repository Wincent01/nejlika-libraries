#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "bhkSerializable.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A Ball and Socket Constraint chain.
 *         
 */
class bhkBallSocketConstraintChain : public bhkSerializable
{
protected:
    /**
     * Unknown
     */
    uint m_NumFloats;
    /**
     * Unknown
     */
    std::vector<Vector4> m_Floats1;
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Unknown
     */
    uint m_UnknownInt1;
    /**
     * Unknown
     */
    uint m_UnknownInt2;
    /**
     * Number of links in the chain
     */
    uint m_NumLinks;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiObject*>> m_Links;
    /**
     * Number of links in the chain
     */
    uint m_NumLinks2;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiObject*>> m_Links2;
    /**
     * Unknown
     */
    uint m_UnknownInt3;

public:
    const uint& GetNumFloats() const { return m_NumFloats; }
    uint& GetNumFloats() { return m_NumFloats; }
    void SetNumFloats(const uint& value) { m_NumFloats = value; }

    const std::vector<Vector4>& GetFloats1() const { return m_Floats1; }
    std::vector<Vector4>& GetFloats1() { return m_Floats1; }
    void SetFloats1(const std::vector<Vector4>& value) { m_Floats1 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const uint& GetNumLinks() const { return m_NumLinks; }
    uint& GetNumLinks() { return m_NumLinks; }
    void SetNumLinks(const uint& value) { m_NumLinks = value; }

    const std::vector<Pointer<class NiObject*>>& GetLinks() const { return m_Links; }
    std::vector<Pointer<class NiObject*>>& GetLinks() { return m_Links; }
    void SetLinks(const std::vector<Pointer<class NiObject*>>& value) { m_Links = value; }

    const uint& GetNumLinks2() const { return m_NumLinks2; }
    uint& GetNumLinks2() { return m_NumLinks2; }
    void SetNumLinks2(const uint& value) { m_NumLinks2 = value; }

    const std::vector<Pointer<class NiObject*>>& GetLinks2() const { return m_Links2; }
    std::vector<Pointer<class NiObject*>>& GetLinks2() { return m_Links2; }
    void SetLinks2(const std::vector<Pointer<class NiObject*>>& value) { m_Links2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
