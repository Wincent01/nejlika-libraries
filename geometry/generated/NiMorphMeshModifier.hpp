#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ElementReference.hpp"
#include "NiMeshModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Performs linear-weighted blending between a set of target data streams.
 *         
 */
class NiMorphMeshModifier : public NiMeshModifier
{
protected:
    /**
     * 
     *             FLAG_RELATIVETARGETS = 0x01
     *             FLAG_UPDATENORMALS   = 0x02
     *             FLAG_NEEDSUPDATE     = 0x04
     *             FLAG_ALWAYSUPDATE    = 0x08
     *             FLAG_NEEDSCOMPLETION = 0x10
     *             FLAG_SKINNED         = 0x20
     *             FLAG_SWSKINNED       = 0x40
     *         
     */
    byte m_Flags;
    /**
     * The number of morph targets.
     */
    ushort m_NumTargets;
    /**
     * The number of morphing data stream elements.
     */
    uint m_NumElements;
    /**
     * Semantics and normalization of the morphing data stream elements.
     */
    std::vector<ElementReference> m_Elements;

public:
    const byte& GetFlags() const { return m_Flags; }
    byte& GetFlags() { return m_Flags; }
    void SetFlags(const byte& value) { m_Flags = value; }

    const ushort& GetNumTargets() const { return m_NumTargets; }
    ushort& GetNumTargets() { return m_NumTargets; }
    void SetNumTargets(const ushort& value) { m_NumTargets = value; }

    const uint& GetNumElements() const { return m_NumElements; }
    uint& GetNumElements() { return m_NumElements; }
    void SetNumElements(const uint& value) { m_NumElements = value; }

    const std::vector<ElementReference>& GetElements() const { return m_Elements; }
    std::vector<ElementReference>& GetElements() { return m_Elements; }
    void SetElements(const std::vector<ElementReference>& value) { m_Elements = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
