#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Similar to a Flip Controller, this handles particle texture animation on a single texture atlas
 *         
 */
class BSPSysSubTexModifier : public NiPSysModifier
{
protected:
    /**
     * Starting frame/position on atlas
     */
    uint m_StartFrame;
    /**
     * Random chance to start on a different frame?
     */
    float m_StartFrameFudge;
    /**
     * Ending frame/position on atlas
     */
    float m_EndFrame;
    /**
     * Frame to start looping
     */
    float m_LoopStartFrame;
    float m_LoopStartFrameFudge;
    /**
     * Unknown
     */
    float m_FrameCount;
    /**
     * Unknown
     */
    float m_FrameCountFudge;

public:
    const uint& GetStartFrame() const { return m_StartFrame; }
    uint& GetStartFrame() { return m_StartFrame; }
    void SetStartFrame(const uint& value) { m_StartFrame = value; }

    const float& GetStartFrameFudge() const { return m_StartFrameFudge; }
    float& GetStartFrameFudge() { return m_StartFrameFudge; }
    void SetStartFrameFudge(const float& value) { m_StartFrameFudge = value; }

    const float& GetEndFrame() const { return m_EndFrame; }
    float& GetEndFrame() { return m_EndFrame; }
    void SetEndFrame(const float& value) { m_EndFrame = value; }

    const float& GetLoopStartFrame() const { return m_LoopStartFrame; }
    float& GetLoopStartFrame() { return m_LoopStartFrame; }
    void SetLoopStartFrame(const float& value) { m_LoopStartFrame = value; }

    const float& GetLoopStartFrameFudge() const { return m_LoopStartFrameFudge; }
    float& GetLoopStartFrameFudge() { return m_LoopStartFrameFudge; }
    void SetLoopStartFrameFudge(const float& value) { m_LoopStartFrameFudge = value; }

    const float& GetFrameCount() const { return m_FrameCount; }
    float& GetFrameCount() { return m_FrameCount; }
    void SetFrameCount(const float& value) { m_FrameCount = value; }

    const float& GetFrameCountFudge() const { return m_FrameCountFudge; }
    float& GetFrameCountFudge() { return m_FrameCountFudge; }
    void SetFrameCountFudge(const float& value) { m_FrameCountFudge = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
