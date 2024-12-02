#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Texture coordinates (u,v). As in OpenGL; image origin is in the lower left corner.
 *         
 */
class TexCoord : public Construct
{
protected:
    /**
     * First coordinate.
     */
    float m_u;
    /**
     * Second coordinate.
     */
    float m_v;

public:
    TexCoord() : m_u(0.0f), m_v(0.0f) { }
    TexCoord(const float& u, const float& v) : m_u(u), m_v(v) { }

    const float& Getu() const { return m_u; }
    float& Getu() { return m_u; }
    void Setu(const float& value) { m_u = value; }

    const float& Getv() const { return m_v; }
    float& Getv() { return m_v; }
    void Setv(const float& value) { m_v = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
