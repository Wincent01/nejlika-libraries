#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "SkinTransform.hpp"
#include "NiAVObject.hpp"
#include "SkinTransform.hpp"
#include "SphereBV.hpp"
#include "NiMeshModifier.hpp"
namespace nejlika::geometry {


class NiSkinningMeshModifier : public NiMeshModifier
{
protected:
    /**
     * 
     *             USE_SOFTWARE_SKINNING = 0x0001
     *             RECOMPUTE_BOUNDS = 0x0002
     *         
     */
    ushort m_Flags;
    /**
     * The root bone of the skeleton.
     */
    Pointer<class NiAVObject*> m_SkeletonRoot;
    /**
     * The transform that takes the root bone parent coordinate system into the skin coordinate system.
     */
    SkinTransform m_SkeletonTransform;
    /**
     * The number of bones referenced by this mesh modifier.
     */
    uint m_NumBones;
    /**
     * Pointers to the bone nodes that affect this skin.
     */
    std::vector<Pointer<class NiAVObject*>> m_Bones;
    /**
     * The transforms that go from bind-pose space to bone space.
     */
    std::vector<SkinTransform> m_BoneTransforms;
    /**
     * The bounds of the bones.  Only stored if the RECOMPUTE_BOUNDS bit is set.
     */
    std::vector<SphereBV> m_BoneBounds;

public:
    const ushort& GetFlags() const { return m_Flags; }
    ushort& GetFlags() { return m_Flags; }
    void SetFlags(const ushort& value) { m_Flags = value; }

    const Pointer<class NiAVObject*>& GetSkeletonRoot() const { return m_SkeletonRoot; }
    Pointer<class NiAVObject*>& GetSkeletonRoot() { return m_SkeletonRoot; }
    void SetSkeletonRoot(const Pointer<class NiAVObject*>& value) { m_SkeletonRoot = value; }

    const SkinTransform& GetSkeletonTransform() const { return m_SkeletonTransform; }
    SkinTransform& GetSkeletonTransform() { return m_SkeletonTransform; }
    void SetSkeletonTransform(const SkinTransform& value) { m_SkeletonTransform = value; }

    const uint& GetNumBones() const { return m_NumBones; }
    uint& GetNumBones() { return m_NumBones; }
    void SetNumBones(const uint& value) { m_NumBones = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetBones() const { return m_Bones; }
    std::vector<Pointer<class NiAVObject*>>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<Pointer<class NiAVObject*>>& value) { m_Bones = value; }

    const std::vector<SkinTransform>& GetBoneTransforms() const { return m_BoneTransforms; }
    std::vector<SkinTransform>& GetBoneTransforms() { return m_BoneTransforms; }
    void SetBoneTransforms(const std::vector<SkinTransform>& value) { m_BoneTransforms = value; }

    const std::vector<SphereBV>& GetBoneBounds() const { return m_BoneBounds; }
    std::vector<SphereBV>& GetBoneBounds() { return m_BoneBounds; }
    void SetBoneBounds(const std::vector<SphereBV>& value) { m_BoneBounds = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
