#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiSourceTexture.hpp"
#include "TexClampMode.hpp"
#include "TexFilterMode.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Texture description.
 *         
 */
class TexDesc : public Construct
{
protected:
    /**
     * NiSourceTexture object index.
     */
    Pointer<class NiSourceTexture*> m_Source;
    /**
     * 0=clamp S clamp T, 1=clamp S wrap T, 2=wrap S clamp T, 3=wrap S wrap T
     */
    TexClampMode m_ClampMode;
    /**
     * 0=nearest, 1=bilinear, 2=trilinear, 3=..., 4=..., 5=...
     */
    TexFilterMode m_FilterMode;
    /**
     * Texture mode flags; clamp and filter mode stored in upper byte with 0xYZ00 = clamp mode Y, filter mode Z.
     */
    Flags m_Flags;
    /**
     * Unknown, seems to always be 1
     */
    short m_UnknownShort;
    /**
     * The texture coordinate set in NiGeometryData that this texture slot will use.
     */
    uint m_UVSet;
    /**
     * PS2 only; from the Freedom Force docs, "L values can range from 0 to 3 and are used to specify how fast a texture gets blurry".
     */
    short m_PS2L;
    /**
     * PS2 only; from the Freedom Force docs, "The K value is used as an offset into the mipmap levels and can range from -2047 to 2047. Positive values push the mipmap towards being blurry and negative values make the mipmap sharper." -75 for most v4.0.0.2 meshes.
     */
    short m_PS2K;
    /**
     * Unknown, 0 or 0x0101?
     */
    ushort m_Unknown1;
    /**
     * Determines whether or not the texture's coordinates are transformed.
     */
    bool m_HasTextureTransform;
    /**
     * The amount to translate the texture coordinates in each direction?
     */
    TexCoord m_Translation;
    /**
     * The number of times the texture is tiled in each direction?
     */
    TexCoord m_Tiling;
    /**
     * 2D Rotation of texture image around third W axis after U and V.
     */
    float m_WRotation;
    /**
     * The texture transform type?  Doesn't seem to do anything.
     */
    uint m_TransformType;
    /**
     * The offset from the origin?
     */
    TexCoord m_CenterOffset;

public:
    const Pointer<class NiSourceTexture*>& GetSource() const { return m_Source; }
    Pointer<class NiSourceTexture*>& GetSource() { return m_Source; }
    void SetSource(const Pointer<class NiSourceTexture*>& value) { m_Source = value; }

    const TexClampMode& GetClampMode() const { return m_ClampMode; }
    TexClampMode& GetClampMode() { return m_ClampMode; }
    void SetClampMode(const TexClampMode& value) { m_ClampMode = value; }

    const TexFilterMode& GetFilterMode() const { return m_FilterMode; }
    TexFilterMode& GetFilterMode() { return m_FilterMode; }
    void SetFilterMode(const TexFilterMode& value) { m_FilterMode = value; }

    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const short& GetUnknownShort() const { return m_UnknownShort; }
    short& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const short& value) { m_UnknownShort = value; }

    const uint& GetUVSet() const { return m_UVSet; }
    uint& GetUVSet() { return m_UVSet; }
    void SetUVSet(const uint& value) { m_UVSet = value; }

    const short& GetPS2L() const { return m_PS2L; }
    short& GetPS2L() { return m_PS2L; }
    void SetPS2L(const short& value) { m_PS2L = value; }

    const short& GetPS2K() const { return m_PS2K; }
    short& GetPS2K() { return m_PS2K; }
    void SetPS2K(const short& value) { m_PS2K = value; }

    const ushort& GetUnknown1() const { return m_Unknown1; }
    ushort& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const ushort& value) { m_Unknown1 = value; }

    const bool& GetHasTextureTransform() const { return m_HasTextureTransform; }
    bool& GetHasTextureTransform() { return m_HasTextureTransform; }
    void SetHasTextureTransform(const bool& value) { m_HasTextureTransform = value; }

    const TexCoord& GetTranslation() const { return m_Translation; }
    TexCoord& GetTranslation() { return m_Translation; }
    void SetTranslation(const TexCoord& value) { m_Translation = value; }

    const TexCoord& GetTiling() const { return m_Tiling; }
    TexCoord& GetTiling() { return m_Tiling; }
    void SetTiling(const TexCoord& value) { m_Tiling = value; }

    const float& GetWRotation() const { return m_WRotation; }
    float& GetWRotation() { return m_WRotation; }
    void SetWRotation(const float& value) { m_WRotation = value; }

    const uint& GetTransformType() const { return m_TransformType; }
    uint& GetTransformType() { return m_TransformType; }
    void SetTransformType(const uint& value) { m_TransformType = value; }

    const TexCoord& GetCenterOffset() const { return m_CenterOffset; }
    TexCoord& GetCenterOffset() { return m_CenterOffset; }
    void SetCenterOffset(const TexCoord& value) { m_CenterOffset = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
