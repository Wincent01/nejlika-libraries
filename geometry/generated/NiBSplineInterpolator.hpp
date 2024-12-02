#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBSplineData.hpp"
#include "NiBSplineBasisData.hpp"
#include "NiInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         For interpolators storing data via a B-spline.
 *         
 */
class NiBSplineInterpolator : public NiInterpolator
{
protected:
    /**
     * Animation start time.
     */
    float m_StartTime;
    /**
     * Animation stop time.
     */
    float m_StopTime;
    /**
     * Refers to NiBSplineData.
     */
    Pointer<class NiBSplineData*> m_SplineData;
    /**
     * Refers to NiBSPlineBasisData.
     */
    Pointer<class NiBSplineBasisData*> m_BasisData;

public:
    const float& GetStartTime() const { return m_StartTime; }
    float& GetStartTime() { return m_StartTime; }
    void SetStartTime(const float& value) { m_StartTime = value; }

    const float& GetStopTime() const { return m_StopTime; }
    float& GetStopTime() { return m_StopTime; }
    void SetStopTime(const float& value) { m_StopTime = value; }

    const Pointer<class NiBSplineData*>& GetSplineData() const { return m_SplineData; }
    Pointer<class NiBSplineData*>& GetSplineData() { return m_SplineData; }
    void SetSplineData(const Pointer<class NiBSplineData*>& value) { m_SplineData = value; }

    const Pointer<class NiBSplineBasisData*>& GetBasisData() const { return m_BasisData; }
    Pointer<class NiBSplineBasisData*>& GetBasisData() { return m_BasisData; }
    void SetBasisData(const Pointer<class NiBSplineBasisData*>& value) { m_BasisData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
