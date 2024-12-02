#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ApplyMode.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "Matrix22.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "TexDesc.hpp"
#include "ShaderTexDesc.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes an object's textures.
 *         
 */
class NiTexturingProperty : public NiProperty
{
protected:
    /**
     * Property flags.
     */
    Flags m_Flags;
    /**
     * Determines how the texture will be applied.  Seems to have special functions in Oblivion.
     */
    ApplyMode m_ApplyMode;
    /**
     * Number of textures. Always 7 in versions < 20.0.0.4. Can also be 8 in >= 20.0.0.4.
     */
    uint m_TextureCount;
    /**
     * Do we have a base texture?
     */
    bool m_HasBaseTexture;
    /**
     * The base texture.
     */
    TexDesc m_BaseTexture;
    /**
     * Do we have a dark texture?
     */
    bool m_HasDarkTexture;
    /**
     * The dark texture.
     */
    TexDesc m_DarkTexture;
    /**
     * Do we have a detail texture?
     */
    bool m_HasDetailTexture;
    /**
     * The detail texture.
     */
    TexDesc m_DetailTexture;
    /**
     * Do we have a gloss texture?
     */
    bool m_HasGlossTexture;
    /**
     * The gloss texture.
     */
    TexDesc m_GlossTexture;
    /**
     * Do we have a glow texture?
     */
    bool m_HasGlowTexture;
    /**
     * The glowing texture.
     */
    TexDesc m_GlowTexture;
    /**
     * Do we have a bump map texture?
     */
    bool m_HasBumpMapTexture;
    /**
     * The bump map texture.
     */
    TexDesc m_BumpMapTexture;
    /**
     * Unknown.
     */
    float m_BumpMapLumaScale;
    /**
     * Unknown.
     */
    float m_BumpMapLumaOffset;
    /**
     * Unknown.
     */
    Matrix22 m_BumpMapMatrix;
    /**
     * Do we have a normal texture?  (Noraml guess based on file suffix in sample files)
     */
    bool m_HasNormalTexture;
    /**
     * Normal texture.
     */
    TexDesc m_NormalTexture;
    /**
     * Do we have a unknown texture 2?
     */
    bool m_HasUnknown2Texture;
    /**
     * Unknown texture 2.
     */
    TexDesc m_Unknown2Texture;
    /**
     * Unknown.
     */
    float m_Unknown2Float;
    /**
     * Do we have a decal 0 texture?
     */
    bool m_HasDecal0Texture;
    /**
     * The decal texture.
     */
    TexDesc m_Decal0Texture;
    /**
     * Do we have a decal 1 texture?
     */
    bool m_HasDecal1Texture;
    /**
     * Another decal texture.
     */
    TexDesc m_Decal1Texture;
    /**
     * Do we have a decal 2 texture?
     */
    bool m_HasDecal2Texture;
    /**
     * Another decal texture.
     */
    TexDesc m_Decal2Texture;
    /**
     * Do we have a decal 3 texture?
     */
    bool m_HasDecal3Texture;
    /**
     * Another decal texture. Who knows the limit.
     */
    TexDesc m_Decal3Texture;
    /**
     * Number of Shader textures that follow.
     */
    uint m_NumShaderTextures;
    /**
     * Shader textures.
     */
    std::vector<ShaderTexDesc> m_ShaderTextures;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const ApplyMode& GetApplyMode() const { return m_ApplyMode; }
    ApplyMode& GetApplyMode() { return m_ApplyMode; }
    void SetApplyMode(const ApplyMode& value) { m_ApplyMode = value; }

    const uint& GetTextureCount() const { return m_TextureCount; }
    uint& GetTextureCount() { return m_TextureCount; }
    void SetTextureCount(const uint& value) { m_TextureCount = value; }

    const bool& GetHasBaseTexture() const { return m_HasBaseTexture; }
    bool& GetHasBaseTexture() { return m_HasBaseTexture; }
    void SetHasBaseTexture(const bool& value) { m_HasBaseTexture = value; }

    const TexDesc& GetBaseTexture() const { return m_BaseTexture; }
    TexDesc& GetBaseTexture() { return m_BaseTexture; }
    void SetBaseTexture(const TexDesc& value) { m_BaseTexture = value; }

    const bool& GetHasDarkTexture() const { return m_HasDarkTexture; }
    bool& GetHasDarkTexture() { return m_HasDarkTexture; }
    void SetHasDarkTexture(const bool& value) { m_HasDarkTexture = value; }

    const TexDesc& GetDarkTexture() const { return m_DarkTexture; }
    TexDesc& GetDarkTexture() { return m_DarkTexture; }
    void SetDarkTexture(const TexDesc& value) { m_DarkTexture = value; }

    const bool& GetHasDetailTexture() const { return m_HasDetailTexture; }
    bool& GetHasDetailTexture() { return m_HasDetailTexture; }
    void SetHasDetailTexture(const bool& value) { m_HasDetailTexture = value; }

    const TexDesc& GetDetailTexture() const { return m_DetailTexture; }
    TexDesc& GetDetailTexture() { return m_DetailTexture; }
    void SetDetailTexture(const TexDesc& value) { m_DetailTexture = value; }

    const bool& GetHasGlossTexture() const { return m_HasGlossTexture; }
    bool& GetHasGlossTexture() { return m_HasGlossTexture; }
    void SetHasGlossTexture(const bool& value) { m_HasGlossTexture = value; }

    const TexDesc& GetGlossTexture() const { return m_GlossTexture; }
    TexDesc& GetGlossTexture() { return m_GlossTexture; }
    void SetGlossTexture(const TexDesc& value) { m_GlossTexture = value; }

    const bool& GetHasGlowTexture() const { return m_HasGlowTexture; }
    bool& GetHasGlowTexture() { return m_HasGlowTexture; }
    void SetHasGlowTexture(const bool& value) { m_HasGlowTexture = value; }

    const TexDesc& GetGlowTexture() const { return m_GlowTexture; }
    TexDesc& GetGlowTexture() { return m_GlowTexture; }
    void SetGlowTexture(const TexDesc& value) { m_GlowTexture = value; }

    const bool& GetHasBumpMapTexture() const { return m_HasBumpMapTexture; }
    bool& GetHasBumpMapTexture() { return m_HasBumpMapTexture; }
    void SetHasBumpMapTexture(const bool& value) { m_HasBumpMapTexture = value; }

    const TexDesc& GetBumpMapTexture() const { return m_BumpMapTexture; }
    TexDesc& GetBumpMapTexture() { return m_BumpMapTexture; }
    void SetBumpMapTexture(const TexDesc& value) { m_BumpMapTexture = value; }

    const float& GetBumpMapLumaScale() const { return m_BumpMapLumaScale; }
    float& GetBumpMapLumaScale() { return m_BumpMapLumaScale; }
    void SetBumpMapLumaScale(const float& value) { m_BumpMapLumaScale = value; }

    const float& GetBumpMapLumaOffset() const { return m_BumpMapLumaOffset; }
    float& GetBumpMapLumaOffset() { return m_BumpMapLumaOffset; }
    void SetBumpMapLumaOffset(const float& value) { m_BumpMapLumaOffset = value; }

    const Matrix22& GetBumpMapMatrix() const { return m_BumpMapMatrix; }
    Matrix22& GetBumpMapMatrix() { return m_BumpMapMatrix; }
    void SetBumpMapMatrix(const Matrix22& value) { m_BumpMapMatrix = value; }

    const bool& GetHasNormalTexture() const { return m_HasNormalTexture; }
    bool& GetHasNormalTexture() { return m_HasNormalTexture; }
    void SetHasNormalTexture(const bool& value) { m_HasNormalTexture = value; }

    const TexDesc& GetNormalTexture() const { return m_NormalTexture; }
    TexDesc& GetNormalTexture() { return m_NormalTexture; }
    void SetNormalTexture(const TexDesc& value) { m_NormalTexture = value; }

    const bool& GetHasUnknown2Texture() const { return m_HasUnknown2Texture; }
    bool& GetHasUnknown2Texture() { return m_HasUnknown2Texture; }
    void SetHasUnknown2Texture(const bool& value) { m_HasUnknown2Texture = value; }

    const TexDesc& GetUnknown2Texture() const { return m_Unknown2Texture; }
    TexDesc& GetUnknown2Texture() { return m_Unknown2Texture; }
    void SetUnknown2Texture(const TexDesc& value) { m_Unknown2Texture = value; }

    const float& GetUnknown2Float() const { return m_Unknown2Float; }
    float& GetUnknown2Float() { return m_Unknown2Float; }
    void SetUnknown2Float(const float& value) { m_Unknown2Float = value; }

    const bool& GetHasDecal0Texture() const { return m_HasDecal0Texture; }
    bool& GetHasDecal0Texture() { return m_HasDecal0Texture; }
    void SetHasDecal0Texture(const bool& value) { m_HasDecal0Texture = value; }

    const TexDesc& GetDecal0Texture() const { return m_Decal0Texture; }
    TexDesc& GetDecal0Texture() { return m_Decal0Texture; }
    void SetDecal0Texture(const TexDesc& value) { m_Decal0Texture = value; }

    const bool& GetHasDecal1Texture() const { return m_HasDecal1Texture; }
    bool& GetHasDecal1Texture() { return m_HasDecal1Texture; }
    void SetHasDecal1Texture(const bool& value) { m_HasDecal1Texture = value; }

    const TexDesc& GetDecal1Texture() const { return m_Decal1Texture; }
    TexDesc& GetDecal1Texture() { return m_Decal1Texture; }
    void SetDecal1Texture(const TexDesc& value) { m_Decal1Texture = value; }

    const bool& GetHasDecal2Texture() const { return m_HasDecal2Texture; }
    bool& GetHasDecal2Texture() { return m_HasDecal2Texture; }
    void SetHasDecal2Texture(const bool& value) { m_HasDecal2Texture = value; }

    const TexDesc& GetDecal2Texture() const { return m_Decal2Texture; }
    TexDesc& GetDecal2Texture() { return m_Decal2Texture; }
    void SetDecal2Texture(const TexDesc& value) { m_Decal2Texture = value; }

    const bool& GetHasDecal3Texture() const { return m_HasDecal3Texture; }
    bool& GetHasDecal3Texture() { return m_HasDecal3Texture; }
    void SetHasDecal3Texture(const bool& value) { m_HasDecal3Texture = value; }

    const TexDesc& GetDecal3Texture() const { return m_Decal3Texture; }
    TexDesc& GetDecal3Texture() { return m_Decal3Texture; }
    void SetDecal3Texture(const TexDesc& value) { m_Decal3Texture = value; }

    const uint& GetNumShaderTextures() const { return m_NumShaderTextures; }
    uint& GetNumShaderTextures() { return m_NumShaderTextures; }
    void SetNumShaderTextures(const uint& value) { m_NumShaderTextures = value; }

    const std::vector<ShaderTexDesc>& GetShaderTextures() const { return m_ShaderTextures; }
    std::vector<ShaderTexDesc>& GetShaderTextures() { return m_ShaderTextures; }
    void SetShaderTextures(const std::vector<ShaderTexDesc>& value) { m_ShaderTextures = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
