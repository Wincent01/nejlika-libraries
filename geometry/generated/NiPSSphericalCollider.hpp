#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSSphericalCollider : public NiObject
{
protected:
    int m_Unknown1;
    int m_Unknown2;
    byte m_Unknown3;
    float m_Unknown4;
    int m_Unknown5;
    short m_Unknown6;
    int m_Unknown7;

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

    const int& GetUnknown5() const { return m_Unknown5; }
    int& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const int& value) { m_Unknown5 = value; }

    const short& GetUnknown6() const { return m_Unknown6; }
    short& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const short& value) { m_Unknown6 = value; }

    const int& GetUnknown7() const { return m_Unknown7; }
    int& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const int& value) { m_Unknown7 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
