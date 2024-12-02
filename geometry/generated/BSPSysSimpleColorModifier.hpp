#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color4.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific Particle node.
 *         
 */
class BSPSysSimpleColorModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown
     */
    float m_FadeInPercent;
    /**
     * Unknown
     */
    float m_FadeOutPercent;
    /**
     * Unknown
     */
    float m_Color1EndPercent;
    /**
     * Unknown
     */
    float m_Color1StartPercent;
    /**
     * Unknown
     */
    float m_Color2EndPercent;
    /**
     * Unknown
     */
    float m_Color2StartPercent;
    /**
     * Colors
     */
    std::vector<Color4> m_Colors;

public:
    const float& GetFadeInPercent() const { return m_FadeInPercent; }
    float& GetFadeInPercent() { return m_FadeInPercent; }
    void SetFadeInPercent(const float& value) { m_FadeInPercent = value; }

    const float& GetFadeOutPercent() const { return m_FadeOutPercent; }
    float& GetFadeOutPercent() { return m_FadeOutPercent; }
    void SetFadeOutPercent(const float& value) { m_FadeOutPercent = value; }

    const float& GetColor1EndPercent() const { return m_Color1EndPercent; }
    float& GetColor1EndPercent() { return m_Color1EndPercent; }
    void SetColor1EndPercent(const float& value) { m_Color1EndPercent = value; }

    const float& GetColor1StartPercent() const { return m_Color1StartPercent; }
    float& GetColor1StartPercent() { return m_Color1StartPercent; }
    void SetColor1StartPercent(const float& value) { m_Color1StartPercent = value; }

    const float& GetColor2EndPercent() const { return m_Color2EndPercent; }
    float& GetColor2EndPercent() { return m_Color2EndPercent; }
    void SetColor2EndPercent(const float& value) { m_Color2EndPercent = value; }

    const float& GetColor2StartPercent() const { return m_Color2StartPercent; }
    float& GetColor2StartPercent() { return m_Color2StartPercent; }
    void SetColor2StartPercent(const float& value) { m_Color2StartPercent = value; }

    const std::vector<Color4>& GetColors() const { return m_Colors; }
    std::vector<Color4>& GetColors() { return m_Colors; }
    void SetColors(const std::vector<Color4>& value) { m_Colors = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
