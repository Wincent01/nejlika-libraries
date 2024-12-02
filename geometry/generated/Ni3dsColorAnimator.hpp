#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown!
 *         
 */
class Ni3dsColorAnimator : public NiObject
{
protected:
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown1;

public:
    const std::vector<byte>& GetUnknown1() const { return m_Unknown1; }
    std::vector<byte>& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const std::vector<byte>& value) { m_Unknown1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
