#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Transparency. Flags 0x00ED.
 *         
 */
class NiAlphaProperty : public NiProperty
{
protected:
    /**
     * 
     *             Bit 0 : alpha blending enable
     *             Bits 1-4 : source blend mode
     *             Bits 5-8 : destination blend mode
     *             Bit 9 : alpha test enable
     *             Bit 10-12 : alpha test mode
     *             Bit 13 : no sorter flag ( disables triangle sorting )
     * 
     *             blend modes (glBlendFunc):
     *             0000 GL_ONE
     *             0001 GL_ZERO
     *             0010 GL_SRC_COLOR
     *             0011 GL_ONE_MINUS_SRC_COLOR
     *             0100 GL_DST_COLOR
     *             0101 GL_ONE_MINUS_DST_COLOR
     *             0110 GL_SRC_ALPHA
     *             0111 GL_ONE_MINUS_SRC_ALPHA
     *             1000 GL_DST_ALPHA
     *             1001 GL_ONE_MINUS_DST_ALPHA
     *             1010 GL_SRC_ALPHA_SATURATE
     * 
     *             test modes (glAlphaFunc):
     *             000 GL_ALWAYS
     *             001 GL_LESS
     *             010 GL_EQUAL
     *             011 GL_LEQUAL
     *             100 GL_GREATER
     *             101 GL_NOTEQUAL
     *             110 GL_GEQUAL
     *             111 GL_NEVER
     *         
     */
    Flags m_Flags;
    /**
     * Threshold for alpha testing (see: glAlphaFunc)
     */
    byte m_Threshold;
    /**
     * Unknown
     */
    ushort m_UnknownShort1;
    /**
     * Unknown
     */
    uint m_UnknownInt2;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const byte& GetThreshold() const { return m_Threshold; }
    byte& GetThreshold() { return m_Threshold; }
    void SetThreshold(const byte& value) { m_Threshold = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
