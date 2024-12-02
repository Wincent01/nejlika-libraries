#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkyrimShaderPropertyFlags1.hpp"
#include "SkyrimShaderPropertyFlags2.hpp"
#include "TexCoord.hpp"
#include "TexCoord.hpp"
#include "SizedString.hpp"
#include "SkyObjectType.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skyrim Sky shader block.
 *         
 */
class BSSkyShaderProperty : public NiProperty
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
     * points to an external texture.
     */
    SizedString m_SourceTexture;
    /**
     * Sky Object Type
     */
    SkyObjectType m_SkyObjectType;

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

    const SizedString& GetSourceTexture() const { return m_SourceTexture; }
    SizedString& GetSourceTexture() { return m_SourceTexture; }
    void SetSourceTexture(const SizedString& value) { m_SourceTexture = value; }

    const SkyObjectType& GetSkyObjectType() const { return m_SkyObjectType; }
    SkyObjectType& GetSkyObjectType() { return m_SkyObjectType; }
    void SetSkyObjectType(const SkyObjectType& value) { m_SkyObjectType = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
