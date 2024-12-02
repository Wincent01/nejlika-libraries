#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FilePath.hpp"
#include "NiObject.hpp"
#include "FilePath.hpp"
#include "ATextureRenderData.hpp"
#include "PixelLayout.hpp"
#include "MipMapFormat.hpp"
#include "AlphaFormat.hpp"
#include "NiTexture.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes texture source and properties.
 *         
 */
class NiSourceTexture : public NiTexture
{
protected:
    /**
     * Is the texture external?
     */
    byte m_UseExternal;
    /**
     * The external texture file name.
     */
    FilePath m_FileName;
    /**
     * Unknown.
     */
    Pointer<class NiObject*> m_UnknownLink;
    /**
     * Unknown. Seems to be set if Pixel Data is present?
     */
    byte m_UnknownByte;
    /**
     * Pixel data object index. NiPixelData or NiPersistentSrcTextureRendererData
     */
    Pointer<class ATextureRenderData*> m_PixelData;
    /**
     * Specifies the way the image will be stored.
     */
    PixelLayout m_PixelLayout;
    /**
     * Specifies whether mip maps are used.
     */
    MipMapFormat m_UseMipmaps;
    /**
     *  Note: the NiTriShape linked to this object must have a NiAlphaProperty in its list of properties to enable material and/or texture transparency.
     */
    AlphaFormat m_AlphaFormat;
    /**
     * Is Static?
     */
    byte m_IsStatic;
    /**
     * Load direct to renderer
     */
    bool m_DirectRender;
    /**
     * Render data is persistant
     */
    bool m_PersistRenderData;

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

    const Pointer<class ATextureRenderData*>& GetPixelData() const { return m_PixelData; }
    Pointer<class ATextureRenderData*>& GetPixelData() { return m_PixelData; }
    void SetPixelData(const Pointer<class ATextureRenderData*>& value) { m_PixelData = value; }

    const PixelLayout& GetPixelLayout() const { return m_PixelLayout; }
    PixelLayout& GetPixelLayout() { return m_PixelLayout; }
    void SetPixelLayout(const PixelLayout& value) { m_PixelLayout = value; }

    const MipMapFormat& GetUseMipmaps() const { return m_UseMipmaps; }
    MipMapFormat& GetUseMipmaps() { return m_UseMipmaps; }
    void SetUseMipmaps(const MipMapFormat& value) { m_UseMipmaps = value; }

    const AlphaFormat& GetAlphaFormat() const { return m_AlphaFormat; }
    AlphaFormat& GetAlphaFormat() { return m_AlphaFormat; }
    void SetAlphaFormat(const AlphaFormat& value) { m_AlphaFormat = value; }

    const byte& GetIsStatic() const { return m_IsStatic; }
    byte& GetIsStatic() { return m_IsStatic; }
    void SetIsStatic(const byte& value) { m_IsStatic = value; }

    const bool& GetDirectRender() const { return m_DirectRender; }
    bool& GetDirectRender() { return m_DirectRender; }
    void SetDirectRender(const bool& value) { m_DirectRender = value; }

    const bool& GetPersistRenderData() const { return m_PersistRenderData; }
    bool& GetPersistRenderData() { return m_PersistRenderData; }
    void SetPersistRenderData(const bool& value) { m_PersistRenderData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
