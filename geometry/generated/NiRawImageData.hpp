#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ImageType.hpp"
#include "ByteColor3.hpp"
#include "ByteColor4.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Raw image data.
 *         
 */
class NiRawImageData : public NiObject
{
protected:
    /**
     * Image width
     */
    uint m_Width;
    /**
     * Image height
     */
    uint m_Height;
    /**
     * The format of the raw image data.
     */
    ImageType m_ImageType;
    /**
     * Image pixel data.
     */
    std::vector<std::vector<ByteColor3>> m_RGBImageData;
    /**
     * Image pixel data.
     */
    std::vector<std::vector<ByteColor4>> m_RGBAImageData;

public:
    const uint& GetWidth() const { return m_Width; }
    uint& GetWidth() { return m_Width; }
    void SetWidth(const uint& value) { m_Width = value; }

    const uint& GetHeight() const { return m_Height; }
    uint& GetHeight() { return m_Height; }
    void SetHeight(const uint& value) { m_Height = value; }

    const ImageType& GetImageType() const { return m_ImageType; }
    ImageType& GetImageType() { return m_ImageType; }
    void SetImageType(const ImageType& value) { m_ImageType = value; }

    const std::vector<std::vector<ByteColor3>>& GetRGBImageData() const { return m_RGBImageData; }
    std::vector<std::vector<ByteColor3>>& GetRGBImageData() { return m_RGBImageData; }
    void SetRGBImageData(const std::vector<std::vector<ByteColor3>>& value) { m_RGBImageData = value; }

    const std::vector<std::vector<ByteColor4>>& GetRGBAImageData() const { return m_RGBAImageData; }
    std::vector<std::vector<ByteColor4>>& GetRGBAImageData() { return m_RGBAImageData; }
    void SetRGBAImageData(const std::vector<std::vector<ByteColor4>>& value) { m_RGBAImageData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
