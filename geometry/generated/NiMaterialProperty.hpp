#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color3.hpp"
#include "Color3.hpp"
#include "Color3.hpp"
#include "Color3.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes the material shading properties.
 *         
 */
class NiMaterialProperty : public NiProperty
{
protected:
    /**
     * Property flags.
     */
    Flags m_Flags;
    /**
     * How much the material reflects ambient light.
     */
    Color3 m_AmbientColor;
    /**
     * How much the material reflects diffuse light.
     */
    Color3 m_DiffuseColor;
    /**
     * How much light the material reflects in a specular manner.
     */
    Color3 m_SpecularColor;
    /**
     * How much light the material emits.
     */
    Color3 m_EmissiveColor;
    /**
     * The material's glossiness.
     */
    float m_Glossiness;
    /**
     * The material transparency (1=non-transparant). Refer to a NiAlphaProperty object in this material's parent NiTriShape object, when alpha is not 1.
     */
    float m_Alpha;
    /**
     * Unknown
     */
    float m_EmitMulti;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const Color3& GetAmbientColor() const { return m_AmbientColor; }
    Color3& GetAmbientColor() { return m_AmbientColor; }
    void SetAmbientColor(const Color3& value) { m_AmbientColor = value; }

    const Color3& GetDiffuseColor() const { return m_DiffuseColor; }
    Color3& GetDiffuseColor() { return m_DiffuseColor; }
    void SetDiffuseColor(const Color3& value) { m_DiffuseColor = value; }

    const Color3& GetSpecularColor() const { return m_SpecularColor; }
    Color3& GetSpecularColor() { return m_SpecularColor; }
    void SetSpecularColor(const Color3& value) { m_SpecularColor = value; }

    const Color3& GetEmissiveColor() const { return m_EmissiveColor; }
    Color3& GetEmissiveColor() { return m_EmissiveColor; }
    void SetEmissiveColor(const Color3& value) { m_EmissiveColor = value; }

    const float& GetGlossiness() const { return m_Glossiness; }
    float& GetGlossiness() { return m_Glossiness; }
    void SetGlossiness(const float& value) { m_Glossiness = value; }

    const float& GetAlpha() const { return m_Alpha; }
    float& GetAlpha() { return m_Alpha; }
    void SetAlpha(const float& value) { m_Alpha = value; }

    const float& GetEmitMulti() const { return m_EmitMulti; }
    float& GetEmitMulti() { return m_EmitMulti; }
    void SetEmitMulti(const float& value) { m_EmitMulti = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
