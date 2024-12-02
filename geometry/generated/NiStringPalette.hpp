#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "StringPalette.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         List of 0x00-seperated strings, which are names of controlled objects and controller types. Used in .kf files in conjunction with NiControllerSequence.
 *         
 */
class NiStringPalette : public NiObject
{
protected:
    /**
     * A bunch of 0x00 seperated strings.
     */
    StringPalette m_Palette;

public:
    const StringPalette& GetPalette() const { return m_Palette; }
    StringPalette& GetPalette() { return m_Palette; }
    void SetPalette(const StringPalette& value) { m_Palette = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
