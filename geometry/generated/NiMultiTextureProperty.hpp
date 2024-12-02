#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "MultiTextureElement.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         (note: not quite complete yet... but already reads most of the DAoC ones)
 *         
 */
class NiMultiTextureProperty : public NiProperty
{
protected:
    /**
     * Property flags.
     */
    Flags m_Flags;
    /**
     * Unknown. Always 5 for DAoC files, and always 6 for Bridge Commander.  Seems to have nothing to do with the number of Texture Element slots that follow.
     */
    uint m_UnknownInt;
    /**
     * Describes the various textures used by this mutli-texture property.  Each slot probably has special meaning like thoes in NiTexturingProperty.
     */
    std::vector<MultiTextureElement> m_TextureElements;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const std::vector<MultiTextureElement>& GetTextureElements() const { return m_TextureElements; }
    std::vector<MultiTextureElement>& GetTextureElements() { return m_TextureElements; }
    void SetTextureElements(const std::vector<MultiTextureElement>& value) { m_TextureElements = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
