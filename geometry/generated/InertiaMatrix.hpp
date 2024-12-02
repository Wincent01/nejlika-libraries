#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         An inertia matrix.
 *         
 */
class InertiaMatrix : public Construct
{
protected:
    float m_m11;
    float m_m12;
    float m_m13;
    /**
     * Zero
     */
    float m_m14;
    float m_m21;
    float m_m22;
    float m_m23;
    /**
     * Zero
     */
    float m_m24;
    float m_m31;
    float m_m32;
    float m_m33;
    /**
     * Zero
     */
    float m_m34;

public:
    const float& Getm11() const { return m_m11; }
    float& Getm11() { return m_m11; }
    void Setm11(const float& value) { m_m11 = value; }

    const float& Getm12() const { return m_m12; }
    float& Getm12() { return m_m12; }
    void Setm12(const float& value) { m_m12 = value; }

    const float& Getm13() const { return m_m13; }
    float& Getm13() { return m_m13; }
    void Setm13(const float& value) { m_m13 = value; }

    const float& Getm14() const { return m_m14; }
    float& Getm14() { return m_m14; }
    void Setm14(const float& value) { m_m14 = value; }

    const float& Getm21() const { return m_m21; }
    float& Getm21() { return m_m21; }
    void Setm21(const float& value) { m_m21 = value; }

    const float& Getm22() const { return m_m22; }
    float& Getm22() { return m_m22; }
    void Setm22(const float& value) { m_m22 = value; }

    const float& Getm23() const { return m_m23; }
    float& Getm23() { return m_m23; }
    void Setm23(const float& value) { m_m23 = value; }

    const float& Getm24() const { return m_m24; }
    float& Getm24() { return m_m24; }
    void Setm24(const float& value) { m_m24 = value; }

    const float& Getm31() const { return m_m31; }
    float& Getm31() { return m_m31; }
    void Setm31(const float& value) { m_m31 = value; }

    const float& Getm32() const { return m_m32; }
    float& Getm32() { return m_m32; }
    void Setm32(const float& value) { m_m32 = value; }

    const float& Getm33() const { return m_m33; }
    float& Getm33() { return m_m33; }
    void Setm33(const float& value) { m_m33 = value; }

    const float& Getm34() const { return m_m34; }
    float& Getm34() { return m_m34; }
    void Setm34(const float& value) { m_m34 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
