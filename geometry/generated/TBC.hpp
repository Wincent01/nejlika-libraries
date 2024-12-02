#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Tension, bias, continuity.
 *         
 */
class TBC : public Construct
{
protected:
    /**
     * Tension.
     */
    float m_t;
    /**
     * Bias.
     */
    float m_b;
    /**
     * Continuity.
     */
    float m_c;

public:
    const float& Gett() const { return m_t; }
    float& Gett() { return m_t; }
    void Sett(const float& value) { m_t = value; }

    const float& Getb() const { return m_b; }
    float& Getb() { return m_b; }
    void Setb(const float& value) { m_b = value; }

    const float& Getc() const { return m_c; }
    float& Getc() { return m_c; }
    void Setc(const float& value) { m_c = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
