#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Apparently commands for an optimizer instructing it to keep things it would normally discard.
 *         Also refers to NiNode objects (through their name) in animation .kf files.
 *         
 */
class NiStringExtraData : public NiExtraData
{
protected:
    /**
     * The number of bytes left in the record.  Equals the length of the following string + 4.
     */
    uint m_BytesRemaining;
    /**
     * The string.
     */
    string m_StringData;

public:
    const uint& GetBytesRemaining() const { return m_BytesRemaining; }
    uint& GetBytesRemaining() { return m_BytesRemaining; }
    void SetBytesRemaining(const uint& value) { m_BytesRemaining = value; }

    const string& GetStringData() const { return m_StringData; }
    string& GetStringData() { return m_StringData; }
    void SetStringData(const string& value) { m_StringData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
