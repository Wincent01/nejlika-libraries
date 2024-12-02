#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A string of given length.
 *         
 */
class SizedString : public Construct
{
protected:
    /**
     * The string length.
     */
    uint m_Length;
    /**
     * The string itself.
     */
    std::vector<char> m_Value;

public:
    const uint& GetLength() const { return m_Length; }
    uint& GetLength() { return m_Length; }
    void SetLength(const uint& value) { m_Length = value; }

    const std::vector<char>& GetValue() const { return m_Value; }
    std::vector<char>& GetValue() { return m_Value; }
    void SetValue(const std::vector<char>& value) { m_Value = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
