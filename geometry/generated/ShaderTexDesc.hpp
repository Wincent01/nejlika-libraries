#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TexDesc.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An extended texture description for shader textures.
 *         
 */
class ShaderTexDesc : public Construct
{
protected:
    /**
     * Is it used?
     */
    bool m_IsUsed;
    /**
     * The texture data.
     */
    TexDesc m_TextureData;
    /**
     * Map Index
     */
    uint m_MapIndex;

public:
    const bool& GetIsUsed() const { return m_IsUsed; }
    bool& GetIsUsed() { return m_IsUsed; }
    void SetIsUsed(const bool& value) { m_IsUsed = value; }

    const TexDesc& GetTextureData() const { return m_TextureData; }
    TexDesc& GetTextureData() { return m_TextureData; }
    void SetTextureData(const TexDesc& value) { m_TextureData = value; }

    const uint& GetMapIndex() const { return m_MapIndex; }
    uint& GetMapIndex() { return m_MapIndex; }
    void SetMapIndex(const uint& value) { m_MapIndex = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
