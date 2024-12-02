#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown
 *         
 */
class NiTransparentProperty : public NiProperty
{
protected:
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown;

public:
    const std::vector<byte>& GetUnknown() const { return m_Unknown; }
    std::vector<byte>& GetUnknown() { return m_Unknown; }
    void SetUnknown(const std::vector<byte>& value) { m_Unknown = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
