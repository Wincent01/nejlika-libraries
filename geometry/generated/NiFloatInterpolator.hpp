#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiFloatData.hpp"
#include "NiKeyBasedInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiFloatInterpolator : public NiKeyBasedInterpolator
{
protected:
    /**
     * Value when posed?  At time 0?
     */
    float m_FloatValue;
    /**
     * Float data?
     */
    Pointer<class NiFloatData*> m_Data;

public:
    const float& GetFloatValue() const { return m_FloatValue; }
    float& GetFloatValue() { return m_FloatValue; }
    void SetFloatValue(const float& value) { m_FloatValue = value; }

    const Pointer<class NiFloatData*>& GetData() const { return m_Data; }
    Pointer<class NiFloatData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiFloatData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
