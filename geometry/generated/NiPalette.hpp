#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ByteColor4.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A color palette.
 *         
 */
class NiPalette : public NiObject
{
protected:
    /**
     * Unknown, Usually = 0.
     */
    byte m_UnknownByte;
    /**
     * The number of palette entries.  Always = 256.
     */
    uint m_NumEntries;
    /**
     * The color palette.
     */
    std::vector<ByteColor4> m_Palette;

public:
    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const uint& GetNumEntries() const { return m_NumEntries; }
    uint& GetNumEntries() { return m_NumEntries; }
    void SetNumEntries(const uint& value) { m_NumEntries = value; }

    const std::vector<ByteColor4>& GetPalette() const { return m_Palette; }
    std::vector<ByteColor4>& GetPalette() { return m_Palette; }
    void SetPalette(const std::vector<ByteColor4>& value) { m_Palette = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
