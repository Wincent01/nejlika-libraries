#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.
 *         
 */
class NiArkImporterExtraData : public NiExtraData
{
protected:
    int m_UnknownInt1;
    int m_UnknownInt2;
    /**
     * Contains a string like "Gamebryo_1_1" or "4.1.0.12"
     */
    string m_ImporterName;
    std::vector<byte> m_UnknownBytes;
    std::vector<float> m_UnknownFloats;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const string& GetImporterName() const { return m_ImporterName; }
    string& GetImporterName() { return m_ImporterName; }
    void SetImporterName(const string& value) { m_ImporterName = value; }

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }

    const std::vector<float>& GetUnknownFloats() const { return m_UnknownFloats; }
    std::vector<float>& GetUnknownFloats() { return m_UnknownFloats; }
    void SetUnknownFloats(const std::vector<float>& value) { m_UnknownFloats = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
