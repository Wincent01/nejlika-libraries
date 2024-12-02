#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A quaternion as it appears in the havok objects.
 *         
 */
class QuaternionXYZW : public Construct
{
protected:
    /**
     * The x-coordinate.
     */
    float m_x;
    /**
     * The y-coordinate.
     */
    float m_y;
    /**
     * The z-coordinate.
     */
    float m_z;
    /**
     * The w-coordinate.
     */
    float m_w;

public:
    const float& Getx() const { return m_x; }
    float& Getx() { return m_x; }
    void Setx(const float& value) { m_x = value; }

    const float& Gety() const { return m_y; }
    float& Gety() { return m_y; }
    void Sety(const float& value) { m_y = value; }

    const float& Getz() const { return m_z; }
    float& Getz() { return m_z; }
    void Setz(const float& value) { m_z = value; }

    const float& Getw() const { return m_w; }
    float& Getw() { return m_w; }
    void Setw(const float& value) { m_w = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
