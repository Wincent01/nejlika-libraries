#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class AdditionalDataInfo : public Construct
{
protected:
    /**
     * Type of data in this channel
     */
    int m_DataType;
    /**
     * Number of bytes per element of this channel
     */
    int m_NumChannelBytesPerElement;
    /**
     * Total number of bytes of this channel (num vertices times num bytes per element)
     */
    int m_NumChannelBytes;
    /**
     * Number of bytes per element in all channels together. Sum of num channel bytes per element over all block infos.
     */
    int m_NumTotalBytesPerElement;
    /**
     * Unsure. The block in which this channel is stored? Usually there is only one block, and so this is zero.
     */
    int m_BlockIndex;
    /**
     * Offset (in bytes) of this channel. Sum of all num channel bytes per element of all preceeding block infos.
     */
    int m_ChannelOffset;
    /**
     * Unknown, usually equal to 2.
     */
    byte m_UnknownByte1;

public:
    const int& GetDataType() const { return m_DataType; }
    int& GetDataType() { return m_DataType; }
    void SetDataType(const int& value) { m_DataType = value; }

    const int& GetNumChannelBytesPerElement() const { return m_NumChannelBytesPerElement; }
    int& GetNumChannelBytesPerElement() { return m_NumChannelBytesPerElement; }
    void SetNumChannelBytesPerElement(const int& value) { m_NumChannelBytesPerElement = value; }

    const int& GetNumChannelBytes() const { return m_NumChannelBytes; }
    int& GetNumChannelBytes() { return m_NumChannelBytes; }
    void SetNumChannelBytes(const int& value) { m_NumChannelBytes = value; }

    const int& GetNumTotalBytesPerElement() const { return m_NumTotalBytesPerElement; }
    int& GetNumTotalBytesPerElement() { return m_NumTotalBytesPerElement; }
    void SetNumTotalBytesPerElement(const int& value) { m_NumTotalBytesPerElement = value; }

    const int& GetBlockIndex() const { return m_BlockIndex; }
    int& GetBlockIndex() { return m_BlockIndex; }
    void SetBlockIndex(const int& value) { m_BlockIndex = value; }

    const int& GetChannelOffset() const { return m_ChannelOffset; }
    int& GetChannelOffset() { return m_ChannelOffset; }
    void SetChannelOffset(const int& value) { m_ChannelOffset = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
