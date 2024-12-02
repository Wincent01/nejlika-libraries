#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A sphere.
 *         
 */
class SphereBV : public Construct
{
protected:
    /**
     * The sphere's center.
     */
    Vector3 m_Center;
    /**
     * The sphere's radius.
     */
    float m_Radius;

public:
    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
