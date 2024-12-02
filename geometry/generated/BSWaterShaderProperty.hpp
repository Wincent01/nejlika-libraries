#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkyrimShaderPropertyFlags1.hpp"
#include "SkyrimShaderPropertyFlags2.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
#include "SkyrimWaterShaderFlags.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skyrim water shader property, different from "WaterShaderProperty" seen in Fallout.
 *         
 */
class BSWaterShaderProperty : public NiProperty
{
protected:
    SkyrimShaderPropertyFlags1 m_ShaderFlags1;
    SkyrimShaderPropertyFlags2 m_ShaderFlags2;
    /**
     * Offset UVs. Seems to be unused, but it fits with the other Skyrim shader properties.
     */
    TexCoord m_UVOffset;
    /**
     * Offset UV Scale to repeat tiling textures, see above.
     */
    TexCoord m_UVScale;
    /**
     * Defines attributes for the water shader (will use SkyrimWaterShaderFlags)
     */
    SkyrimWaterShaderFlags m_WaterShaderFlags;
    /**
     * A bitflag, only the first/second bit controls water flow positive or negative along UVs.
     */
    byte m_WaterDirection;
    /**
     * Unknown, flag?
     */
    ushort m_UnknownShort3;

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

    const SkyrimWaterShaderFlags& GetWaterShaderFlags() const { return m_WaterShaderFlags; }
    SkyrimWaterShaderFlags& GetWaterShaderFlags() { return m_WaterShaderFlags; }
    void SetWaterShaderFlags(const SkyrimWaterShaderFlags& value) { m_WaterShaderFlags = value; }

    const byte& GetWaterDirection() const { return m_WaterDirection; }
    byte& GetWaterDirection() { return m_WaterDirection; }
    void SetWaterDirection(const byte& value) { m_WaterDirection = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
