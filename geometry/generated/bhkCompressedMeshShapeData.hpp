#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "bhkCMSDMaterial.hpp"
#include "bhkCMSDTransform.hpp"
#include "Vector4.hpp"
#include "bhkCMSDBigTris.hpp"
#include "bhkCMSDChunk.hpp"
#include "bhkRefObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *          A compressed mesh shape for collision in Skyrim.
 * 		
 */
class bhkCompressedMeshShapeData : public bhkRefObject
{
protected:
    /**
     * Number of bits in the shape-key reserved for a triangle index
     */
    uint m_BitsPerIndex;
    /**
     * Number of bits in the shape-key reserved for a triangle index and its winding
     */
    uint m_BitsPerWIndex;
    /**
     * Mask used to get the triangle index and winding from a shape-key (common: 262143 = 0x3ffff)
     */
    uint m_MaskWIndex;
    /**
     * Mask used to get the triangle index from a shape-key (common: 131071 = 0x1ffff)
     */
    uint m_MaskIndex;
    /**
     * The radius of the storage mesh shape? Quantization error?
     */
    float m_Error;
    /**
     * The minimum boundary of the AABB (the coordinates of the corner with the lowest numerical values)
     */
    Vector4 m_BoundsMin;
    /**
     * The maximum boundary of the AABB (the coordinates of the corner with the highest numerical values)
     */
    Vector4 m_BoundsMax;
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * Unknown
     */
    uint m_UnknownInt3;
    /**
     * Unknown
     */
    uint m_UnknownInt4;
    /**
     * Unknown
     */
    uint m_UnknownInt5;
    /**
     * Unknown
     */
    byte m_UnknownByte2;
    /**
     * Number of chunk materials
     */
    uint m_NumMaterials;
    /**
     * Table (array) with sets of materials. Chunks refers to this table by index.
     */
    std::vector<bhkCMSDMaterial> m_ChunkMaterials;
    /**
     * Unknown
     */
    uint m_UnknownInt6;
    /**
     * Number of chunk transformations
     */
    uint m_NumTransforms;
    /**
     * Table (array) with sets of transformations. Chunks refers to this table by index.
     */
    std::vector<bhkCMSDTransform> m_ChunkTransforms;
    /**
     * Unknown
     */
    uint m_NumBigVerts;
    /**
     * Compressed Vertices?
     */
    std::vector<Vector4> m_BigVerts;
    /**
     * Unknown
     */
    uint m_NumBigTris;
    /**
     * Unknown
     */
    std::vector<bhkCMSDBigTris> m_BigTris;
    /**
     * Unknown
     */
    uint m_NumChunks;
    std::vector<bhkCMSDChunk> m_Chunks;
    /**
     * Unknown, end of block.
     */
    uint m_UnknownInt12;

public:
    const uint& GetBitsPerIndex() const { return m_BitsPerIndex; }
    uint& GetBitsPerIndex() { return m_BitsPerIndex; }
    void SetBitsPerIndex(const uint& value) { m_BitsPerIndex = value; }

    const uint& GetBitsPerWIndex() const { return m_BitsPerWIndex; }
    uint& GetBitsPerWIndex() { return m_BitsPerWIndex; }
    void SetBitsPerWIndex(const uint& value) { m_BitsPerWIndex = value; }

    const uint& GetMaskWIndex() const { return m_MaskWIndex; }
    uint& GetMaskWIndex() { return m_MaskWIndex; }
    void SetMaskWIndex(const uint& value) { m_MaskWIndex = value; }

    const uint& GetMaskIndex() const { return m_MaskIndex; }
    uint& GetMaskIndex() { return m_MaskIndex; }
    void SetMaskIndex(const uint& value) { m_MaskIndex = value; }

    const float& GetError() const { return m_Error; }
    float& GetError() { return m_Error; }
    void SetError(const float& value) { m_Error = value; }

    const Vector4& GetBoundsMin() const { return m_BoundsMin; }
    Vector4& GetBoundsMin() { return m_BoundsMin; }
    void SetBoundsMin(const Vector4& value) { m_BoundsMin = value; }

    const Vector4& GetBoundsMax() const { return m_BoundsMax; }
    Vector4& GetBoundsMax() { return m_BoundsMax; }
    void SetBoundsMax(const Vector4& value) { m_BoundsMax = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const uint& GetUnknownInt4() const { return m_UnknownInt4; }
    uint& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const uint& value) { m_UnknownInt4 = value; }

    const uint& GetUnknownInt5() const { return m_UnknownInt5; }
    uint& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const uint& value) { m_UnknownInt5 = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }

    const uint& GetNumMaterials() const { return m_NumMaterials; }
    uint& GetNumMaterials() { return m_NumMaterials; }
    void SetNumMaterials(const uint& value) { m_NumMaterials = value; }

    const std::vector<bhkCMSDMaterial>& GetChunkMaterials() const { return m_ChunkMaterials; }
    std::vector<bhkCMSDMaterial>& GetChunkMaterials() { return m_ChunkMaterials; }
    void SetChunkMaterials(const std::vector<bhkCMSDMaterial>& value) { m_ChunkMaterials = value; }

    const uint& GetUnknownInt6() const { return m_UnknownInt6; }
    uint& GetUnknownInt6() { return m_UnknownInt6; }
    void SetUnknownInt6(const uint& value) { m_UnknownInt6 = value; }

    const uint& GetNumTransforms() const { return m_NumTransforms; }
    uint& GetNumTransforms() { return m_NumTransforms; }
    void SetNumTransforms(const uint& value) { m_NumTransforms = value; }

    const std::vector<bhkCMSDTransform>& GetChunkTransforms() const { return m_ChunkTransforms; }
    std::vector<bhkCMSDTransform>& GetChunkTransforms() { return m_ChunkTransforms; }
    void SetChunkTransforms(const std::vector<bhkCMSDTransform>& value) { m_ChunkTransforms = value; }

    const uint& GetNumBigVerts() const { return m_NumBigVerts; }
    uint& GetNumBigVerts() { return m_NumBigVerts; }
    void SetNumBigVerts(const uint& value) { m_NumBigVerts = value; }

    const std::vector<Vector4>& GetBigVerts() const { return m_BigVerts; }
    std::vector<Vector4>& GetBigVerts() { return m_BigVerts; }
    void SetBigVerts(const std::vector<Vector4>& value) { m_BigVerts = value; }

    const uint& GetNumBigTris() const { return m_NumBigTris; }
    uint& GetNumBigTris() { return m_NumBigTris; }
    void SetNumBigTris(const uint& value) { m_NumBigTris = value; }

    const std::vector<bhkCMSDBigTris>& GetBigTris() const { return m_BigTris; }
    std::vector<bhkCMSDBigTris>& GetBigTris() { return m_BigTris; }
    void SetBigTris(const std::vector<bhkCMSDBigTris>& value) { m_BigTris = value; }

    const uint& GetNumChunks() const { return m_NumChunks; }
    uint& GetNumChunks() { return m_NumChunks; }
    void SetNumChunks(const uint& value) { m_NumChunks = value; }

    const std::vector<bhkCMSDChunk>& GetChunks() const { return m_Chunks; }
    std::vector<bhkCMSDChunk>& GetChunks() { return m_Chunks; }
    void SetChunks(const std::vector<bhkCMSDChunk>& value) { m_Chunks = value; }

    const uint& GetUnknownInt12() const { return m_UnknownInt12; }
    uint& GetUnknownInt12() { return m_UnknownInt12; }
    void SetUnknownInt12(const uint& value) { m_UnknownInt12 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
