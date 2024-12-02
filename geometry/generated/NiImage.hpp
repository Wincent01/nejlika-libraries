#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FilePath.hpp"
#include "NiRawImageData.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiImage : public NiObject
{
protected:
    /**
     * 0 if the texture is internal to the NIF file.
     */
    byte m_UseExternal;
    /**
     * The filepath to the texture.
     */
    FilePath m_FileName;
    /**
     * Link to the internally stored image data.
     */
    Pointer<class NiRawImageData*> m_ImageData;
    /**
     * Unknown.  Often seems to be 7. Perhaps m_uiMipLevels?
     */
    uint m_UnknownInt;
    /**
     * Unknown.  Perhaps fImageScale?
     */
    float m_UnknownFloat;

public:
    const byte& GetUseExternal() const { return m_UseExternal; }
    byte& GetUseExternal() { return m_UseExternal; }
    void SetUseExternal(const byte& value) { m_UseExternal = value; }

    const FilePath& GetFileName() const { return m_FileName; }
    FilePath& GetFileName() { return m_FileName; }
    void SetFileName(const FilePath& value) { m_FileName = value; }

    const Pointer<class NiRawImageData*>& GetImageData() const { return m_ImageData; }
    Pointer<class NiRawImageData*>& GetImageData() { return m_ImageData; }
    void SetImageData(const Pointer<class NiRawImageData*>& value) { m_ImageData = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
