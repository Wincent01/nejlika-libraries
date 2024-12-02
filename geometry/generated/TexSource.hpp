#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FilePath.hpp"
#include "NiObject.hpp"
#include "FilePath.hpp"
#include "NiPixelData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A texture source.
 *         
 */
class TexSource : public Construct
{
protected:
    /**
     * Is the texture external?
     */
    byte m_UseExternal;
    /**
     * 
     *             The external texture file name.
     * 
     *             Note: all original morrowind nifs use name.ext only for addressing the textures, but most mods use something like textures/[subdir/]name.ext. This is due to a feature in Morrowind resource manager: it loads name.ext, textures/name.ext and textures/subdir/name.ext but NOT subdir/name.ext.
     *         
     */
    FilePath m_FileName;
    /**
     * Unknown.
     */
    Pointer<class NiObject*> m_UnknownLink;
    /**
     * Unknown.
     */
    byte m_UnknownByte;
    /**
     * Pixel data object index.
     */
    Pointer<class NiPixelData*> m_PixelData;

public:
    const byte& GetUseExternal() const { return m_UseExternal; }
    byte& GetUseExternal() { return m_UseExternal; }
    void SetUseExternal(const byte& value) { m_UseExternal = value; }

    const FilePath& GetFileName() const { return m_FileName; }
    FilePath& GetFileName() { return m_FileName; }
    void SetFileName(const FilePath& value) { m_FileName = value; }

    const Pointer<class NiObject*>& GetUnknownLink() const { return m_UnknownLink; }
    Pointer<class NiObject*>& GetUnknownLink() { return m_UnknownLink; }
    void SetUnknownLink(const Pointer<class NiObject*>& value) { m_UnknownLink = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const Pointer<class NiPixelData*>& GetPixelData() const { return m_PixelData; }
    Pointer<class NiPixelData*>& GetPixelData() { return m_PixelData; }
    void SetPixelData(const Pointer<class NiPixelData*>& value) { m_PixelData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
