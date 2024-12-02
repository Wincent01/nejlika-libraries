#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node.
 *         
 */
class BSDebrisNode : public NiNode
{
protected:
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * Unknown
     */
    short m_UnknownShort2;

public:
    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const short& GetUnknownShort2() const { return m_UnknownShort2; }
    short& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const short& value) { m_UnknownShort2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
