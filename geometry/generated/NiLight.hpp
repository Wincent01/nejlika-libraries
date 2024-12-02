#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color3.hpp"
#include "Color3.hpp"
#include "Color3.hpp"
#include "NiDynamicEffect.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Light source.
 *         
 */
class NiLight : public NiDynamicEffect
{
protected:
    /**
     * Dimmer.
     */
    float m_Dimmer;
    /**
     * Ambient color.
     */
    Color3 m_AmbientColor;
    /**
     * Diffuse color.
     */
    Color3 m_DiffuseColor;
    /**
     * Specular color.
     */
    Color3 m_SpecularColor;

public:
    const float& GetDimmer() const { return m_Dimmer; }
    float& GetDimmer() { return m_Dimmer; }
    void SetDimmer(const float& value) { m_Dimmer = value; }

    const Color3& GetAmbientColor() const { return m_AmbientColor; }
    Color3& GetAmbientColor() { return m_AmbientColor; }
    void SetAmbientColor(const Color3& value) { m_AmbientColor = value; }

    const Color3& GetDiffuseColor() const { return m_DiffuseColor; }
    Color3& GetDiffuseColor() { return m_DiffuseColor; }
    void SetDiffuseColor(const Color3& value) { m_DiffuseColor = value; }

    const Color3& GetSpecularColor() const { return m_SpecularColor; }
    Color3& GetSpecularColor() { return m_SpecularColor; }
    void SetSpecularColor(const Color3& value) { m_SpecularColor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
