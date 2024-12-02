#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiPSysCollider.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle Collider object which particles will interact with.
 *         
 */
class NiPSysPlanarCollider : public NiPSysCollider
{
protected:
    /**
     * Defines the width of the plane.
     */
    float m_Width;
    /**
     * Defines the height of the plane.
     */
    float m_Height;
    /**
     * Defines Orientation.
     */
    Vector3 m_XAxis;
    /**
     * Defines Orientation.
     */
    Vector3 m_YAxis;

public:
    const float& GetWidth() const { return m_Width; }
    float& GetWidth() { return m_Width; }
    void SetWidth(const float& value) { m_Width = value; }

    const float& GetHeight() const { return m_Height; }
    float& GetHeight() { return m_Height; }
    void SetHeight(const float& value) { m_Height = value; }

    const Vector3& GetXAxis() const { return m_XAxis; }
    Vector3& GetXAxis() { return m_XAxis; }
    void SetXAxis(const Vector3& value) { m_XAxis = value; }

    const Vector3& GetYAxis() const { return m_YAxis; }
    Vector3& GetYAxis() { return m_YAxis; }
    void SetYAxis(const Vector3& value) { m_YAxis = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
