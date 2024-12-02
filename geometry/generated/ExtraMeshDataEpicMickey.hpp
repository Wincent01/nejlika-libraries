#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class ExtraMeshDataEpicMickey : public Construct
{
protected:
    int m_UnknownInt1;
    int m_UnknownInt2;
    int m_UnknownInt3;
    float m_UnknownInt4;
    float m_UnknownInt5;
    float m_UnknownInt6;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }

    const float& GetUnknownInt4() const { return m_UnknownInt4; }
    float& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const float& value) { m_UnknownInt4 = value; }

    const float& GetUnknownInt5() const { return m_UnknownInt5; }
    float& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const float& value) { m_UnknownInt5 = value; }

    const float& GetUnknownInt6() const { return m_UnknownInt6; }
    float& GetUnknownInt6() { return m_UnknownInt6; }
    void SetUnknownInt6(const float& value) { m_UnknownInt6 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
