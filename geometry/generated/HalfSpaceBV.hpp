#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


class HalfSpaceBV : public Construct
{
protected:
    /**
     * Normal
     */
    Vector3 m_Normal;
    /**
     * Center
     */
    Vector3 m_Center;
    /**
     * Unknown.
     */
    float m_UnknownFloat1;

public:
    const Vector3& GetNormal() const { return m_Normal; }
    Vector3& GetNormal() { return m_Normal; }
    void SetNormal(const Vector3& value) { m_Normal = value; }

    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
