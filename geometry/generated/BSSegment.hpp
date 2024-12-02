#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSSegmentFlags.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSSegment : public Construct
{
protected:
    /**
     * Index multiplied by 1536 (0x0600)
     */
    int m_InternalIndex;
    /**
     * Geometry present in the segment
     */
    BSSegmentFlags m_Flags;
    /**
     * Unknown
     */
    byte m_UnknownByte1;

public:
    const int& GetInternalIndex() const { return m_InternalIndex; }
    int& GetInternalIndex() { return m_InternalIndex; }
    void SetInternalIndex(const int& value) { m_InternalIndex = value; }

    const BSSegmentFlags& GetFlags() const { return m_Flags; }
    BSSegmentFlags& GetFlags() { return m_Flags; }
    void SetFlags(const BSSegmentFlags& value) { m_Flags = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
