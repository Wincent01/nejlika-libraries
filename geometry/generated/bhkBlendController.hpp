#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Is apparently only used in skeleton.nif files.
 *         
 */
class bhkBlendController : public NiTimeController
{
protected:
    /**
     * Seems to be always zero.
     */
    uint m_UnknownInt;

public:
    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
