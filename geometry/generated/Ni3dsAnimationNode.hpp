#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Only found in 2.3 nifs.
 *         
 */
class Ni3dsAnimationNode : public NiObject
{
protected:
    /**
     * Name of this object.
     */
    string m_Name;
    /**
     * Unknown.
     */
    bool m_HasData;
    /**
     * Unknown. Matrix?
     */
    std::vector<float> m_UnknownFloats1;
    /**
     * Unknown.
     */
    ushort m_UnknownShort;
    /**
     * Child?
     */
    Pointer<class NiObject*> m_Child;
    /**
     * Unknown.
     */
    std::vector<float> m_UnknownFloats2;
    /**
     * A count.
     */
    uint m_Count;
    /**
     * Unknown.
     */
    std::vector<std::vector<byte>> m_UnknownArray;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const bool& GetHasData() const { return m_HasData; }
    bool& GetHasData() { return m_HasData; }
    void SetHasData(const bool& value) { m_HasData = value; }

    const std::vector<float>& GetUnknownFloats1() const { return m_UnknownFloats1; }
    std::vector<float>& GetUnknownFloats1() { return m_UnknownFloats1; }
    void SetUnknownFloats1(const std::vector<float>& value) { m_UnknownFloats1 = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const Pointer<class NiObject*>& GetChild() const { return m_Child; }
    Pointer<class NiObject*>& GetChild() { return m_Child; }
    void SetChild(const Pointer<class NiObject*>& value) { m_Child = value; }

    const std::vector<float>& GetUnknownFloats2() const { return m_UnknownFloats2; }
    std::vector<float>& GetUnknownFloats2() { return m_UnknownFloats2; }
    void SetUnknownFloats2(const std::vector<float>& value) { m_UnknownFloats2 = value; }

    const uint& GetCount() const { return m_Count; }
    uint& GetCount() { return m_Count; }
    void SetCount(const uint& value) { m_Count = value; }

    const std::vector<std::vector<byte>>& GetUnknownArray() const { return m_UnknownArray; }
    std::vector<std::vector<byte>>& GetUnknownArray() { return m_UnknownArray; }
    void SetUnknownArray(const std::vector<std::vector<byte>>& value) { m_UnknownArray = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
