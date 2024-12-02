#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBlendInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An interpolator for a float.
 *         
 */
class NiBlendFloatInterpolator : public NiBlendInterpolator
{
protected:
    /**
     * The interpolated float?
     */
    float m_FloatValue;

public:
    const float& GetFloatValue() const { return m_FloatValue; }
    float& GetFloatValue() { return m_FloatValue; }
    void SetFloatValue(const float& value) { m_FloatValue = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
