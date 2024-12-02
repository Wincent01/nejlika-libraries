#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A color with alpha (red, green, blue, alpha).
 *         
 */
class Color4 : public Construct
{
protected:
    /**
     * Red component.
     */
    float m_r;
    /**
     * Green component.
     */
    float m_g;
    /**
     * Blue component.
     */
    float m_b;
    /**
     * Alpha.
     */
    float m_a;

public:
    const float& Getr() const { return m_r; }
    float& Getr() { return m_r; }
    void Setr(const float& value) { m_r = value; }

    const float& Getg() const { return m_g; }
    float& Getg() { return m_g; }
    void Setg(const float& value) { m_g = value; }

    const float& Getb() const { return m_b; }
    float& Getb() { return m_b; }
    void Setb(const float& value) { m_b = value; }

    const float& Geta() const { return m_a; }
    float& Geta() { return m_a; }
    void Seta(const float& value) { m_a = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
