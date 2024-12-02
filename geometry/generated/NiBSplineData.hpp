#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         B-spline data points as floats, or as shorts for compressed B-splines.
 *         
 */
class NiBSplineData : public NiObject
{
protected:
    /**
     * Number of Float Data Points
     */
    uint m_NumFloatControlPoints;
    /**
     * Float values representing the control data.
     */
    std::vector<float> m_FloatControlPoints;
    /**
     * Number of Short Data Points
     */
    uint m_NumShortControlPoints;
    /**
     * Signed shorts representing the data from 0 to 1 (scaled by SHRT_MAX).
     */
    std::vector<short> m_ShortControlPoints;

public:
    const uint& GetNumFloatControlPoints() const { return m_NumFloatControlPoints; }
    uint& GetNumFloatControlPoints() { return m_NumFloatControlPoints; }
    void SetNumFloatControlPoints(const uint& value) { m_NumFloatControlPoints = value; }

    const std::vector<float>& GetFloatControlPoints() const { return m_FloatControlPoints; }
    std::vector<float>& GetFloatControlPoints() { return m_FloatControlPoints; }
    void SetFloatControlPoints(const std::vector<float>& value) { m_FloatControlPoints = value; }

    const uint& GetNumShortControlPoints() const { return m_NumShortControlPoints; }
    uint& GetNumShortControlPoints() { return m_NumShortControlPoints; }
    void SetNumShortControlPoints(const uint& value) { m_NumShortControlPoints = value; }

    const std::vector<short>& GetShortControlPoints() const { return m_ShortControlPoints; }
    std::vector<short>& GetShortControlPoints() { return m_ShortControlPoints; }
    void SetShortControlPoints(const std::vector<short>& value) { m_ShortControlPoints = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
