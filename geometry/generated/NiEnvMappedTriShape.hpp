#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Matrix44.hpp"
#include "NiAVObject.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiObjectNET.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown
 *         
 */
class NiEnvMappedTriShape : public NiObjectNET
{
protected:
    /**
     * unknown (=4 - 5)
     */
    ushort m_Unknown1;
    /**
     * unknown
     */
    Matrix44 m_UnknownMatrix;
    /**
     * The number of child objects.
     */
    uint m_NumChildren;
    /**
     * List of child node object indices.
     */
    std::vector<Pointer<class NiAVObject*>> m_Children;
    /**
     * unknown
     */
    Pointer<class NiObject*> m_Child2;
    /**
     * unknown
     */
    Pointer<class NiObject*> m_Child3;

public:
    const ushort& GetUnknown1() const { return m_Unknown1; }
    ushort& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const ushort& value) { m_Unknown1 = value; }

    const Matrix44& GetUnknownMatrix() const { return m_UnknownMatrix; }
    Matrix44& GetUnknownMatrix() { return m_UnknownMatrix; }
    void SetUnknownMatrix(const Matrix44& value) { m_UnknownMatrix = value; }

    const uint& GetNumChildren() const { return m_NumChildren; }
    uint& GetNumChildren() { return m_NumChildren; }
    void SetNumChildren(const uint& value) { m_NumChildren = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetChildren() const { return m_Children; }
    std::vector<Pointer<class NiAVObject*>>& GetChildren() { return m_Children; }
    void SetChildren(const std::vector<Pointer<class NiAVObject*>>& value) { m_Children = value; }

    const Pointer<class NiObject*>& GetChild2() const { return m_Child2; }
    Pointer<class NiObject*>& GetChild2() { return m_Child2; }
    void SetChild2(const Pointer<class NiObject*>& value) { m_Child2 = value; }

    const Pointer<class NiObject*>& GetChild3() const { return m_Child3; }
    Pointer<class NiObject*>& GetChild3() { return m_Child3; }
    void SetChild3(const Pointer<class NiObject*>& value) { m_Child3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
