#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class Ni3dsAlphaAnimator : public NiObject
{
protected:
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown1;
    /**
     * The parent?
     */
    Pointer<class NiObject*> m_Parent;
    /**
     * Unknown.
     */
    uint m_Num1;
    /**
     * Unknown.
     */
    uint m_Num2;
    /**
     * Unknown.
     */
    std::vector<std::vector<std::vector<uint>>> m_Unknown2;

public:
    const std::vector<byte>& GetUnknown1() const { return m_Unknown1; }
    std::vector<byte>& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const std::vector<byte>& value) { m_Unknown1 = value; }

    const Pointer<class NiObject*>& GetParent() const { return m_Parent; }
    Pointer<class NiObject*>& GetParent() { return m_Parent; }
    void SetParent(const Pointer<class NiObject*>& value) { m_Parent = value; }

    const uint& GetNum1() const { return m_Num1; }
    uint& GetNum1() { return m_Num1; }
    void SetNum1(const uint& value) { m_Num1 = value; }

    const uint& GetNum2() const { return m_Num2; }
    uint& GetNum2() { return m_Num2; }
    void SetNum2(const uint& value) { m_Num2 = value; }

    const std::vector<std::vector<std::vector<uint>>>& GetUnknown2() const { return m_Unknown2; }
    std::vector<std::vector<std::vector<uint>>>& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const std::vector<std::vector<std::vector<uint>>>& value) { m_Unknown2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
