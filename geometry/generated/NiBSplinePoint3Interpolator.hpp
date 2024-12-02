#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBSplineInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
protected:
    /**
     * Unknown.
     */
    std::vector<float> m_UnknownFloats;

public:
    const std::vector<float>& GetUnknownFloats() const { return m_UnknownFloats; }
    std::vector<float>& GetUnknownFloats() { return m_UnknownFloats; }
    void SetUnknownFloats(const std::vector<float>& value) { m_UnknownFloats = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
