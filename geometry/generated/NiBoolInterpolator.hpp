#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBoolData.hpp"
#include "NiKeyBasedInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiBoolInterpolator : public NiKeyBasedInterpolator
{
protected:
    /**
     * Value when posed?  At time 0?
     */
    bool m_BoolValue;
    /**
     * Refers to a NiBoolData object.
     */
    Pointer<class NiBoolData*> m_Data;

public:
    const bool& GetBoolValue() const { return m_BoolValue; }
    bool& GetBoolValue() { return m_BoolValue; }
    void SetBoolValue(const bool& value) { m_BoolValue = value; }

    const Pointer<class NiBoolData*>& GetData() const { return m_Data; }
    Pointer<class NiBoolData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiBoolData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
