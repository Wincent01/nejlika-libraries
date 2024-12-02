#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         An array of bytes.
 *         
 */
class ByteArray : public Construct
{
protected:
    /**
     * The number of bytes in this array
     */
    uint m_DataSize;
    /**
     * The bytes which make up the array
     */
    std::vector<byte> m_Data;

public:
    const uint& GetDataSize() const { return m_DataSize; }
    uint& GetDataSize() { return m_DataSize; }
    void SetDataSize(const uint& value) { m_DataSize = value; }

    const std::vector<byte>& GetData() const { return m_Data; }
    std::vector<byte>& GetData() { return m_Data; }
    void SetData(const std::vector<byte>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
