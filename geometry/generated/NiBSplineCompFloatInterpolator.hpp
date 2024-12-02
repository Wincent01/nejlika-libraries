#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBSplineFloatInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiBSplineCompFloatInterpolator : public NiBSplineFloatInterpolator
{
protected:
    /**
     * Base value when curve not defined.
     */
    float m_Base;
    /**
     * Starting offset for the data. (USHRT_MAX for no data.)
     */
    uint m_Offset;
    /**
     * Bias
     */
    float m_Bias;
    /**
     * Multiplier
     */
    float m_Multiplier;

public:
    const float& GetBase() const { return m_Base; }
    float& GetBase() { return m_Base; }
    void SetBase(const float& value) { m_Base = value; }

    const uint& GetOffset() const { return m_Offset; }
    uint& GetOffset() { return m_Offset; }
    void SetOffset(const uint& value) { m_Offset = value; }

    const float& GetBias() const { return m_Bias; }
    float& GetBias() { return m_Bias; }
    void SetBias(const float& value) { m_Bias = value; }

    const float& GetMultiplier() const { return m_Multiplier; }
    float& GetMultiplier() { return m_Multiplier; }
    void SetMultiplier(const float& value) { m_Multiplier = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
