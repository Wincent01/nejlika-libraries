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
class ByteColor4 : public Construct
{
protected:
    /**
     * Red color component.
     */
    byte m_r;
    /**
     * Green color component.
     */
    byte m_g;
    /**
     * Blue color component.
     */
    byte m_b;
    /**
     * Alpha color component.
     */
    byte m_a;

public:
    const byte& Getr() const { return m_r; }
    byte& Getr() { return m_r; }
    void Setr(const byte& value) { m_r = value; }

    const byte& Getg() const { return m_g; }
    byte& Getg() { return m_g; }
    void Setg(const byte& value) { m_g = value; }

    const byte& Getb() const { return m_b; }
    byte& Getb() { return m_b; }
    void Setb(const byte& value) { m_b = value; }

    const byte& Geta() const { return m_a; }
    byte& Geta() { return m_a; }
    void Seta(const byte& value) { m_a = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}