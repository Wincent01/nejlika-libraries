#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiPSysFieldModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system modifier, used for controlling the particle velocity in a field like wind.
 *         
 */
class NiPSysAirFieldModifier : public NiPSysFieldModifier
{
protected:
    /**
     * Direction of the particle velocity
     */
    Vector3 m_Direction;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Unknown
     */
    float m_UnknownFloat3;
    /**
     * Unknown
     */
    bool m_UnknownBoolean1;
    /**
     * Unknown
     */
    bool m_UnknownBoolean2;
    /**
     * Unknown
     */
    bool m_UnknownBoolean3;
    /**
     * Unknown
     */
    float m_UnknownFloat4;

public:
    const Vector3& GetDirection() const { return m_Direction; }
    Vector3& GetDirection() { return m_Direction; }
    void SetDirection(const Vector3& value) { m_Direction = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const bool& GetUnknownBoolean1() const { return m_UnknownBoolean1; }
    bool& GetUnknownBoolean1() { return m_UnknownBoolean1; }
    void SetUnknownBoolean1(const bool& value) { m_UnknownBoolean1 = value; }

    const bool& GetUnknownBoolean2() const { return m_UnknownBoolean2; }
    bool& GetUnknownBoolean2() { return m_UnknownBoolean2; }
    void SetUnknownBoolean2(const bool& value) { m_UnknownBoolean2 = value; }

    const bool& GetUnknownBoolean3() const { return m_UnknownBoolean3; }
    bool& GetUnknownBoolean3() { return m_UnknownBoolean3; }
    void SetUnknownBoolean3(const bool& value) { m_UnknownBoolean3 = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
