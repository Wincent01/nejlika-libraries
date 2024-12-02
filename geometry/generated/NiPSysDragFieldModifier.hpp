#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiPSysFieldModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system modifier, used for controlling the particle velocity in drag space warp.
 *         
 */
class NiPSysDragFieldModifier : public NiPSysFieldModifier
{
protected:
    /**
     * Whether to use the direction field?
     */
    bool m_UseDirection;
    /**
     * Direction of the particle velocity
     */
    Vector3 m_Direction;

public:
    const bool& GetUseDirection() const { return m_UseDirection; }
    bool& GetUseDirection() { return m_UseDirection; }
    void SetUseDirection(const bool& value) { m_UseDirection = value; }

    const Vector3& GetDirection() const { return m_Direction; }
    Vector3& GetDirection() { return m_Direction; }
    void SetDirection(const Vector3& value) { m_Direction = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
