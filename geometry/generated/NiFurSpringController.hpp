#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiNode.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


class NiFurSpringController : public NiTimeController
{
protected:
    float m_UnknownFloat;
    float m_UnknownFloat2;
    /**
     * The number of node bones referenced as influences.
     */
    uint m_NumBones;
    /**
     * List of all armature bones.
     */
    std::vector<Pointer<class NiNode*>> m_Bones;
    /**
     * The number of node bones referenced as influences.
     */
    uint m_NumBones2;
    /**
     * List of all armature bones.
     */
    std::vector<Pointer<class NiNode*>> m_Bones2;

public:
    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const uint& GetNumBones() const { return m_NumBones; }
    uint& GetNumBones() { return m_NumBones; }
    void SetNumBones(const uint& value) { m_NumBones = value; }

    const std::vector<Pointer<class NiNode*>>& GetBones() const { return m_Bones; }
    std::vector<Pointer<class NiNode*>>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<Pointer<class NiNode*>>& value) { m_Bones = value; }

    const uint& GetNumBones2() const { return m_NumBones2; }
    uint& GetNumBones2() { return m_NumBones2; }
    void SetNumBones2(const uint& value) { m_NumBones2 = value; }

    const std::vector<Pointer<class NiNode*>>& GetBones2() const { return m_Bones2; }
    std::vector<Pointer<class NiNode*>>& GetBones2() { return m_Bones2; }
    void SetBones2(const std::vector<Pointer<class NiNode*>>& value) { m_Bones2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
