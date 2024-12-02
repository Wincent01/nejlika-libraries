#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Box Bounding Volume
 *         
 */
class BoxBV : public Construct
{
protected:
    /**
     * Center
     */
    Vector3 m_Center;
    /**
     * Axis
     */
    std::vector<Vector3> m_Axis;
    /**
     * Extent
     */
    std::vector<float> m_Extent;

public:
    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const std::vector<Vector3>& GetAxis() const { return m_Axis; }
    std::vector<Vector3>& GetAxis() { return m_Axis; }
    void SetAxis(const std::vector<Vector3>& value) { m_Axis = value; }

    const std::vector<float>& GetExtent() const { return m_Extent; }
    std::vector<float>& GetExtent() { return m_Extent; }
    void SetExtent(const std::vector<float>& value) { m_Extent = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
