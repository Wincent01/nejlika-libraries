#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TexType.hpp"
#include "NiSourceTexture.hpp"
#include "NiImage.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Texture flipping controller.
 *         
 */
class NiFlipController : public NiFloatInterpController
{
protected:
    /**
     * Target texture slot (0=base, 4=glow).
     */
    TexType m_TextureSlot;
    /**
     * 0?
     */
    uint m_UnknownInt2;
    /**
     * 
     *             Time between two flips.
     *             delta = (start_time - stop_time) / sources.num_indices
     *         
     */
    float m_Delta;
    /**
     * The number of source objects.
     */
    uint m_NumSources;
    /**
     * The texture sources.
     */
    std::vector<Pointer<class NiSourceTexture*>> m_Sources;
    /**
     * The image sources
     */
    std::vector<Pointer<class NiImage*>> m_Images;

public:
    const TexType& GetTextureSlot() const { return m_TextureSlot; }
    TexType& GetTextureSlot() { return m_TextureSlot; }
    void SetTextureSlot(const TexType& value) { m_TextureSlot = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const float& GetDelta() const { return m_Delta; }
    float& GetDelta() { return m_Delta; }
    void SetDelta(const float& value) { m_Delta = value; }

    const uint& GetNumSources() const { return m_NumSources; }
    uint& GetNumSources() { return m_NumSources; }
    void SetNumSources(const uint& value) { m_NumSources = value; }

    const std::vector<Pointer<class NiSourceTexture*>>& GetSources() const { return m_Sources; }
    std::vector<Pointer<class NiSourceTexture*>>& GetSources() { return m_Sources; }
    void SetSources(const std::vector<Pointer<class NiSourceTexture*>>& value) { m_Sources = value; }

    const std::vector<Pointer<class NiImage*>>& GetImages() const { return m_Images; }
    std::vector<Pointer<class NiImage*>>& GetImages() { return m_Images; }
    void SetImages(const std::vector<Pointer<class NiImage*>>& value) { m_Images = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
