#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Triangle.hpp"
#include "Triangle.hpp"
#include "SkinPartitionUnknownItem1.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skinning data for a submesh, optimized for hardware skinning. Part of NiSkinPartition.
 *         
 */
class SkinPartition : public Construct
{
protected:
    /**
     * Number of vertices in this submesh.
     */
    ushort m_NumVertices;
    /**
     * Number of triangles in this submesh.
     */
    ushort m_NumTriangles;
    /**
     * Number of bones influencing this submesh.
     */
    ushort m_NumBones;
    /**
     * Number of strips in this submesh (zero if not stripped).
     */
    ushort m_NumStrips;
    /**
     * Number of weight coefficients per vertex. The Gamebryo engine seems to work well only if this number is equal to 4, even if there are less than 4 influences per vertex.
     */
    ushort m_NumWeightsPerVertex;
    /**
     * List of bones.
     */
    std::vector<ushort> m_Bones;
    /**
     * Do we have a vertex map?
     */
    bool m_HasVertexMap;
    /**
     * Maps the weight/influence lists in this submesh to the vertices in the shape being skinned.
     */
    std::vector<ushort> m_VertexMap;
    /**
     * Do we have vertex weights?
     */
    bool m_HasVertexWeights;
    /**
     * The vertex weights.
     */
    std::vector<std::vector<float>> m_VertexWeights;
    /**
     * The strip lengths.
     */
    std::vector<ushort> m_StripLengths;
    /**
     * Do we have triangle or strip data?
     */
    bool m_HasFaces;
    /**
     * The strips.
     */
    std::vector<std::vector<ushort>> m_Strips;
    /**
     * The triangles.
     */
    std::vector<Triangle> m_Triangles;
    /**
     * Do we have bone indices?
     */
    bool m_HasBoneIndices;
    /**
     * Bone indices, they index into 'Bones'.
     */
    std::vector<std::vector<byte>> m_BoneIndices;
    /**
     * Unknown
     */
    ushort m_UnknownShort;
    ushort m_Unknown83C3;
    ushort m_Unknown00001;
    ushort m_NumVertices2;
    ushort m_Unknown00002;
    ushort m_Unknown00003;
    ushort m_Unknown00004;
    std::vector<SkinPartitionUnknownItem1> m_UnknownArr1;

public:
    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const ushort& GetNumTriangles() const { return m_NumTriangles; }
    ushort& GetNumTriangles() { return m_NumTriangles; }
    void SetNumTriangles(const ushort& value) { m_NumTriangles = value; }

    const ushort& GetNumBones() const { return m_NumBones; }
    ushort& GetNumBones() { return m_NumBones; }
    void SetNumBones(const ushort& value) { m_NumBones = value; }

    const ushort& GetNumStrips() const { return m_NumStrips; }
    ushort& GetNumStrips() { return m_NumStrips; }
    void SetNumStrips(const ushort& value) { m_NumStrips = value; }

    const ushort& GetNumWeightsPerVertex() const { return m_NumWeightsPerVertex; }
    ushort& GetNumWeightsPerVertex() { return m_NumWeightsPerVertex; }
    void SetNumWeightsPerVertex(const ushort& value) { m_NumWeightsPerVertex = value; }

    const std::vector<ushort>& GetBones() const { return m_Bones; }
    std::vector<ushort>& GetBones() { return m_Bones; }
    void SetBones(const std::vector<ushort>& value) { m_Bones = value; }

    const bool& GetHasVertexMap() const { return m_HasVertexMap; }
    bool& GetHasVertexMap() { return m_HasVertexMap; }
    void SetHasVertexMap(const bool& value) { m_HasVertexMap = value; }

    const std::vector<ushort>& GetVertexMap() const { return m_VertexMap; }
    std::vector<ushort>& GetVertexMap() { return m_VertexMap; }
    void SetVertexMap(const std::vector<ushort>& value) { m_VertexMap = value; }

    const bool& GetHasVertexWeights() const { return m_HasVertexWeights; }
    bool& GetHasVertexWeights() { return m_HasVertexWeights; }
    void SetHasVertexWeights(const bool& value) { m_HasVertexWeights = value; }

    const std::vector<std::vector<float>>& GetVertexWeights() const { return m_VertexWeights; }
    std::vector<std::vector<float>>& GetVertexWeights() { return m_VertexWeights; }
    void SetVertexWeights(const std::vector<std::vector<float>>& value) { m_VertexWeights = value; }

    const std::vector<ushort>& GetStripLengths() const { return m_StripLengths; }
    std::vector<ushort>& GetStripLengths() { return m_StripLengths; }
    void SetStripLengths(const std::vector<ushort>& value) { m_StripLengths = value; }

    const bool& GetHasFaces() const { return m_HasFaces; }
    bool& GetHasFaces() { return m_HasFaces; }
    void SetHasFaces(const bool& value) { m_HasFaces = value; }

    const std::vector<std::vector<ushort>>& GetStrips() const { return m_Strips; }
    std::vector<std::vector<ushort>>& GetStrips() { return m_Strips; }
    void SetStrips(const std::vector<std::vector<ushort>>& value) { m_Strips = value; }

    const std::vector<Triangle>& GetTriangles() const { return m_Triangles; }
    std::vector<Triangle>& GetTriangles() { return m_Triangles; }
    void SetTriangles(const std::vector<Triangle>& value) { m_Triangles = value; }

    const bool& GetHasBoneIndices() const { return m_HasBoneIndices; }
    bool& GetHasBoneIndices() { return m_HasBoneIndices; }
    void SetHasBoneIndices(const bool& value) { m_HasBoneIndices = value; }

    const std::vector<std::vector<byte>>& GetBoneIndices() const { return m_BoneIndices; }
    std::vector<std::vector<byte>>& GetBoneIndices() { return m_BoneIndices; }
    void SetBoneIndices(const std::vector<std::vector<byte>>& value) { m_BoneIndices = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const ushort& GetUnknown83C3() const { return m_Unknown83C3; }
    ushort& GetUnknown83C3() { return m_Unknown83C3; }
    void SetUnknown83C3(const ushort& value) { m_Unknown83C3 = value; }

    const ushort& GetUnknown00001() const { return m_Unknown00001; }
    ushort& GetUnknown00001() { return m_Unknown00001; }
    void SetUnknown00001(const ushort& value) { m_Unknown00001 = value; }

    const ushort& GetNumVertices2() const { return m_NumVertices2; }
    ushort& GetNumVertices2() { return m_NumVertices2; }
    void SetNumVertices2(const ushort& value) { m_NumVertices2 = value; }

    const ushort& GetUnknown00002() const { return m_Unknown00002; }
    ushort& GetUnknown00002() { return m_Unknown00002; }
    void SetUnknown00002(const ushort& value) { m_Unknown00002 = value; }

    const ushort& GetUnknown00003() const { return m_Unknown00003; }
    ushort& GetUnknown00003() { return m_Unknown00003; }
    void SetUnknown00003(const ushort& value) { m_Unknown00003 = value; }

    const ushort& GetUnknown00004() const { return m_Unknown00004; }
    ushort& GetUnknown00004() { return m_Unknown00004; }
    void SetUnknown00004(const ushort& value) { m_Unknown00004 = value; }

    const std::vector<SkinPartitionUnknownItem1>& GetUnknownArr1() const { return m_UnknownArr1; }
    std::vector<SkinPartitionUnknownItem1>& GetUnknownArr1() { return m_UnknownArr1; }
    void SetUnknownArr1(const std::vector<SkinPartitionUnknownItem1>& value) { m_UnknownArr1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
