#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiNode.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Node for handling Trees, Switches branch configurations for variation?
 *         
 */
class BSTreeNode : public NiNode
{
protected:
    /**
     * Unknown
     */
    uint m_NumBones1;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiNode*>> m_Bones1;
    /**
     * Unknown
     */
    uint m_NumBones2;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiNode*>> m_Bones;

public:
    const uint& GetNumBones1() const { return m_NumBones1; }
    uint& GetNumBones1() { return m_NumBones1; }
    void SetNumBones1(const uint& value) { m_NumBones1 = value; }

    const std::vector<Pointer<class NiNode*>>& GetBones1() const { return m_Bones1; }
    std::vector<Pointer<class NiNode*>>& GetBones1() { return m_Bones1; }
    void SetBones1(const std::vector<Pointer<class NiNode*>>& value) { m_Bones1 = value; }

    const uint& GetNumBones2() const { return m_NumBones2; }
    uint& GetNumBones2() { return m_NumBones2; }
    void SetNumBones2(const uint& value) { m_NumBones2 = value; }

    const std::vector<Pointer<class NiNode*>>& GetBones() const { return m_Bones; }
    std::vector<Pointer<class NiNode*>>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<Pointer<class NiNode*>>& value) { m_Bones = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
