#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiBlendInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Interpolates a point?
 *         
 */
class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
protected:
    /**
     * The interpolated point?
     */
    Vector3 m_PointValue;

public:
    const Vector3& GetPointValue() const { return m_PointValue; }
    Vector3& GetPointValue() { return m_PointValue; }
    void SetPointValue(const Vector3& value) { m_PointValue = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
