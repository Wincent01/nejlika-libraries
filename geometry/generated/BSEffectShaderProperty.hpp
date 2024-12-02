#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkyrimShaderPropertyFlags1.hpp"
#include "SkyrimShaderPropertyFlags2.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
#include "SizedString.hpp"
#include "Color4.hpp"
#include "SizedString.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skyrim non-PP shader model, used primarily for transparency effects, often as decal.
 *         
 */
class BSEffectShaderProperty : public NiProperty
{
protected:
    SkyrimShaderPropertyFlags1 m_ShaderFlags1;
    SkyrimShaderPropertyFlags2 m_ShaderFlags2;
    /**
     * Offset UVs
     */
    TexCoord m_UVOffset;
    /**
     * Offset UV Scale to repeat tiling textures
     */
    TexCoord m_UVScale;
    /**
     * points to an external texture.
     */
    SizedString m_SourceTexture;
    /**
     * How to handle texture borders.
     */
    uint m_TextureClampMode;
    /**
     * At this cosine of angle falloff will be equal to Falloff Start Opacity
     */
    float m_FalloffStartAngle;
    /**
     * At this cosine of angle falloff will be equal to Falloff Stop Opacity
     */
    float m_FalloffStopAngle;
    /**
     * Alpha falloff multiplier at start angle
     */
    float m_FalloffStartOpacity;
    /**
     * Alpha falloff multiplier at end angle
     */
    float m_FalloffStopOpacity;
    /**
     * Emissive color
     */
    Color4 m_EmissiveColor;
    /**
     * Multiplier for Emissive Color (RGB part)
     */
    float m_EmissiveMultiple;
    float m_SoftFalloffDepth;
    /**
     * Points to an external texture, used as palette for SLSF1_Greyscale_To_PaletteColor/SLSF1_Greyscale_To_PaletteAlpha.
     */
    SizedString m_GreyscaleTexture;

public:
    const SkyrimShaderPropertyFlags1& GetShaderFlags1() const { return m_ShaderFlags1; }
    SkyrimShaderPropertyFlags1& GetShaderFlags1() { return m_ShaderFlags1; }
    void SetShaderFlags1(const SkyrimShaderPropertyFlags1& value) { m_ShaderFlags1 = value; }

    const SkyrimShaderPropertyFlags2& GetShaderFlags2() const { return m_ShaderFlags2; }
    SkyrimShaderPropertyFlags2& GetShaderFlags2() { return m_ShaderFlags2; }
    void SetShaderFlags2(const SkyrimShaderPropertyFlags2& value) { m_ShaderFlags2 = value; }

    const TexCoord& GetUVOffset() const { return m_UVOffset; }
    TexCoord& GetUVOffset() { return m_UVOffset; }
    void SetUVOffset(const TexCoord& value) { m_UVOffset = value; }

    const TexCoord& GetUVScale() const { return m_UVScale; }
    TexCoord& GetUVScale() { return m_UVScale; }
    void SetUVScale(const TexCoord& value) { m_UVScale = value; }

    const SizedString& GetSourceTexture() const { return m_SourceTexture; }
    SizedString& GetSourceTexture() { return m_SourceTexture; }
    void SetSourceTexture(const SizedString& value) { m_SourceTexture = value; }

    const uint& GetTextureClampMode() const { return m_TextureClampMode; }
    uint& GetTextureClampMode() { return m_TextureClampMode; }
    void SetTextureClampMode(const uint& value) { m_TextureClampMode = value; }

    const float& GetFalloffStartAngle() const { return m_FalloffStartAngle; }
    float& GetFalloffStartAngle() { return m_FalloffStartAngle; }
    void SetFalloffStartAngle(const float& value) { m_FalloffStartAngle = value; }

    const float& GetFalloffStopAngle() const { return m_FalloffStopAngle; }
    float& GetFalloffStopAngle() { return m_FalloffStopAngle; }
    void SetFalloffStopAngle(const float& value) { m_FalloffStopAngle = value; }

    const float& GetFalloffStartOpacity() const { return m_FalloffStartOpacity; }
    float& GetFalloffStartOpacity() { return m_FalloffStartOpacity; }
    void SetFalloffStartOpacity(const float& value) { m_FalloffStartOpacity = value; }

    const float& GetFalloffStopOpacity() const { return m_FalloffStopOpacity; }
    float& GetFalloffStopOpacity() { return m_FalloffStopOpacity; }
    void SetFalloffStopOpacity(const float& value) { m_FalloffStopOpacity = value; }

    const Color4& GetEmissiveColor() const { return m_EmissiveColor; }
    Color4& GetEmissiveColor() { return m_EmissiveColor; }
    void SetEmissiveColor(const Color4& value) { m_EmissiveColor = value; }

    const float& GetEmissiveMultiple() const { return m_EmissiveMultiple; }
    float& GetEmissiveMultiple() { return m_EmissiveMultiple; }
    void SetEmissiveMultiple(const float& value) { m_EmissiveMultiple = value; }

    const float& GetSoftFalloffDepth() const { return m_SoftFalloffDepth; }
    float& GetSoftFalloffDepth() { return m_SoftFalloffDepth; }
    void SetSoftFalloffDepth(const float& value) { m_SoftFalloffDepth = value; }

    const SizedString& GetGreyscaleTexture() const { return m_GreyscaleTexture; }
    SizedString& GetGreyscaleTexture() { return m_GreyscaleTexture; }
    void SetGreyscaleTexture(const SizedString& value) { m_GreyscaleTexture = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
