#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ZCompareMode.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         This Property controls the Z buffer (OpenGL: depth buffer).
 *         
 */
class NiZBufferProperty : public NiProperty
{
protected:
    /**
     * 
     *             Bit 0 enables the z test
     *             Bit 1 controls wether the Z buffer is read only (0) or read/write (1)
     *         
     */
    Flags m_Flags;
    /**
     * 
     *             Z-Test function (see: glDepthFunc). In Flags from 20.1.0.3 on.
     *         
     */
    ZCompareMode m_Function;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const ZCompareMode& GetFunction() const { return m_Function; }
    ZCompareMode& GetFunction() { return m_Function; }
    void SetFunction(const ZCompareMode& value) { m_Function = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
