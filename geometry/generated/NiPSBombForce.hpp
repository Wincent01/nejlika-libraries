#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSBombForce : public NiObject
{
protected:
    string m_Name;
    byte m_Unknown1;
    int m_Unknown2;
    int m_Unknown3;
    int m_Unknown4;
    int m_Unknown5;
    int m_Unknown6;
    int m_Unknown7;
    int m_Unknown8;
    int m_Unknown9;
    int m_Unknown10;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const byte& GetUnknown1() const { return m_Unknown1; }
    byte& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const byte& value) { m_Unknown1 = value; }

    const int& GetUnknown2() const { return m_Unknown2; }
    int& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const int& value) { m_Unknown2 = value; }

    const int& GetUnknown3() const { return m_Unknown3; }
    int& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const int& value) { m_Unknown3 = value; }

    const int& GetUnknown4() const { return m_Unknown4; }
    int& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const int& value) { m_Unknown4 = value; }

    const int& GetUnknown5() const { return m_Unknown5; }
    int& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const int& value) { m_Unknown5 = value; }

    const int& GetUnknown6() const { return m_Unknown6; }
    int& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const int& value) { m_Unknown6 = value; }

    const int& GetUnknown7() const { return m_Unknown7; }
    int& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const int& value) { m_Unknown7 = value; }

    const int& GetUnknown8() const { return m_Unknown8; }
    int& GetUnknown8() { return m_Unknown8; }
    void SetUnknown8(const int& value) { m_Unknown8 = value; }

    const int& GetUnknown9() const { return m_Unknown9; }
    int& GetUnknown9() { return m_Unknown9; }
    void SetUnknown9(const int& value) { m_Unknown9 = value; }

    const int& GetUnknown10() const { return m_Unknown10; }
    int& GetUnknown10() { return m_Unknown10; }
    void SetUnknown10(const int& value) { m_Unknown10 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
