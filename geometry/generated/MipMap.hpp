#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Description of a MipMap within a NiPixelData object.
 *         
 */
class MipMap : public Construct
{
protected:
    /**
     * Width of the mipmap image.
     */
    uint m_Width;
    /**
     * Height of the mipmap image.
     */
    uint m_Height;
    /**
     * Offset into the pixel data array where this mipmap starts.
     */
    uint m_Offset;

public:
    const uint& GetWidth() const { return m_Width; }
    uint& GetWidth() { return m_Width; }
    void SetWidth(const uint& value) { m_Width = value; }

    const uint& GetHeight() const { return m_Height; }
    uint& GetHeight() { return m_Height; }
    void SetHeight(const uint& value) { m_Height = value; }

    const uint& GetOffset() const { return m_Offset; }
    uint& GetOffset() { return m_Offset; }
    void SetOffset(const uint& value) { m_Offset = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
