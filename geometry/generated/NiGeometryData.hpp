#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "SkyrimHavokMaterial.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "Color4.hpp"
#include "TexCoord.hpp"
#include "ConsistencyType.hpp"
#include "ConsistencyType.hpp"
#include "AbstractAdditionalGeometryData.hpp"
#include "AbstractAdditionalGeometryData.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Mesh data: vertices, vertex normals, etc.
 *         
 */
class NiGeometryData : public NiObject
{
protected:
    /**
     * Unknown identifier. Always 0.
     */
    int m_UnknownInt;
    /**
     * Number of vertices.
     */
    ushort m_NumVertices;
    /**
     * Bethesda uses this for max number of particles in NiPSysData.
     */
    ushort m_BSMaxVertices;
    /**
     * Used with NiCollision objects when OBB or TRI is set.
     */
    byte m_KeepFlags;
    /**
     * Unknown.
     */
    byte m_CompressFlags;
    /**
     * Is the vertex array present? (Always non-zero.)
     */
    bool m_HasVertices;
    /**
     * The mesh vertices.
     */
    std::vector<Vector3> m_Vertices;
    /**
     * Flag for tangents and bitangents in upper byte. Texture flags in lower byte.
     */
    ushort m_NumUVSets;
    /**
     * Bethesda's version of this field for nif versions 20.2.0.7 and up. Only a single bit denotes whether uv's are present. For example, see meshes/architecture/megaton/megatonrampturn45sml.nif in Fallout 3.
     */
    ushort m_BSNumUVSets;
    /**
     * Material
     */
    SkyrimHavokMaterial m_SkyrimMaterial;
    /**
     * Do we have lighting normals? These are essential for proper lighting: if not present, the model will only be influenced by ambient light.
     */
    bool m_HasNormals;
    /**
     * The lighting normals.
     */
    std::vector<Vector3> m_Normals;
    /**
     * Tangent vectors.
     */
    std::vector<Vector3> m_Tangents;
    /**
     * Bitangent vectors.
     */
    std::vector<Vector3> m_Bitangents;
    /**
     * Center of the bounding box (smallest box that contains all vertices) of the mesh.
     */
    Vector3 m_Center;
    /**
     * Radius of the mesh: maximal Euclidean distance between the center and all vertices.
     */
    float m_Radius;
    /**
     * Unknown, always 0?
     */
    std::vector<short> m_Unknown13Shorts;
    /**
     * 
     *             Do we have vertex colors? These are usually used to fine-tune the lighting of the model.
     * 
     *             Note: how vertex colors influence the model can be controlled by having a NiVertexColorProperty object as a property child of the root node. If this property object is not present, the vertex colors fine-tune lighting.
     * 
     *             Note 2: set to either 0 or 0xFFFFFFFF for NifTexture compatibility.
     *         
     */
    bool m_HasVertexColors;
    /**
     * The vertex colors.
     */
    std::vector<Color4> m_VertexColors;
    /**
     * 
     *             Do we have UV coordinates?
     * 
     *             Note: for compatibility with NifTexture, set this value to either 0x00000000 or 0xFFFFFFFF.
     *         
     */
    bool m_HasUV;
    /**
     * The UV texture coordinates. They follow the OpenGL standard: some programs may require you to flip the second coordinate.
     */
    std::vector<std::vector<TexCoord>> m_UVSets;
    /**
     * Consistency Flags
     */
    ConsistencyType m_ConsistencyFlags;
    /**
     * Unknown.
     */
    Pointer<class AbstractAdditionalGeometryData*> m_AdditionalData;

public:
    const int& GetUnknownInt() const { return m_UnknownInt; }
    int& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const int& value) { m_UnknownInt = value; }

    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const ushort& GetBSMaxVertices() const { return m_BSMaxVertices; }
    ushort& GetBSMaxVertices() { return m_BSMaxVertices; }
    void SetBSMaxVertices(const ushort& value) { m_BSMaxVertices = value; }

    const byte& GetKeepFlags() const { return m_KeepFlags; }
    byte& GetKeepFlags() { return m_KeepFlags; }
    void SetKeepFlags(const byte& value) { m_KeepFlags = value; }

    const byte& GetCompressFlags() const { return m_CompressFlags; }
    byte& GetCompressFlags() { return m_CompressFlags; }
    void SetCompressFlags(const byte& value) { m_CompressFlags = value; }

    const bool& GetHasVertices() const { return m_HasVertices; }
    bool& GetHasVertices() { return m_HasVertices; }
    void SetHasVertices(const bool& value) { m_HasVertices = value; }

    const std::vector<Vector3>& GetVertices() const { return m_Vertices; }
    std::vector<Vector3>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<Vector3>& value) { m_Vertices = value; }

    const ushort& GetNumUVSets() const { return m_NumUVSets; }
    ushort& GetNumUVSets() { return m_NumUVSets; }
    void SetNumUVSets(const ushort& value) { m_NumUVSets = value; }

    const ushort& GetBSNumUVSets() const { return m_BSNumUVSets; }
    ushort& GetBSNumUVSets() { return m_BSNumUVSets; }
    void SetBSNumUVSets(const ushort& value) { m_BSNumUVSets = value; }

    const SkyrimHavokMaterial& GetSkyrimMaterial() const { return m_SkyrimMaterial; }
    SkyrimHavokMaterial& GetSkyrimMaterial() { return m_SkyrimMaterial; }
    void SetSkyrimMaterial(const SkyrimHavokMaterial& value) { m_SkyrimMaterial = value; }

    const bool& GetHasNormals() const { return m_HasNormals; }
    bool& GetHasNormals() { return m_HasNormals; }
    void SetHasNormals(const bool& value) { m_HasNormals = value; }

    const std::vector<Vector3>& GetNormals() const { return m_Normals; }
    std::vector<Vector3>& GetNormals() { return m_Normals; }
    void SetNormals(const std::vector<Vector3>& value) { m_Normals = value; }

    const std::vector<Vector3>& GetTangents() const { return m_Tangents; }
    std::vector<Vector3>& GetTangents() { return m_Tangents; }
    void SetTangents(const std::vector<Vector3>& value) { m_Tangents = value; }

    const std::vector<Vector3>& GetBitangents() const { return m_Bitangents; }
    std::vector<Vector3>& GetBitangents() { return m_Bitangents; }
    void SetBitangents(const std::vector<Vector3>& value) { m_Bitangents = value; }

    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }

    const std::vector<short>& GetUnknown13Shorts() const { return m_Unknown13Shorts; }
    std::vector<short>& GetUnknown13Shorts() { return m_Unknown13Shorts; }
    void SetUnknown13Shorts(const std::vector<short>& value) { m_Unknown13Shorts = value; }

    const bool& GetHasVertexColors() const { return m_HasVertexColors; }
    bool& GetHasVertexColors() { return m_HasVertexColors; }
    void SetHasVertexColors(const bool& value) { m_HasVertexColors = value; }

    const std::vector<Color4>& GetVertexColors() const { return m_VertexColors; }
    std::vector<Color4>& GetVertexColors() { return m_VertexColors; }
    void SetVertexColors(const std::vector<Color4>& value) { m_VertexColors = value; }

    const bool& GetHasUV() const { return m_HasUV; }
    bool& GetHasUV() { return m_HasUV; }
    void SetHasUV(const bool& value) { m_HasUV = value; }

    const std::vector<std::vector<TexCoord>>& GetUVSets() const { return m_UVSets; }
    std::vector<std::vector<TexCoord>>& GetUVSets() { return m_UVSets; }
    void SetUVSets(const std::vector<std::vector<TexCoord>>& value) { m_UVSets = value; }

    const ConsistencyType& GetConsistencyFlags() const { return m_ConsistencyFlags; }
    ConsistencyType& GetConsistencyFlags() { return m_ConsistencyFlags; }
    void SetConsistencyFlags(const ConsistencyType& value) { m_ConsistencyFlags = value; }

    const Pointer<class AbstractAdditionalGeometryData*>& GetAdditionalData() const { return m_AdditionalData; }
    Pointer<class AbstractAdditionalGeometryData*>& GetAdditionalData() { return m_AdditionalData; }
    void SetAdditionalData(const Pointer<class AbstractAdditionalGeometryData*>& value) { m_AdditionalData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
