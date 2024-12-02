#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Stores the number of control points of a B-spline.
 *         
 */
class NiBSplineBasisData : public NiObject
{
protected:
    /**
     * The number of control points of the B-spline (number of frames of animation plus degree of B-spline minus one).
     */
    uint m_NumControlPoints;

public:
    const uint& GetNumControlPoints() const { return m_NumControlPoints; }
    uint& GetNumControlPoints() { return m_NumControlPoints; }
    void SetNumControlPoints(const uint& value) { m_NumControlPoints = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
