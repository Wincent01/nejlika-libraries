#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Another string format, for short strings.  Specific to Bethesda-specific header tags.
 *         
 */
class ShortString : public Construct
{
protected:
    /**
     * The string length.
     */
    byte m_Length;
    /**
     * The string itself, null terminated (the null terminator is taken into account in the length byte).
     */
    std::vector<char> m_Value;

public:
    const byte& GetLength() const { return m_Length; }
    byte& GetLength() { return m_Length; }
    void SetLength(const byte& value) { m_Length = value; }

    const std::vector<char>& GetValue() const { return m_Value; }
    std::vector<char>& GetValue() { return m_Value; }
    void SetValue(const std::vector<char>& value) { m_Value = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
