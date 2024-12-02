#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A 3x3 rotation matrix; M^T M=identity, det(M)=1.    Stored in OpenGL column-major format.
 *         
 */
class Matrix33 : public Construct
{
protected:
    /**
     * Member 1,1 (top left)
     */
    float m_m11;
    /**
     * Member 2,1
     */
    float m_m21;
    /**
     * Member 3,1 (bottom left)
     */
    float m_m31;
    /**
     * Member 1,2
     */
    float m_m12;
    /**
     * Member 2,2
     */
    float m_m22;
    /**
     * Member 3,2
     */
    float m_m32;
    /**
     * Member 1,3 (top right)
     */
    float m_m13;
    /**
     * Member 2,3
     */
    float m_m23;
    /**
     * Member 3,3 (bottom left)
     */
    float m_m33;

public:
    const float& Getm11() const { return m_m11; }
    float& Getm11() { return m_m11; }
    void Setm11(const float& value) { m_m11 = value; }

    const float& Getm21() const { return m_m21; }
    float& Getm21() { return m_m21; }
    void Setm21(const float& value) { m_m21 = value; }

    const float& Getm31() const { return m_m31; }
    float& Getm31() { return m_m31; }
    void Setm31(const float& value) { m_m31 = value; }

    const float& Getm12() const { return m_m12; }
    float& Getm12() { return m_m12; }
    void Setm12(const float& value) { m_m12 = value; }

    const float& Getm22() const { return m_m22; }
    float& Getm22() { return m_m22; }
    void Setm22(const float& value) { m_m22 = value; }

    const float& Getm32() const { return m_m32; }
    float& Getm32() { return m_m32; }
    void Setm32(const float& value) { m_m32 = value; }

    const float& Getm13() const { return m_m13; }
    float& Getm13() { return m_m13; }
    void Setm13(const float& value) { m_m13 = value; }

    const float& Getm23() const { return m_m23; }
    float& Getm23() { return m_m23; }
    void Setm23(const float& value) { m_m23 = value; }

    const float& Getm33() const { return m_m33; }
    float& Getm33() { return m_m33; }
    void Setm33(const float& value) { m_m33 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
