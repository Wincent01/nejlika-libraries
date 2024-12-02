#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Capsule Bounding Volume
 *         
 */
class CapsuleBV : public Construct
{
protected:
    /**
     * Center
     */
    Vector3 m_Center;
    /**
     * Origin
     */
    Vector3 m_Origin;
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    float m_UnknownFloat2;

public:
    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const Vector3& GetOrigin() const { return m_Origin; }
    Vector3& GetOrigin() { return m_Origin; }
    void SetOrigin(const Vector3& value) { m_Origin = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
