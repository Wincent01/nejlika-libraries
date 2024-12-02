#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSShaderType.hpp"
#include "BSShaderFlags.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific Property node
 *         
 */
class BSShaderProperty : public NiProperty
{
protected:
    /**
     * Unknown
     */
    Flags m_Flags;
    /**
     * Unknown (Set to 0x21 for NoLighting, 0x11 for Water)
     */
    BSShaderType m_ShaderType;
    /**
     * Shader Property Flags
     */
    BSShaderFlags m_ShaderFlags;
    /**
     * Unknown
     */
    int m_UnknownInt2;
    /**
     * Unknown
     */
    float m_EnvmapScale;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const BSShaderType& GetShaderType() const { return m_ShaderType; }
    BSShaderType& GetShaderType() { return m_ShaderType; }
    void SetShaderType(const BSShaderType& value) { m_ShaderType = value; }

    const BSShaderFlags& GetShaderFlags() const { return m_ShaderFlags; }
    BSShaderFlags& GetShaderFlags() { return m_ShaderFlags; }
    void SetShaderFlags(const BSShaderFlags& value) { m_ShaderFlags = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const float& GetEnvmapScale() const { return m_EnvmapScale; }
    float& GetEnvmapScale() { return m_EnvmapScale; }
    void SetEnvmapScale(const float& value) { m_EnvmapScale = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
