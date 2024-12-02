#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "PixelFormat.hpp"
#include "ChannelData.hpp"
#include "NiPalette.hpp"
#include "MipMap.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class ATextureRenderData : public NiObject
{
protected:
    /**
     * The format of the pixels in this internally stored image.
     */
    PixelFormat m_PixelFormat;
    /**
     * 0x000000ff (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
     */
    uint m_RedMask;
    /**
     * 0x0000ff00 (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
     */
    uint m_GreenMask;
    /**
     * 0x00ff0000 (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
     */
    uint m_BlueMask;
    /**
     * 0xff000000 (for 32bpp) or 0x00000000 (for 24bpp and 8bpp)
     */
    uint m_AlphaMask;
    /**
     * Bits per pixel, 0 (?), 8, 24 or 32.
     */
    byte m_BitsPerPixel;
    /**
     * Zero?
     */
    std::vector<byte> m_Unknown3Bytes;
    /**
     * 
     *             [96,8,130,0,0,65,0,0] if 24 bits per pixel
     *             [129,8,130,32,0,65,12,0] if 32 bits per pixel
     *             [34,0,0,0,0,0,0,0] if 8 bits per pixel
     *             [4,0,0,0,0,0,0,0] if 0 (?) bits per pixel
     *         
     */
    std::vector<byte> m_Unknown8Bytes;
    /**
     * Seems to always be zero.
     */
    uint m_UnknownInt;
    /**
     * Unknown.  Could be reference pointer.
     */
    int m_UnknownInt2;
    /**
     * Seems to always be zero.
     */
    uint m_UnknownInt3;
    /**
     * Flags
     */
    byte m_Flags;
    /**
     * Unkown. Often zero.
     */
    uint m_UnknownInt4;
    /**
     * Unknown.
     */
    byte m_UnknownByte1;
    /**
     * Channel Data
     */
    std::vector<ChannelData> m_Channels;
    /**
     * Link to NiPalette, for 8-bit textures.
     */
    Pointer<class NiPalette*> m_Palette;
    /**
     * Number of mipmaps in the texture.
     */
    uint m_NumMipmaps;
    /**
     * Bytes per pixel (Bits Per Pixel / 8).
     */
    uint m_BytesPerPixel;
    /**
     * Mipmap descriptions (width, height, offset).
     */
    std::vector<MipMap> m_Mipmaps;

public:
    const PixelFormat& GetPixelFormat() const { return m_PixelFormat; }
    PixelFormat& GetPixelFormat() { return m_PixelFormat; }
    void SetPixelFormat(const PixelFormat& value) { m_PixelFormat = value; }

    const uint& GetRedMask() const { return m_RedMask; }
    uint& GetRedMask() { return m_RedMask; }
    void SetRedMask(const uint& value) { m_RedMask = value; }

    const uint& GetGreenMask() const { return m_GreenMask; }
    uint& GetGreenMask() { return m_GreenMask; }
    void SetGreenMask(const uint& value) { m_GreenMask = value; }

    const uint& GetBlueMask() const { return m_BlueMask; }
    uint& GetBlueMask() { return m_BlueMask; }
    void SetBlueMask(const uint& value) { m_BlueMask = value; }

    const uint& GetAlphaMask() const { return m_AlphaMask; }
    uint& GetAlphaMask() { return m_AlphaMask; }
    void SetAlphaMask(const uint& value) { m_AlphaMask = value; }

    const byte& GetBitsPerPixel() const { return m_BitsPerPixel; }
    byte& GetBitsPerPixel() { return m_BitsPerPixel; }
    void SetBitsPerPixel(const byte& value) { m_BitsPerPixel = value; }

    const std::vector<byte>& GetUnknown3Bytes() const { return m_Unknown3Bytes; }
    std::vector<byte>& GetUnknown3Bytes() { return m_Unknown3Bytes; }
    void SetUnknown3Bytes(const std::vector<byte>& value) { m_Unknown3Bytes = value; }

    const std::vector<byte>& GetUnknown8Bytes() const { return m_Unknown8Bytes; }
    std::vector<byte>& GetUnknown8Bytes() { return m_Unknown8Bytes; }
    void SetUnknown8Bytes(const std::vector<byte>& value) { m_Unknown8Bytes = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const byte& GetFlags() const { return m_Flags; }
    byte& GetFlags() { return m_Flags; }
    void SetFlags(const byte& value) { m_Flags = value; }

    const uint& GetUnknownInt4() const { return m_UnknownInt4; }
    uint& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const uint& value) { m_UnknownInt4 = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const std::vector<ChannelData>& GetChannels() const { return m_Channels; }
    std::vector<ChannelData>& GetChannels() { return m_Channels; }
    void SetChannels(const std::vector<ChannelData>& value) { m_Channels = value; }

    const Pointer<class NiPalette*>& GetPalette() const { return m_Palette; }
    Pointer<class NiPalette*>& GetPalette() { return m_Palette; }
    void SetPalette(const Pointer<class NiPalette*>& value) { m_Palette = value; }

    const uint& GetNumMipmaps() const { return m_NumMipmaps; }
    uint& GetNumMipmaps() { return m_NumMipmaps; }
    void SetNumMipmaps(const uint& value) { m_NumMipmaps = value; }

    const uint& GetBytesPerPixel() const { return m_BytesPerPixel; }
    uint& GetBytesPerPixel() { return m_BytesPerPixel; }
    void SetBytesPerPixel(const uint& value) { m_BytesPerPixel = value; }

    const std::vector<MipMap>& GetMipmaps() const { return m_Mipmaps; }
    std::vector<MipMap>& GetMipmaps() { return m_Mipmaps; }
    void SetMipmaps(const std::vector<MipMap>& value) { m_Mipmaps = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
