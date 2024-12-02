#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ChannelType.hpp"
#include "ChannelConvention.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Channel data
 *         
 */
class ChannelData : public Construct
{
protected:
    /**
     * Channel Type
     */
    ChannelType m_Type;
    /**
     * Data Storage Convention
     */
    ChannelConvention m_Convention;
    /**
     * Bits per channel
     */
    byte m_BitsPerChannel;
    /**
     * Unknown
     */
    byte m_UnknownByte1;

public:
    const ChannelType& GetType() const { return m_Type; }
    ChannelType& GetType() { return m_Type; }
    void SetType(const ChannelType& value) { m_Type = value; }

    const ChannelConvention& GetConvention() const { return m_Convention; }
    ChannelConvention& GetConvention() { return m_Convention; }
    void SetConvention(const ChannelConvention& value) { m_Convention = value; }

    const byte& GetBitsPerChannel() const { return m_BitsPerChannel; }
    byte& GetBitsPerChannel() { return m_BitsPerChannel; }
    void SetBitsPerChannel(const byte& value) { m_BitsPerChannel = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
