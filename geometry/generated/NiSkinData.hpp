#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkinTransform.hpp"
#include "NiSkinPartition.hpp"
#include "SkinData.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skinning data.
 *         
 */
class NiSkinData : public NiObject
{
protected:
    /**
     * Offset of the skin from this bone in bind position.
     */
    SkinTransform m_SkinTransform;
    /**
     * Number of bones.
     */
    uint m_NumBones;
    /**
     * This optionally links a NiSkinPartition for hardware-acceleration information.
     */
    Pointer<class NiSkinPartition*> m_SkinPartition;
    /**
     * Enables Vertex Weights for this NiSkinData.
     */
    byte m_HasVertexWeights;
    /**
     * Contains offset data for each node that this skin is influenced by.
     */
    std::vector<SkinData> m_BoneList;

public:
    const SkinTransform& GetSkinTransform() const { return m_SkinTransform; }
    SkinTransform& GetSkinTransform() { return m_SkinTransform; }
    void SetSkinTransform(const SkinTransform& value) { m_SkinTransform = value; }

    const uint& GetNumBones() const { return m_NumBones; }
    uint& GetNumBones() { return m_NumBones; }
    void SetNumBones(const uint& value) { m_NumBones = value; }

    const Pointer<class NiSkinPartition*>& GetSkinPartition() const { return m_SkinPartition; }
    Pointer<class NiSkinPartition*>& GetSkinPartition() { return m_SkinPartition; }
    void SetSkinPartition(const Pointer<class NiSkinPartition*>& value) { m_SkinPartition = value; }

    const byte& GetHasVertexWeights() const { return m_HasVertexWeights; }
    byte& GetHasVertexWeights() { return m_HasVertexWeights; }
    void SetHasVertexWeights(const byte& value) { m_HasVertexWeights = value; }

    const std::vector<SkinData>& GetBoneList() const { return m_BoneList; }
    std::vector<SkinData>& GetBoneList() { return m_BoneList; }
    void SetBoneList(const std::vector<SkinData>& value) { m_BoneList = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
