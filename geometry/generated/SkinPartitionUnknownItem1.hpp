#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class SkinPartitionUnknownItem1 : public Construct
{
protected:
    uint m_UnknownFlags;
    float m_f1;
    float m_f2;
    float m_f3;
    float m_f4;
    float m_f5;

public:
    const uint& GetUnknownFlags() const { return m_UnknownFlags; }
    uint& GetUnknownFlags() { return m_UnknownFlags; }
    void SetUnknownFlags(const uint& value) { m_UnknownFlags = value; }

    const float& Getf1() const { return m_f1; }
    float& Getf1() { return m_f1; }
    void Setf1(const float& value) { m_f1 = value; }

    const float& Getf2() const { return m_f2; }
    float& Getf2() { return m_f2; }
    void Setf2(const float& value) { m_f2 = value; }

    const float& Getf3() const { return m_f3; }
    float& Getf3() { return m_f3; }
    void Setf3(const float& value) { m_f3 = value; }

    const float& Getf4() const { return m_f4; }
    float& Getf4() { return m_f4; }
    void Setf4(const float& value) { m_f4 = value; }

    const float& Getf5() const { return m_f5; }
    float& Getf5() { return m_f5; }
    void Setf5(const float& value) { m_f5 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
