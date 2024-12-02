#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ATextureRenderData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A texture.
 *         
 */
class NiPixelData : public ATextureRenderData
{
protected:
    /**
     * Total number of pixels
     */
    uint m_NumPixels;
    /**
     * Unknown
     */
    uint m_NumFaces;
    /**
     * Raw pixel data holding the mipmaps.  Mipmap zero is the full-size texture and they get smaller by half as the number increases.
     */
    std::vector<std::vector<byte>> m_PixelData;

public:
    const uint& GetNumPixels() const { return m_NumPixels; }
    uint& GetNumPixels() { return m_NumPixels; }
    void SetNumPixels(const uint& value) { m_NumPixels = value; }

    const uint& GetNumFaces() const { return m_NumFaces; }
    uint& GetNumFaces() { return m_NumFaces; }
    void SetNumFaces(const uint& value) { m_NumFaces = value; }

    const std::vector<std::vector<byte>>& GetPixelData() const { return m_PixelData; }
    std::vector<std::vector<byte>>& GetPixelData() { return m_PixelData; }
    void SetPixelData(const std::vector<std::vector<byte>>& value) { m_PixelData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
