#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSDragForce : public NiObject
{
protected:
    int m_Unknown1;
    int m_Unknown2;
    byte m_Unknown3;
    float m_Unknown4;
    float m_Unknown5;
    float m_Unknown6;
    float m_Unknown7;
    float m_Unknown8;
    float m_Unknown9;
    int m_Unknown10;

public:
    const int& GetUnknown1() const { return m_Unknown1; }
    int& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const int& value) { m_Unknown1 = value; }

    const int& GetUnknown2() const { return m_Unknown2; }
    int& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const int& value) { m_Unknown2 = value; }

    const byte& GetUnknown3() const { return m_Unknown3; }
    byte& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const byte& value) { m_Unknown3 = value; }

    const float& GetUnknown4() const { return m_Unknown4; }
    float& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const float& value) { m_Unknown4 = value; }

    const float& GetUnknown5() const { return m_Unknown5; }
    float& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const float& value) { m_Unknown5 = value; }

    const float& GetUnknown6() const { return m_Unknown6; }
    float& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const float& value) { m_Unknown6 = value; }

    const float& GetUnknown7() const { return m_Unknown7; }
    float& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const float& value) { m_Unknown7 = value; }

    const float& GetUnknown8() const { return m_Unknown8; }
    float& GetUnknown8() { return m_Unknown8; }
    void SetUnknown8(const float& value) { m_Unknown8 = value; }

    const float& GetUnknown9() const { return m_Unknown9; }
    float& GetUnknown9() { return m_Unknown9; }
    void SetUnknown9(const float& value) { m_Unknown9 = value; }

    const int& GetUnknown10() const { return m_Unknown10; }
    int& GetUnknown10() { return m_Unknown10; }
    void SetUnknown10(const int& value) { m_Unknown10 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
