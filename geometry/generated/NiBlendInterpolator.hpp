#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An extended type of interpolater.
 *         
 */
class NiBlendInterpolator : public NiInterpolator
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort;
    /**
     * Unknown.
     */
    uint m_UnknownInt;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
