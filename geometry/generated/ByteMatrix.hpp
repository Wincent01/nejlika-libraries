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
class ByteMatrix : public Construct
{
protected:
    /**
     * The number of bytes in this array
     */
    uint m_DataSize1;
    /**
     * The number of bytes in this array
     */
    uint m_DataSize2;
    /**
     * The bytes which make up the array
     */
    std::vector<std::vector<byte>> m_Data;

public:
    const uint& GetDataSize1() const { return m_DataSize1; }
    uint& GetDataSize1() { return m_DataSize1; }
    void SetDataSize1(const uint& value) { m_DataSize1 = value; }

    const uint& GetDataSize2() const { return m_DataSize2; }
    uint& GetDataSize2() { return m_DataSize2; }
    void SetDataSize2(const uint& value) { m_DataSize2 = value; }

    const std::vector<std::vector<byte>>& GetData() const { return m_Data; }
    std::vector<std::vector<byte>>& GetData() { return m_Data; }
    void SetData(const std::vector<std::vector<byte>>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
