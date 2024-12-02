#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSFacingQuadGenerator : public NiObject
{
protected:
    byte m_Unknown1;
    byte m_Unknown2;
    byte m_Unknown3;
    byte m_Unknown4;
    byte m_Unknown5;
    byte m_Unknown6;
    byte m_Unknown7;
    byte m_Unknown8;
    byte m_Unknown9;
    byte m_Unknown10;
    byte m_Unknown11;
    byte m_Unknown12;

public:
    const byte& GetUnknown1() const { return m_Unknown1; }
    byte& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const byte& value) { m_Unknown1 = value; }

    const byte& GetUnknown2() const { return m_Unknown2; }
    byte& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const byte& value) { m_Unknown2 = value; }

    const byte& GetUnknown3() const { return m_Unknown3; }
    byte& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const byte& value) { m_Unknown3 = value; }

    const byte& GetUnknown4() const { return m_Unknown4; }
    byte& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const byte& value) { m_Unknown4 = value; }

    const byte& GetUnknown5() const { return m_Unknown5; }
    byte& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const byte& value) { m_Unknown5 = value; }

    const byte& GetUnknown6() const { return m_Unknown6; }
    byte& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const byte& value) { m_Unknown6 = value; }

    const byte& GetUnknown7() const { return m_Unknown7; }
    byte& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const byte& value) { m_Unknown7 = value; }

    const byte& GetUnknown8() const { return m_Unknown8; }
    byte& GetUnknown8() { return m_Unknown8; }
    void SetUnknown8(const byte& value) { m_Unknown8 = value; }

    const byte& GetUnknown9() const { return m_Unknown9; }
    byte& GetUnknown9() { return m_Unknown9; }
    void SetUnknown9(const byte& value) { m_Unknown9 = value; }

    const byte& GetUnknown10() const { return m_Unknown10; }
    byte& GetUnknown10() { return m_Unknown10; }
    void SetUnknown10(const byte& value) { m_Unknown10 = value; }

    const byte& GetUnknown11() const { return m_Unknown11; }
    byte& GetUnknown11() { return m_Unknown11; }
    void SetUnknown11(const byte& value) { m_Unknown11 = value; }

    const byte& GetUnknown12() const { return m_Unknown12; }
    byte& GetUnknown12() { return m_Unknown12; }
    void SetUnknown12(const byte& value) { m_Unknown12 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
