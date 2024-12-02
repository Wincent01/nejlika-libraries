#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiSkinData.hpp"
#include "NiSkinPartition.hpp"
#include "NiNode.hpp"
#include "NiNode.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skinning instance.
 *         
 */
class NiSkinInstance : public NiObject
{
protected:
    /**
     * Skinning data reference.
     */
    Pointer<class NiSkinData*> m_Data;
    /**
     * Refers to a NiSkinPartition objects, which partitions the mesh such that every vertex is only influenced by a limited number of bones.
     */
    Pointer<class NiSkinPartition*> m_SkinPartition;
    /**
     * Armature root node.
     */
    Pointer<class NiNode*> m_SkeletonRoot;
    /**
     * The number of node bones referenced as influences.
     */
    uint m_NumBones;
    /**
     * List of all armature bones.
     */
    std::vector<Pointer<class NiNode*>> m_Bones;

public:
    const Pointer<class NiSkinData*>& GetData() const { return m_Data; }
    Pointer<class NiSkinData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiSkinData*>& value) { m_Data = value; }

    const Pointer<class NiSkinPartition*>& GetSkinPartition() const { return m_SkinPartition; }
    Pointer<class NiSkinPartition*>& GetSkinPartition() { return m_SkinPartition; }
    void SetSkinPartition(const Pointer<class NiSkinPartition*>& value) { m_SkinPartition = value; }

    const Pointer<class NiNode*>& GetSkeletonRoot() const { return m_SkeletonRoot; }
    Pointer<class NiNode*>& GetSkeletonRoot() { return m_SkeletonRoot; }
    void SetSkeletonRoot(const Pointer<class NiNode*>& value) { m_SkeletonRoot = value; }

    const uint& GetNumBones() const { return m_NumBones; }
    uint& GetNumBones() { return m_NumBones; }
    void SetNumBones(const uint& value) { m_NumBones = value; }

    const std::vector<Pointer<class NiNode*>>& GetBones() const { return m_Bones; }
    std::vector<Pointer<class NiNode*>>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<Pointer<class NiNode*>>& value) { m_Bones = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
