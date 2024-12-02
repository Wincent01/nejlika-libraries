#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkyrimShaderPropertyFlags1.hpp"
#include "SkyrimShaderPropertyFlags2.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
#include "BSShaderTextureSet.hpp"
#include "Color3.hpp"
#include "TexClampMode.hpp"
#include "Color3.hpp"
#include "Color3.hpp"
#include "Color3.hpp"
#include "TexCoord.hpp"
#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skyrim PP shader for assigning material/shader/texture.
 *         
 */
class BSLightingShaderProperty : public NiProperty
{
protected:
    /**
     * Skyrim Shader Flags for setting render/shader options.
     */
    SkyrimShaderPropertyFlags1 m_ShaderFlags1;
    /**
     * Skyrim Shader Flags for setting render/shader options.
     */
    SkyrimShaderPropertyFlags2 m_ShaderFlags2;
    /**
     * Offset UVs
     */
    TexCoord m_UVOffset;
    /**
     * Offset UV Scale to repeat tiling textures, see above.
     */
    TexCoord m_UVScale;
    /**
     * Texture Set, can have override in an esm/esp
     */
    Pointer<class BSShaderTextureSet*> m_TextureSet;
    /**
     * Glow color and alpha
     */
    Color3 m_EmissiveColor;
    /**
     * Multiplied emissive colors
     */
    float m_EmissiveMultiple;
    /**
     * How to handle texture borders.
     */
    TexClampMode m_TextureClampMode;
    /**
     * The materials opacity (1=non-transparent).
     */
    float m_Alpha;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * The material's specular power, or glossiness (0-999).
     */
    float m_Glossiness;
    /**
     * Adds a colored highlight.
     */
    Color3 m_SpecularColor;
    /**
     * Brightness of specular highlight. (0=not visible) (0-999)
     */
    float m_SpecularStrength;
    /**
     * Controls strength for envmap/backlight/rim/softlight lighting effect?
     */
    float m_LightingEffect1;
    /**
     * Controls strength for envmap/backlight/rim/softlight lighting effect?
     */
    float m_LightingEffect2;
    /**
     * Scales the intensity of the environment/cube map. (0-1)
     */
    float m_EnvironmentMapScale;
    /**
     * Tints the base texture. Overridden by game settings.
     */
    Color3 m_SkinTintColor;
    /**
     * Tints the base texture. Overridden by game settings.
     */
    Color3 m_HairTintColor;
    /**
     * Max Passes
     */
    float m_MaxPasses;
    /**
     * Scale
     */
    float m_Scale;
    /**
     * How far from the surface the inner layer appears to be.
     */
    float m_ParallaxInnerLayerThickness;
    /**
     * Depth of inner parallax layer effect.
     */
    float m_ParallaxRefractionScale;
    /**
     * Scales the inner parallax layer texture.
     */
    TexCoord m_ParallaxInnerLayerTextureScale;
    /**
     * How strong the environment/cube map is. (0-??)
     */
    float m_ParallaxEnvmapStrength;
    /**
     * Unknown/unused?  CK lists "snow material" when used.
     */
    Vector4 m_SparkleParameters;
    /**
     * Eye cubemap scale
     */
    float m_EyeCubemapScale;
    /**
     * Offset to set center for left eye cubemap
     */
    Vector3 m_LeftEyeReflectionCenter;
    /**
     * Offset to set center for right eye cubemap
     */
    Vector3 m_RightEyeReflectionCenter;

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

    const Pointer<class BSShaderTextureSet*>& GetTextureSet() const { return m_TextureSet; }
    Pointer<class BSShaderTextureSet*>& GetTextureSet() { return m_TextureSet; }
    void SetTextureSet(const Pointer<class BSShaderTextureSet*>& value) { m_TextureSet = value; }

    const Color3& GetEmissiveColor() const { return m_EmissiveColor; }
    Color3& GetEmissiveColor() { return m_EmissiveColor; }
    void SetEmissiveColor(const Color3& value) { m_EmissiveColor = value; }

    const float& GetEmissiveMultiple() const { return m_EmissiveMultiple; }
    float& GetEmissiveMultiple() { return m_EmissiveMultiple; }
    void SetEmissiveMultiple(const float& value) { m_EmissiveMultiple = value; }

    const TexClampMode& GetTextureClampMode() const { return m_TextureClampMode; }
    TexClampMode& GetTextureClampMode() { return m_TextureClampMode; }
    void SetTextureClampMode(const TexClampMode& value) { m_TextureClampMode = value; }

    const float& GetAlpha() const { return m_Alpha; }
    float& GetAlpha() { return m_Alpha; }
    void SetAlpha(const float& value) { m_Alpha = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetGlossiness() const { return m_Glossiness; }
    float& GetGlossiness() { return m_Glossiness; }
    void SetGlossiness(const float& value) { m_Glossiness = value; }

    const Color3& GetSpecularColor() const { return m_SpecularColor; }
    Color3& GetSpecularColor() { return m_SpecularColor; }
    void SetSpecularColor(const Color3& value) { m_SpecularColor = value; }

    const float& GetSpecularStrength() const { return m_SpecularStrength; }
    float& GetSpecularStrength() { return m_SpecularStrength; }
    void SetSpecularStrength(const float& value) { m_SpecularStrength = value; }

    const float& GetLightingEffect1() const { return m_LightingEffect1; }
    float& GetLightingEffect1() { return m_LightingEffect1; }
    void SetLightingEffect1(const float& value) { m_LightingEffect1 = value; }

    const float& GetLightingEffect2() const { return m_LightingEffect2; }
    float& GetLightingEffect2() { return m_LightingEffect2; }
    void SetLightingEffect2(const float& value) { m_LightingEffect2 = value; }

    const float& GetEnvironmentMapScale() const { return m_EnvironmentMapScale; }
    float& GetEnvironmentMapScale() { return m_EnvironmentMapScale; }
    void SetEnvironmentMapScale(const float& value) { m_EnvironmentMapScale = value; }

    const Color3& GetSkinTintColor() const { return m_SkinTintColor; }
    Color3& GetSkinTintColor() { return m_SkinTintColor; }
    void SetSkinTintColor(const Color3& value) { m_SkinTintColor = value; }

    const Color3& GetHairTintColor() const { return m_HairTintColor; }
    Color3& GetHairTintColor() { return m_HairTintColor; }
    void SetHairTintColor(const Color3& value) { m_HairTintColor = value; }

    const float& GetMaxPasses() const { return m_MaxPasses; }
    float& GetMaxPasses() { return m_MaxPasses; }
    void SetMaxPasses(const float& value) { m_MaxPasses = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const float& GetParallaxInnerLayerThickness() const { return m_ParallaxInnerLayerThickness; }
    float& GetParallaxInnerLayerThickness() { return m_ParallaxInnerLayerThickness; }
    void SetParallaxInnerLayerThickness(const float& value) { m_ParallaxInnerLayerThickness = value; }

    const float& GetParallaxRefractionScale() const { return m_ParallaxRefractionScale; }
    float& GetParallaxRefractionScale() { return m_ParallaxRefractionScale; }
    void SetParallaxRefractionScale(const float& value) { m_ParallaxRefractionScale = value; }

    const TexCoord& GetParallaxInnerLayerTextureScale() const { return m_ParallaxInnerLayerTextureScale; }
    TexCoord& GetParallaxInnerLayerTextureScale() { return m_ParallaxInnerLayerTextureScale; }
    void SetParallaxInnerLayerTextureScale(const TexCoord& value) { m_ParallaxInnerLayerTextureScale = value; }

    const float& GetParallaxEnvmapStrength() const { return m_ParallaxEnvmapStrength; }
    float& GetParallaxEnvmapStrength() { return m_ParallaxEnvmapStrength; }
    void SetParallaxEnvmapStrength(const float& value) { m_ParallaxEnvmapStrength = value; }

    const Vector4& GetSparkleParameters() const { return m_SparkleParameters; }
    Vector4& GetSparkleParameters() { return m_SparkleParameters; }
    void SetSparkleParameters(const Vector4& value) { m_SparkleParameters = value; }

    const float& GetEyeCubemapScale() const { return m_EyeCubemapScale; }
    float& GetEyeCubemapScale() { return m_EyeCubemapScale; }
    void SetEyeCubemapScale(const float& value) { m_EyeCubemapScale = value; }

    const Vector3& GetLeftEyeReflectionCenter() const { return m_LeftEyeReflectionCenter; }
    Vector3& GetLeftEyeReflectionCenter() { return m_LeftEyeReflectionCenter; }
    void SetLeftEyeReflectionCenter(const Vector3& value) { m_LeftEyeReflectionCenter = value; }

    const Vector3& GetRightEyeReflectionCenter() const { return m_RightEyeReflectionCenter; }
    Vector3& GetRightEyeReflectionCenter() { return m_RightEyeReflectionCenter; }
    void SetRightEyeReflectionCenter(const Vector3& value) { m_RightEyeReflectionCenter = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
