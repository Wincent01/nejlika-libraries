#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSShaderTextureSet.hpp"
#include "Color4.hpp"
#include "BSShaderLightingProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific Shade node.
 *         
 */
class BSShaderPPLightingProperty : public BSShaderLightingProperty
{
protected:
    /**
     * Texture Set
     */
    Pointer<class BSShaderTextureSet*> m_TextureSet;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Rate of texture movement for refraction shader.
     */
    int m_RefractionPeriod;
    /**
     * Unknown
     */
    float m_UnknownFloat4;
    /**
     * Unknown
     */
    float m_UnknownFloat5;
    /**
     * Glow color and alpha
     */
    Color4 m_EmissiveColor;

public:
    const Pointer<class BSShaderTextureSet*>& GetTextureSet() const { return m_TextureSet; }
    Pointer<class BSShaderTextureSet*>& GetTextureSet() { return m_TextureSet; }
    void SetTextureSet(const Pointer<class BSShaderTextureSet*>& value) { m_TextureSet = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const int& GetRefractionPeriod() const { return m_RefractionPeriod; }
    int& GetRefractionPeriod() { return m_RefractionPeriod; }
    void SetRefractionPeriod(const int& value) { m_RefractionPeriod = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const float& GetUnknownFloat5() const { return m_UnknownFloat5; }
    float& GetUnknownFloat5() { return m_UnknownFloat5; }
    void SetUnknownFloat5(const float& value) { m_UnknownFloat5 = value; }

    const Color4& GetEmissiveColor() const { return m_EmissiveColor; }
    Color4& GetEmissiveColor() { return m_EmissiveColor; }
    void SetEmissiveColor(const Color4& value) { m_EmissiveColor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
