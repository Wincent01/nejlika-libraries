#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraDataController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiFloatExtraDataController : public NiExtraDataController
{
protected:
    /**
     * Refers to a NiFloatExtraData name.
     */
    string m_ControllerData;
    /**
     * Number of extra bytes.
     */
    byte m_NumExtraBytes;
    /**
     * Unknown.
     */
    std::vector<byte> m_UnknownBytes;
    /**
     * Unknown.
     */
    std::vector<byte> m_UnknownExtraBytes;

public:
    const string& GetControllerData() const { return m_ControllerData; }
    string& GetControllerData() { return m_ControllerData; }
    void SetControllerData(const string& value) { m_ControllerData = value; }

    const byte& GetNumExtraBytes() const { return m_NumExtraBytes; }
    byte& GetNumExtraBytes() { return m_NumExtraBytes; }
    void SetNumExtraBytes(const byte& value) { m_NumExtraBytes = value; }

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }

    const std::vector<byte>& GetUnknownExtraBytes() const { return m_UnknownExtraBytes; }
    std::vector<byte>& GetUnknownExtraBytes() { return m_UnknownExtraBytes; }
    void SetUnknownExtraBytes(const std::vector<byte>& value) { m_UnknownExtraBytes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
