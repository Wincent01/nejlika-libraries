#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.
 *         
 */
class NiArkAnimationExtraData : public NiExtraData
{
protected:
    std::vector<int> m_UnknownInts;
    std::vector<byte> m_UnknownBytes;

public:
    const std::vector<int>& GetUnknownInts() const { return m_UnknownInts; }
    std::vector<int>& GetUnknownInts() { return m_UnknownInts; }
    void SetUnknownInts(const std::vector<int>& value) { m_UnknownInts = value; }

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
