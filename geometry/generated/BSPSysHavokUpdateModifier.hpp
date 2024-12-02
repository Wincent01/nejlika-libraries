#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiPSysModifier.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


class BSPSysHavokUpdateModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown
     */
    uint m_NumNodes;
    /**
     * Group of target NiNodes?
     */
    std::vector<Pointer<class NiNode*>> m_Nodes;
    /**
     * Unknown
     */
    Pointer<class NiPSysModifier*> m_Modifier;

public:
    const uint& GetNumNodes() const { return m_NumNodes; }
    uint& GetNumNodes() { return m_NumNodes; }
    void SetNumNodes(const uint& value) { m_NumNodes = value; }

    const std::vector<Pointer<class NiNode*>>& GetNodes() const { return m_Nodes; }
    std::vector<Pointer<class NiNode*>>& GetNodes() { return m_Nodes; }
    void SetNodes(const std::vector<Pointer<class NiNode*>>& value) { m_Nodes = value; }

    const Pointer<class NiPSysModifier*>& GetModifier() const { return m_Modifier; }
    Pointer<class NiPSysModifier*>& GetModifier() { return m_Modifier; }
    void SetModifier(const Pointer<class NiPSysModifier*>& value) { m_Modifier = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
