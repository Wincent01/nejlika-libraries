#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBlendInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An interpolator for a bool.
 *         
 */
class NiBlendBoolInterpolator : public NiBlendInterpolator
{
protected:
    /**
     * The interpolated bool?
     */
    byte m_BoolValue;

public:
    const byte& GetBoolValue() const { return m_BoolValue; }
    byte& GetBoolValue() { return m_BoolValue; }
    void SetBoolValue(const byte& value) { m_BoolValue = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
