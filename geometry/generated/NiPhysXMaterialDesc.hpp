#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.
 *         
 */
class NiPhysXMaterialDesc : public NiObject
{
protected:
    /**
     * Unknown
     */
    std::vector<uint> m_UnknownInt;
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * Unknown
     */
    byte m_UnknownByte2;

public:
    const std::vector<uint>& GetUnknownInt() const { return m_UnknownInt; }
    std::vector<uint>& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const std::vector<uint>& value) { m_UnknownInt = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
