#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

#include <glm/glm.hpp>

#include "Pointer.hpp"
#include "Header.hpp"
#include "Matrix33.hpp"
#include "Vector3.hpp"
#include "Color4.hpp"
#include "NiTriBasedGeomData.hpp"
#include "Factory.hpp"
#include "NiTriShape.hpp"
#include "NiTriStrips.hpp"
#include "NiAVObject.hpp"
#include "NiTriShapeData.hpp"
#include "NiTriStripsData.hpp"
#include "NiNode.hpp"

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"

namespace nejlika::geometry {

class Converter
{
public:
    void LoadKfm(nejlika::Reader& reader, const std::string& path);

    void LoadNif(nejlika::Reader& reader, const std::string& path);

    void LoadKf(nejlika::Reader& reader, const std::string& path);

    void ExportGLTF(std::stringstream& writer);

    void Cleanup();

    ~Converter();

protected:
    using KeyframeData = std::tuple<std::vector<float>, std::vector<float>, int32_t>;
    struct KeyframeSet {
        std::map<float, std::array<float, 3>> translations; // Time -> Vec3 translation
        std::map<float, std::array<float, 4>> rotations;    // Time -> Vec4 rotation
        std::map<float, std::array<float, 3>> scales;       // Time -> Vec3 scale
    };

    int32_t ExportGLTFHeirarchy(class NiAVObject* node, const std::string& name, tinygltf::Model& model, nejlika::Writer& buffer, int32_t childIndex, int32_t levelOfDetail, bool hasLOD);

    void AllocateNodeIndices(class NiAVObject* node, tinygltf::Model& model, nejlika::Writer& buffer);

    std::vector<double> RotationMatrixToQuaternion(const std::array<std::array<float, 3>, 3>& mat);

    int32_t ExportGLTFVertices(const std::vector<Vector3>& vertices, tinygltf::Model& model, nejlika::Writer& buffer);
    int32_t ExportGLTFIndices(const std::vector<uint16_t>& indices, tinygltf::Model& model, nejlika::Writer& buffer);
    int32_t ExportGLTFIndices(const std::vector<Triangle>& indices, tinygltf::Model& model, nejlika::Writer& buffer);
    int32_t ExportGLTFNormals(const std::vector<Vector3>& normals, tinygltf::Model& model, nejlika::Writer& buffer);
    int32_t ExportGLTFUVs(const std::vector<TexCoord>& uvs, tinygltf::Model& model, nejlika::Writer& buffer);
    int32_t ExportGLTFColors(const std::vector<Color4>& colors, tinygltf::Model& model, nejlika::Writer& buffer);

    void ExportNiTriBasedGeomData(const NiTriBasedGeomData* data, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Primitive& primitive);
    void ExportNiTriShapeData(const NiTriShapeData* data, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Primitive& primitive);
    void ExportNiTriStripsData(const NiTriStripsData* data, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Primitive& primitive);

    void ExportMaterial(const NiAVObject* node, tinygltf::Model& model, tinygltf::Primitive& primitive, nejlika::Writer& buffer, const std::vector<Vector3>& vertices);

    int32_t ExportNiTriShape(const NiTriShape* shape, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Node& gltfNode);
    int32_t ExportNiTriStrips(const NiTriStrips* strips, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Node& gltfNode);

    void ExportNodeTransformations(const NiAVObject* node, tinygltf::Model& model, nejlika::Writer& buffer, tinygltf::Node& gltfNode);

    void ExportAnimation(const std::string& name, const nejlika::geometry::Header& header, const std::vector<nejlika::geometry::Construct*>& blocks, tinygltf::Model& model, nejlika::Writer& buffer);

    void WriteAnimationData(
        nejlika::Writer &buffer, tinygltf::Model &model, tinygltf::Animation &animation,
        int32_t nodeIndex, const std::string &targetPath, const KeyframeData &data);

    std::pair<int32_t, int32_t> ConvertDDSToPNG(const std::string& ddsPath, nejlika::Writer& buffer);

    void AlignBuffer(nejlika::Writer& buffer);

    NiNode* FindClosestCommonParent(NiNode* root, std::vector<NiNode*> nodes);

    // NIF data
    std::string GetNifString(uint32_t index) const;

    std::string GetNifString(const nejlika::geometry::Header& header, uint32_t index) const;
    
    glm::mat4 ComputeGlobalTransform(NiAVObject* node);

    std::unordered_map<NiAVObject*, NiNode*> m_ParentMap;

    std::vector<nejlika::geometry::Construct*> m_Blocks;
    std::unordered_map<nejlika::geometry::Construct*, std::string> m_BlockNames;
    std::unordered_map<std::string, std::pair<nejlika::geometry::Header, std::vector<nejlika::geometry::Construct*>>> m_AnimationMap;

    nejlika::geometry::Header m_Header;

    std::string m_NifPath;

    std::unordered_map<std::string, int32_t> m_TextureCache;

    std::vector<std::function<void(tinygltf::Model&, tinygltf::Animation&, nejlika::Writer&)>> m_OnAnimationExport;

    // GLTF data
    tinygltf::Model m_Model;

    std::unordered_map<NiAVObject*, int32_t> m_NodeMap;

    std::unordered_set<NiAVObject*> m_ExportedNodes;
};

}
