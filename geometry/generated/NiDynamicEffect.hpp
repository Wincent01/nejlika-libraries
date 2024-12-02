#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A dynamic effect such as a light or environment map.
 *         
 */
class NiDynamicEffect : public NiAVObject
{
protected:
    /**
     * Turns effect on and off?  Switches list to list of unaffected nodes?
     */
    bool m_SwitchState;
    /**
     * The number of affected nodes referenced.
     */
    uint m_NumAffectedNodeListPointers;
    /**
     * The number of affected nodes referenced.
     */
    uint m_NumAffectedNodes;
    /**
     * This is probably the list of affected nodes. For some reason i do not know the max exporter seems to write pointers instead of links. But it doesn't matter because at least in version 4.0.0.2 the list is automagically updated by the engine during the load stage.
     */
    std::vector<uint> m_AffectedNodeListPointers;
    /**
     * The list of affected nodes?
     */
    std::vector<Pointer<class NiAVObject*>> m_AffectedNodes;

public:
    const bool& GetSwitchState() const { return m_SwitchState; }
    bool& GetSwitchState() { return m_SwitchState; }
    void SetSwitchState(const bool& value) { m_SwitchState = value; }

    const uint& GetNumAffectedNodeListPointers() const { return m_NumAffectedNodeListPointers; }
    uint& GetNumAffectedNodeListPointers() { return m_NumAffectedNodeListPointers; }
    void SetNumAffectedNodeListPointers(const uint& value) { m_NumAffectedNodeListPointers = value; }

    const uint& GetNumAffectedNodes() const { return m_NumAffectedNodes; }
    uint& GetNumAffectedNodes() { return m_NumAffectedNodes; }
    void SetNumAffectedNodes(const uint& value) { m_NumAffectedNodes = value; }

    const std::vector<uint>& GetAffectedNodeListPointers() const { return m_AffectedNodeListPointers; }
    std::vector<uint>& GetAffectedNodeListPointers() { return m_AffectedNodeListPointers; }
    void SetAffectedNodeListPointers(const std::vector<uint>& value) { m_AffectedNodeListPointers = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetAffectedNodes() const { return m_AffectedNodes; }
    std::vector<Pointer<class NiAVObject*>>& GetAffectedNodes() { return m_AffectedNodes; }
    void SetAffectedNodes(const std::vector<Pointer<class NiAVObject*>>& value) { m_AffectedNodes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
