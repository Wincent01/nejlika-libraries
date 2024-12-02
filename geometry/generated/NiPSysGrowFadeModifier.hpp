#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that controls the time it takes to grow a particle from Size=0 to the specified Size in the emitter, and then back to 0.  This modifer has no control over alpha settings.
 *         
 */
class NiPSysGrowFadeModifier : public NiPSysModifier
{
protected:
    /**
     * Time in seconds to fade in.
     */
    float m_GrowTime;
    /**
     * Unknown.
     */
    ushort m_GrowGeneration;
    /**
     * Time in seconds to fade out.
     */
    float m_FadeTime;
    /**
     * Unknown.
     */
    ushort m_FadeGeneration;
    /**
     * Unknown
     */
    float m_BaseScale;

public:
    const float& GetGrowTime() const { return m_GrowTime; }
    float& GetGrowTime() { return m_GrowTime; }
    void SetGrowTime(const float& value) { m_GrowTime = value; }

    const ushort& GetGrowGeneration() const { return m_GrowGeneration; }
    ushort& GetGrowGeneration() { return m_GrowGeneration; }
    void SetGrowGeneration(const ushort& value) { m_GrowGeneration = value; }

    const float& GetFadeTime() const { return m_FadeTime; }
    float& GetFadeTime() { return m_FadeTime; }
    void SetFadeTime(const float& value) { m_FadeTime = value; }

    const ushort& GetFadeGeneration() const { return m_FadeGeneration; }
    ushort& GetFadeGeneration() { return m_FadeGeneration; }
    void SetFadeGeneration(const ushort& value) { m_FadeGeneration = value; }

    const float& GetBaseScale() const { return m_BaseScale; }
    float& GetBaseScale() { return m_BaseScale; }
    void SetBaseScale(const float& value) { m_BaseScale = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
