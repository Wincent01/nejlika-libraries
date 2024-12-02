#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A group of NiNodes references.
 *         
 */
class NodeGroup : public Construct
{
protected:
    /**
     * Number of node references that follow.
     */
    uint m_NumNodes;
    /**
     * The list of NiNode references.
     */
    std::vector<Pointer<class NiNode*>> m_Nodes;

public:
    const uint& GetNumNodes() const { return m_NumNodes; }
    uint& GetNumNodes() { return m_NumNodes; }
    void SetNumNodes(const uint& value) { m_NumNodes = value; }

    const std::vector<Pointer<class NiNode*>>& GetNodes() const { return m_Nodes; }
    std::vector<Pointer<class NiNode*>>& GetNodes() { return m_Nodes; }
    void SetNodes(const std::vector<Pointer<class NiNode*>>& value) { m_Nodes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
