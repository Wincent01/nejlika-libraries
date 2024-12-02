#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Defines subshape chunks in bhkCompressedMeshShapeData
 * 		
 */
class bhkCMSDChunk : public Construct
{
protected:
    /**
     * Local translation
     */
    Vector4 m_Translation;
    /**
     * Index of material in bhkCompressedMeshShapeData::Chunk Materials
     */
    uint m_MaterialIndex;
    /**
     * Always 65535?
     */
    ushort m_UnknownShort1;
    /**
     * Index of transformation in bhkCompressedMeshShapeData::Chunk Transforms
     */
    ushort m_TransformIndex;
    /**
     * Number of compressed vertices
     */
    uint m_NumVertices;
    /**
     * Compressed vertices
     */
    std::vector<ushort> m_Vertices;
    uint m_NumIndices;
    std::vector<ushort> m_Indices;
    /**
     * Number of compressed strips
     */
    uint m_NumStrips;
    /**
     * Compressed strips
     */
    std::vector<ushort> m_Strips;
    /**
     * Number of 
     */
    uint m_NumIndices2;
    /**
     * Compressed 
     */
    std::vector<ushort> m_Indices2;

public:
    const Vector4& GetTranslation() const { return m_Translation; }
    Vector4& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector4& value) { m_Translation = value; }

    const uint& GetMaterialIndex() const { return m_MaterialIndex; }
    uint& GetMaterialIndex() { return m_MaterialIndex; }
    void SetMaterialIndex(const uint& value) { m_MaterialIndex = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const ushort& GetTransformIndex() const { return m_TransformIndex; }
    ushort& GetTransformIndex() { return m_TransformIndex; }
    void SetTransformIndex(const ushort& value) { m_TransformIndex = value; }

    const uint& GetNumVertices() const { return m_NumVertices; }
    uint& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const uint& value) { m_NumVertices = value; }

    const std::vector<ushort>& GetVertices() const { return m_Vertices; }
    std::vector<ushort>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<ushort>& value) { m_Vertices = value; }

    const uint& GetNumIndices() const { return m_NumIndices; }
    uint& GetNumIndices() { return m_NumIndices; }
    void SetNumIndices(const uint& value) { m_NumIndices = value; }

    const std::vector<ushort>& GetIndices() const { return m_Indices; }
    std::vector<ushort>& GetIndices() { return m_Indices; }
    void SetIndices(const std::vector<ushort>& value) { m_Indices = value; }

    const uint& GetNumStrips() const { return m_NumStrips; }
    uint& GetNumStrips() { return m_NumStrips; }
    void SetNumStrips(const uint& value) { m_NumStrips = value; }

    const std::vector<ushort>& GetStrips() const { return m_Strips; }
    std::vector<ushort>& GetStrips() { return m_Strips; }
    void SetStrips(const std::vector<ushort>& value) { m_Strips = value; }

    const uint& GetNumIndices2() const { return m_NumIndices2; }
    uint& GetNumIndices2() { return m_NumIndices2; }
    void SetNumIndices2(const uint& value) { m_NumIndices2 = value; }

    const std::vector<ushort>& GetIndices2() const { return m_Indices2; }
    std::vector<ushort>& GetIndices2() { return m_Indices2; }
    void SetIndices2(const std::vector<ushort>& value) { m_Indices2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
