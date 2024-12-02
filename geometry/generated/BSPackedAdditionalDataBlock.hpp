#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class BSPackedAdditionalDataBlock : public Construct
{
protected:
    /**
     * Has data
     */
    bool m_HasData;
    /**
     * Total number of bytes (over all channels and all elements, equals num total bytes per element times num vertices).
     */
    int m_NumTotalBytes;
    /**
     * Number of blocks? Usually equal to one.
     */
    int m_NumBlocks;
    /**
     * Block offsets in the data? Usually equal to zero.
     */
    std::vector<int> m_BlockOffsets;
    /**
     * Number of atoms?
     */
    int m_NumAtoms;
    /**
     * The sum of all of these equal num total bytes per element, so this probably describes how each data element breaks down into smaller chunks (i.e. atoms).
     */
    std::vector<int> m_AtomSizes;
    /**
     * Unknown
     */
    std::vector<byte> m_Data;
    int m_UnknownInt1;
    /**
     * Unsure, but this seems to correspond again to the number of total bytes per element.
     */
    int m_NumTotalBytesPerElement;

public:
    const bool& GetHasData() const { return m_HasData; }
    bool& GetHasData() { return m_HasData; }
    void SetHasData(const bool& value) { m_HasData = value; }

    const int& GetNumTotalBytes() const { return m_NumTotalBytes; }
    int& GetNumTotalBytes() { return m_NumTotalBytes; }
    void SetNumTotalBytes(const int& value) { m_NumTotalBytes = value; }

    const int& GetNumBlocks() const { return m_NumBlocks; }
    int& GetNumBlocks() { return m_NumBlocks; }
    void SetNumBlocks(const int& value) { m_NumBlocks = value; }

    const std::vector<int>& GetBlockOffsets() const { return m_BlockOffsets; }
    std::vector<int>& GetBlockOffsets() { return m_BlockOffsets; }
    void SetBlockOffsets(const std::vector<int>& value) { m_BlockOffsets = value; }

    const int& GetNumAtoms() const { return m_NumAtoms; }
    int& GetNumAtoms() { return m_NumAtoms; }
    void SetNumAtoms(const int& value) { m_NumAtoms = value; }

    const std::vector<int>& GetAtomSizes() const { return m_AtomSizes; }
    std::vector<int>& GetAtomSizes() { return m_AtomSizes; }
    void SetAtomSizes(const std::vector<int>& value) { m_AtomSizes = value; }

    const std::vector<byte>& GetData() const { return m_Data; }
    std::vector<byte>& GetData() { return m_Data; }
    void SetData(const std::vector<byte>& value) { m_Data = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetNumTotalBytesPerElement() const { return m_NumTotalBytesPerElement; }
    int& GetNumTotalBytesPerElement() { return m_NumTotalBytesPerElement; }
    void SetNumTotalBytesPerElement(const int& value) { m_NumTotalBytesPerElement = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
