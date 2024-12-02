#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBone.hpp"
#include "OldSkinData.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Old version of skinning instance.
 *         
 */
class NiTriShapeSkinController : public NiTimeController
{
protected:
    /**
     * The number of node bones referenced as influences.
     */
    uint m_NumBones;
    /**
     * The number of vertex weights stored for each bone.
     */
    std::vector<uint> m_VertexCounts;
    /**
     * List of all armature bones.
     */
    std::vector<Pointer<class NiBone*>> m_Bones;
    /**
     * Contains skin weight data for each node that this skin is influenced by.
     */
    std::vector<std::vector<OldSkinData>> m_BoneData;

public:
    const uint& GetNumBones() const { return m_NumBones; }
    uint& GetNumBones() { return m_NumBones; }
    void SetNumBones(const uint& value) { m_NumBones = value; }

    const std::vector<uint>& GetVertexCounts() const { return m_VertexCounts; }
    std::vector<uint>& GetVertexCounts() { return m_VertexCounts; }
    void SetVertexCounts(const std::vector<uint>& value) { m_VertexCounts = value; }

    const std::vector<Pointer<class NiBone*>>& GetBones() const { return m_Bones; }
    std::vector<Pointer<class NiBone*>>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<Pointer<class NiBone*>>& value) { m_Bones = value; }

    const std::vector<std::vector<OldSkinData>>& GetBoneData() const { return m_BoneData; }
    std::vector<std::vector<OldSkinData>>& GetBoneData() { return m_BoneData; }
    void SetBoneData(const std::vector<std::vector<OldSkinData>>& value) { m_BoneData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
