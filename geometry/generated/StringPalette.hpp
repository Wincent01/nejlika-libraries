#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A list of \\0 terminated strings.
 *         
 */
class StringPalette : public Construct
{
protected:
    /**
     * A bunch of 0x00 seperated strings.
     */
    SizedString m_Palette;
    /**
     * Length of the palette string is repeated here.
     */
    uint m_Length;

public:
    const SizedString& GetPalette() const { return m_Palette; }
    SizedString& GetPalette() { return m_Palette; }
    void SetPalette(const SizedString& value) { m_Palette = value; }

    const uint& GetLength() const { return m_Length; }
    uint& GetLength() { return m_Length; }
    void SetLength(const uint& value) { m_Length = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
