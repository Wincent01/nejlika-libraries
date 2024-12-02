#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiImage.hpp"
#include "TexClampMode.hpp"
#include "TexFilterMode.hpp"
namespace nejlika::geometry {


class MultiTextureElement : public Construct
{
protected:
    /**
     * Looks like a memory address, so probably a bool.
     */
    bool m_HasImage;
    /**
     * Link to the texture image.
     */
    Pointer<class NiImage*> m_Image;
    /**
     * May be texture clamp mode.
     */
    TexClampMode m_Clamp;
    /**
     * May be texture filter mode.
     */
    TexFilterMode m_Filter;
    /**
     * This may be the UV set counting from 1 instead of zero.
     */
    uint m_UVSet;
    /**
     * 0?
     */
    short m_PS2L;
    /**
     * -75?
     */
    short m_PS2K;
    /**
     * Unknown.  Usually 0 but sometimes 257
     */
    short m_UnknownShort3;

public:
    const bool& GetHasImage() const { return m_HasImage; }
    bool& GetHasImage() { return m_HasImage; }
    void SetHasImage(const bool& value) { m_HasImage = value; }

    const Pointer<class NiImage*>& GetImage() const { return m_Image; }
    Pointer<class NiImage*>& GetImage() { return m_Image; }
    void SetImage(const Pointer<class NiImage*>& value) { m_Image = value; }

    const TexClampMode& GetClamp() const { return m_Clamp; }
    TexClampMode& GetClamp() { return m_Clamp; }
    void SetClamp(const TexClampMode& value) { m_Clamp = value; }

    const TexFilterMode& GetFilter() const { return m_Filter; }
    TexFilterMode& GetFilter() { return m_Filter; }
    void SetFilter(const TexFilterMode& value) { m_Filter = value; }

    const uint& GetUVSet() const { return m_UVSet; }
    uint& GetUVSet() { return m_UVSet; }
    void SetUVSet(const uint& value) { m_UVSet = value; }

    const short& GetPS2L() const { return m_PS2L; }
    short& GetPS2L() { return m_PS2L; }
    void SetPS2L(const short& value) { m_PS2L = value; }

    const short& GetPS2K() const { return m_PS2K; }
    short& GetPS2K() { return m_PS2K; }
    void SetPS2K(const short& value) { m_PS2K = value; }

    const short& GetUnknownShort3() const { return m_UnknownShort3; }
    short& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const short& value) { m_UnknownShort3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
