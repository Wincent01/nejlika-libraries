#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiDitherProperty : public NiProperty
{
protected:
    /**
     * 1's Bit: Enable dithering
     */
    Flags m_Flags;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
