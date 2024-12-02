#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color3.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes... fog?
 *         
 */
class NiFogProperty : public NiProperty
{
protected:
    /**
     * 
     *             1's bit: Enables Fog
     *             2's bit: Sets Fog Function to FOG_RANGE_SQ
     *             4's bit: Sets Fog Function to FOG_VERTEX_ALPHA
     * 
     *             If 2's and 4's bit are not set, but fog is enabled, Fog function is FOG_Z_LINEAR.
     *         
     */
    Flags m_Flags;
    /**
     * The thickness of the fog?  Default is 1.0
     */
    float m_FogDepth;
    /**
     * The color of the fog.
     */
    Color3 m_FogColor;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const float& GetFogDepth() const { return m_FogDepth; }
    float& GetFogDepth() { return m_FogDepth; }
    void SetFogDepth(const float& value) { m_FogDepth = value; }

    const Color3& GetFogColor() const { return m_FogColor; }
    Color3& GetFogColor() { return m_FogColor; }
    void SetFogColor(const Color3& value) { m_FogColor = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
