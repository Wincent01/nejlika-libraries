#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "AdditionalDataInfo.hpp"
#include "BSPackedAdditionalDataBlock.hpp"
#include "AbstractAdditionalGeometryData.hpp"
namespace nejlika::geometry {


class BSPackedAdditionalGeometryData : public AbstractAdditionalGeometryData
{
protected:
    ushort m_NumVertices;
    /**
     * Information about additional data blocks
     */
    uint m_NumBlockInfos;
    /**
     * Number of additional data blocks
     */
    std::vector<AdditionalDataInfo> m_BlockInfos;
    /**
     * Number of additional data blocks. Usually there is exactly one block.
     */
    int m_NumBlocks;
    /**
     * Number of additional data blocks
     */
    std::vector<BSPackedAdditionalDataBlock> m_Blocks;

public:
    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const uint& GetNumBlockInfos() const { return m_NumBlockInfos; }
    uint& GetNumBlockInfos() { return m_NumBlockInfos; }
    void SetNumBlockInfos(const uint& value) { m_NumBlockInfos = value; }

    const std::vector<AdditionalDataInfo>& GetBlockInfos() const { return m_BlockInfos; }
    std::vector<AdditionalDataInfo>& GetBlockInfos() { return m_BlockInfos; }
    void SetBlockInfos(const std::vector<AdditionalDataInfo>& value) { m_BlockInfos = value; }

    const int& GetNumBlocks() const { return m_NumBlocks; }
    int& GetNumBlocks() { return m_NumBlocks; }
    void SetNumBlocks(const int& value) { m_NumBlocks = value; }

    const std::vector<BSPackedAdditionalDataBlock>& GetBlocks() const { return m_Blocks; }
    std::vector<BSPackedAdditionalDataBlock>& GetBlocks() { return m_Blocks; }
    void SetBlocks(const std::vector<BSPackedAdditionalDataBlock>& value) { m_Blocks = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}