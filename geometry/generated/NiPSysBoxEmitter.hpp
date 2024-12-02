#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysVolumeEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle emitter that uses points within a defined Box shape to emit from..
 *         
 */
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
protected:
    /**
     * Defines the Width of the box area.
     */
    float m_Width;
    /**
     * Defines the Height of the box area.
     */
    float m_Height;
    /**
     * Defines the Depth of the box area.
     */
    float m_Depth;

public:
    const float& GetWidth() const { return m_Width; }
    float& GetWidth() { return m_Width; }
    void SetWidth(const float& value) { m_Width = value; }

    const float& GetHeight() const { return m_Height; }
    float& GetHeight() { return m_Height; }
    void SetHeight(const float& value) { m_Height = value; }

    const float& GetDepth() const { return m_Depth; }
    float& GetDepth() { return m_Depth; }
    void SetDepth(const float& value) { m_Depth = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
