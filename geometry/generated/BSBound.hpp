#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific collision bounding box for skeletons.
 *         
 */
class BSBound : public NiExtraData
{
protected:
    /**
     * Center of the bounding box.
     */
    Vector3 m_Center;
    /**
     * Dimensions of the bounding box from center.
     */
    Vector3 m_Dimensions;

public:
    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const Vector3& GetDimensions() const { return m_Dimensions; }
    Vector3& GetDimensions() { return m_Dimensions; }
    void SetDimensions(const Vector3& value) { m_Dimensions = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
