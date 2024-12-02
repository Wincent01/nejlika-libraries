#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ParticleDesc.hpp"
#include "Vector4.hpp"
#include "NiRotatingParticlesData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system data.
 *         
 */
class NiPSysData : public NiRotatingParticlesData
{
protected:
    /**
     * Unknown.
     */
    std::vector<ParticleDesc> m_ParticleDescriptions;
    /**
     * Unknown.
     */
    bool m_HasUnknownFloats3;
    /**
     * Unknown.
     */
    std::vector<float> m_UnknownFloats3;
    /**
     * Unknown.
     */
    ushort m_UnknownShort1;
    /**
     * Unknown.
     */
    ushort m_UnknownShort2;
    /**
     * Boolean for Num Subtexture Offset UVs
     */
    bool m_HasSubtextureOffsetUVs;
    /**
     * How many quads to use in BSPSysSubTexModifier for texture atlasing
     */
    uint m_NumSubtextureOffsetUVs;
    /**
     * Sets aspect ratio for Subtexture Offset UV quads
     */
    float m_AspectRatio;
    /**
     * Defines UV offsets
     */
    std::vector<Vector4> m_SubtextureOffsetUVs;
    /**
     * Unknown
     */
    uint m_UnknownInt4;
    /**
     * Unknown
     */
    uint m_UnknownInt5;
    /**
     * Unknown
     */
    uint m_UnknownInt6;
    /**
     * Unknown
     */
    ushort m_UnknownShort3;
    /**
     * Unknown
     */
    byte m_UnknownByte4;

public:
    const std::vector<ParticleDesc>& GetParticleDescriptions() const { return m_ParticleDescriptions; }
    std::vector<ParticleDesc>& GetParticleDescriptions() { return m_ParticleDescriptions; }
    void SetParticleDescriptions(const std::vector<ParticleDesc>& value) { m_ParticleDescriptions = value; }

    const bool& GetHasUnknownFloats3() const { return m_HasUnknownFloats3; }
    bool& GetHasUnknownFloats3() { return m_HasUnknownFloats3; }
    void SetHasUnknownFloats3(const bool& value) { m_HasUnknownFloats3 = value; }

    const std::vector<float>& GetUnknownFloats3() const { return m_UnknownFloats3; }
    std::vector<float>& GetUnknownFloats3() { return m_UnknownFloats3; }
    void SetUnknownFloats3(const std::vector<float>& value) { m_UnknownFloats3 = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const bool& GetHasSubtextureOffsetUVs() const { return m_HasSubtextureOffsetUVs; }
    bool& GetHasSubtextureOffsetUVs() { return m_HasSubtextureOffsetUVs; }
    void SetHasSubtextureOffsetUVs(const bool& value) { m_HasSubtextureOffsetUVs = value; }

    const uint& GetNumSubtextureOffsetUVs() const { return m_NumSubtextureOffsetUVs; }
    uint& GetNumSubtextureOffsetUVs() { return m_NumSubtextureOffsetUVs; }
    void SetNumSubtextureOffsetUVs(const uint& value) { m_NumSubtextureOffsetUVs = value; }

    const float& GetAspectRatio() const { return m_AspectRatio; }
    float& GetAspectRatio() { return m_AspectRatio; }
    void SetAspectRatio(const float& value) { m_AspectRatio = value; }

    const std::vector<Vector4>& GetSubtextureOffsetUVs() const { return m_SubtextureOffsetUVs; }
    std::vector<Vector4>& GetSubtextureOffsetUVs() { return m_SubtextureOffsetUVs; }
    void SetSubtextureOffsetUVs(const std::vector<Vector4>& value) { m_SubtextureOffsetUVs = value; }

    const uint& GetUnknownInt4() const { return m_UnknownInt4; }
    uint& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const uint& value) { m_UnknownInt4 = value; }

    const uint& GetUnknownInt5() const { return m_UnknownInt5; }
    uint& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const uint& value) { m_UnknownInt5 = value; }

    const uint& GetUnknownInt6() const { return m_UnknownInt6; }
    uint& GetUnknownInt6() { return m_UnknownInt6; }
    void SetUnknownInt6(const uint& value) { m_UnknownInt6 = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }

    const byte& GetUnknownByte4() const { return m_UnknownByte4; }
    byte& GetUnknownByte4() { return m_UnknownByte4; }
    void SetUnknownByte4(const byte& value) { m_UnknownByte4 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
