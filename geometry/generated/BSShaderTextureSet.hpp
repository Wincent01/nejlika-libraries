#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific Texture Set.
 *         
 */
class BSShaderTextureSet : public NiObject
{
protected:
    /**
     * Number of Textures
     */
    int m_NumTextures;
    /**
     * Textures.
     *             0: Diffuse
     *             1: Normal/Gloss
     *             2: Glow(SLSF2_Glow_Map)/Skin/Hair/Rim light(SLSF2_Rim_Lighting)
     *             3: Height/Parallax
     *             4: Environment
     *             5: Environment Mask
     *             6: Subsurface for Multilayer Parallax
     *             7: Back Lighting Map (SLSF2_Back_Lighting)
     *         
     */
    std::vector<SizedString> m_Textures;

public:
    const int& GetNumTextures() const { return m_NumTextures; }
    int& GetNumTextures() { return m_NumTextures; }
    void SetNumTextures(const int& value) { m_NumTextures = value; }

    const std::vector<SizedString>& GetTextures() const { return m_Textures; }
    std::vector<SizedString>& GetTextures() { return m_Textures; }
    void SetTextures(const std::vector<SizedString>& value) { m_Textures = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
