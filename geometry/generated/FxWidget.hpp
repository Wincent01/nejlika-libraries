#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Firaxis-specific UI widgets?
 *         
 */
class FxWidget : public NiNode
{
protected:
    /**
     * Unknown.
     */
    byte m_Unknown3;
    /**
     * Looks like 9 links and some string data.
     */
    std::vector<byte> m_Unknown292Bytes;

public:
    const byte& GetUnknown3() const { return m_Unknown3; }
    byte& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const byte& value) { m_Unknown3 = value; }

    const std::vector<byte>& GetUnknown292Bytes() const { return m_Unknown292Bytes; }
    std::vector<byte>& GetUnknown292Bytes() { return m_Unknown292Bytes; }
    void SetUnknown292Bytes(const std::vector<byte>& value) { m_Unknown292Bytes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
