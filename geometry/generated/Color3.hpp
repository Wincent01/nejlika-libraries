#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A color without alpha (red, green, blue).
 *         
 */
class Color3 : public Construct
{
protected:
    /**
     * Red color component.
     */
    float m_r;
    /**
     * Green color component.
     */
    float m_g;
    /**
     * Blue color component.
     */
    float m_b;

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


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
