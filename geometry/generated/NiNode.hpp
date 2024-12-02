#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiDynamicEffect.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Generic node object for grouping.
 *         
 */
class NiNode : public NiAVObject
{
protected:
    /**
     * The number of child objects.
     */
    uint m_NumChildren;
    /**
     * List of child node object indices.
     */
    std::vector<Pointer<class NiAVObject*>> m_Children;
    /**
     * The number of references to effect objects that follow.
     */
    uint m_NumEffects;
    /**
     * List of node effects. ADynamicEffect?
     */
    std::vector<Pointer<class NiDynamicEffect*>> m_Effects;

public:
    const uint& GetNumChildren() const { return m_NumChildren; }
    uint& GetNumChildren() { return m_NumChildren; }
    void SetNumChildren(const uint& value) { m_NumChildren = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetChildren() const { return m_Children; }
    std::vector<Pointer<class NiAVObject*>>& GetChildren() { return m_Children; }
    void SetChildren(const std::vector<Pointer<class NiAVObject*>>& value) { m_Children = value; }

    const uint& GetNumEffects() const { return m_NumEffects; }
    uint& GetNumEffects() { return m_NumEffects; }
    void SetNumEffects(const uint& value) { m_NumEffects = value; }

    const std::vector<Pointer<class NiDynamicEffect*>>& GetEffects() const { return m_Effects; }
    std::vector<Pointer<class NiDynamicEffect*>>& GetEffects() { return m_Effects; }
    void SetEffects(const std::vector<Pointer<class NiDynamicEffect*>>& value) { m_Effects = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
