#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A 2x2 matrix of float values.  Stored in OpenGL column-major format.
 *         
 */
class Matrix22 : public Construct
{
protected:
    /**
     * Member 1,1 (top left)
     */
    float m_m11;
    /**
     * Member 2,1 (bottom left)
     */
    float m_m21;
    /**
     * Member 1,2 (top right)
     */
    float m_m12;
    /**
     * Member 2,2 (bottom right)
     */
    float m_m22;

public:
    const float& Getm11() const { return m_m11; }
    float& Getm11() { return m_m11; }
    void Setm11(const float& value) { m_m11 = value; }

    const float& Getm21() const { return m_m21; }
    float& Getm21() { return m_m21; }
    void Setm21(const float& value) { m_m21 = value; }

    const float& Getm12() const { return m_m12; }
    float& Getm12() { return m_m12; }
    void Setm12(const float& value) { m_m12 = value; }

    const float& Getm22() const { return m_m22; }
    float& Getm22() { return m_m22; }
    void Setm22(const float& value) { m_m22 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
