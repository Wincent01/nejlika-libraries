#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class AdditionalDataBlock : public Construct
{
protected:
    /**
     * Has data
     */
    bool m_HasData;
    /**
     * Size of Block
     */
    int m_BlockSize;
    /**
     * Unknown
     */
    int m_NumBlocks;
    /**
     * Unknown
     */
    std::vector<int> m_BlockOffsets;
    /**
     * Unknown
     */
    int m_NumData;
    /**
     * Unknown
     */
    std::vector<int> m_DataSizes;
    /**
     * Unknown
     */
    std::vector<std::vector<byte>> m_Data;

public:
    const bool& GetHasData() const { return m_HasData; }
    bool& GetHasData() { return m_HasData; }
    void SetHasData(const bool& value) { m_HasData = value; }

    const int& GetBlockSize() const { return m_BlockSize; }
    int& GetBlockSize() { return m_BlockSize; }
    void SetBlockSize(const int& value) { m_BlockSize = value; }

    const int& GetNumBlocks() const { return m_NumBlocks; }
    int& GetNumBlocks() { return m_NumBlocks; }
    void SetNumBlocks(const int& value) { m_NumBlocks = value; }

    const std::vector<int>& GetBlockOffsets() const { return m_BlockOffsets; }
    std::vector<int>& GetBlockOffsets() { return m_BlockOffsets; }
    void SetBlockOffsets(const std::vector<int>& value) { m_BlockOffsets = value; }

    const int& GetNumData() const { return m_NumData; }
    int& GetNumData() { return m_NumData; }
    void SetNumData(const int& value) { m_NumData = value; }

    const std::vector<int>& GetDataSizes() const { return m_DataSizes; }
    std::vector<int>& GetDataSizes() { return m_DataSizes; }
    void SetDataSizes(const std::vector<int>& value) { m_DataSizes = value; }

    const std::vector<std::vector<byte>>& GetData() const { return m_Data; }
    std::vector<std::vector<byte>>& GetData() { return m_Data; }
    void SetData(const std::vector<std::vector<byte>>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
