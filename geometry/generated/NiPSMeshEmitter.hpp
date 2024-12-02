#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSMeshEmitter : public NiObject
{
protected:
    string m_Name;
    int m_Unknown1;
    int m_Unknown2;
    int m_Unknown3;
    int m_Unknown27;
    float m_Unknown4;
    float m_Unknown5;
    float m_Unknown6;
    float m_Unknown28;
    int m_Unknown7;
    float m_Unknown8;
    float m_Unknown9;
    float m_Unknown10;
    float m_Unknown11;
    float m_Unknown12;
    int m_Unknown13;
    float m_Unknown14;
    float m_Unknown15;
    float m_Unknown16;
    int m_Unknown17;
    int m_Unknown18;
    short m_Unknown19;
    int m_Unknown20;
    int m_Unknown21;
    float m_Unknown22;
    int m_Unknown23;
    int m_Unknown24;
    int m_Unknown25;
    int m_Unknown26;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const int& GetUnknown1() const { return m_Unknown1; }
    int& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const int& value) { m_Unknown1 = value; }

    const int& GetUnknown2() const { return m_Unknown2; }
    int& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const int& value) { m_Unknown2 = value; }

    const int& GetUnknown3() const { return m_Unknown3; }
    int& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const int& value) { m_Unknown3 = value; }

    const int& GetUnknown27() const { return m_Unknown27; }
    int& GetUnknown27() { return m_Unknown27; }
    void SetUnknown27(const int& value) { m_Unknown27 = value; }

    const float& GetUnknown4() const { return m_Unknown4; }
    float& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const float& value) { m_Unknown4 = value; }

    const float& GetUnknown5() const { return m_Unknown5; }
    float& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const float& value) { m_Unknown5 = value; }

    const float& GetUnknown6() const { return m_Unknown6; }
    float& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const float& value) { m_Unknown6 = value; }

    const float& GetUnknown28() const { return m_Unknown28; }
    float& GetUnknown28() { return m_Unknown28; }
    void SetUnknown28(const float& value) { m_Unknown28 = value; }

    const int& GetUnknown7() const { return m_Unknown7; }
    int& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const int& value) { m_Unknown7 = value; }

    const float& GetUnknown8() const { return m_Unknown8; }
    float& GetUnknown8() { return m_Unknown8; }
    void SetUnknown8(const float& value) { m_Unknown8 = value; }

    const float& GetUnknown9() const { return m_Unknown9; }
    float& GetUnknown9() { return m_Unknown9; }
    void SetUnknown9(const float& value) { m_Unknown9 = value; }

    const float& GetUnknown10() const { return m_Unknown10; }
    float& GetUnknown10() { return m_Unknown10; }
    void SetUnknown10(const float& value) { m_Unknown10 = value; }

    const float& GetUnknown11() const { return m_Unknown11; }
    float& GetUnknown11() { return m_Unknown11; }
    void SetUnknown11(const float& value) { m_Unknown11 = value; }

    const float& GetUnknown12() const { return m_Unknown12; }
    float& GetUnknown12() { return m_Unknown12; }
    void SetUnknown12(const float& value) { m_Unknown12 = value; }

    const int& GetUnknown13() const { return m_Unknown13; }
    int& GetUnknown13() { return m_Unknown13; }
    void SetUnknown13(const int& value) { m_Unknown13 = value; }

    const float& GetUnknown14() const { return m_Unknown14; }
    float& GetUnknown14() { return m_Unknown14; }
    void SetUnknown14(const float& value) { m_Unknown14 = value; }

    const float& GetUnknown15() const { return m_Unknown15; }
    float& GetUnknown15() { return m_Unknown15; }
    void SetUnknown15(const float& value) { m_Unknown15 = value; }

    const float& GetUnknown16() const { return m_Unknown16; }
    float& GetUnknown16() { return m_Unknown16; }
    void SetUnknown16(const float& value) { m_Unknown16 = value; }

    const int& GetUnknown17() const { return m_Unknown17; }
    int& GetUnknown17() { return m_Unknown17; }
    void SetUnknown17(const int& value) { m_Unknown17 = value; }

    const int& GetUnknown18() const { return m_Unknown18; }
    int& GetUnknown18() { return m_Unknown18; }
    void SetUnknown18(const int& value) { m_Unknown18 = value; }

    const short& GetUnknown19() const { return m_Unknown19; }
    short& GetUnknown19() { return m_Unknown19; }
    void SetUnknown19(const short& value) { m_Unknown19 = value; }

    const int& GetUnknown20() const { return m_Unknown20; }
    int& GetUnknown20() { return m_Unknown20; }
    void SetUnknown20(const int& value) { m_Unknown20 = value; }

    const int& GetUnknown21() const { return m_Unknown21; }
    int& GetUnknown21() { return m_Unknown21; }
    void SetUnknown21(const int& value) { m_Unknown21 = value; }

    const float& GetUnknown22() const { return m_Unknown22; }
    float& GetUnknown22() { return m_Unknown22; }
    void SetUnknown22(const float& value) { m_Unknown22 = value; }

    const int& GetUnknown23() const { return m_Unknown23; }
    int& GetUnknown23() { return m_Unknown23; }
    void SetUnknown23(const int& value) { m_Unknown23 = value; }

    const int& GetUnknown24() const { return m_Unknown24; }
    int& GetUnknown24() { return m_Unknown24; }
    void SetUnknown24(const int& value) { m_Unknown24 = value; }

    const int& GetUnknown25() const { return m_Unknown25; }
    int& GetUnknown25() { return m_Unknown25; }
    void SetUnknown25(const int& value) { m_Unknown25 = value; }

    const int& GetUnknown26() const { return m_Unknown26; }
    int& GetUnknown26() { return m_Unknown26; }
    void SetUnknown26(const int& value) { m_Unknown26 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
