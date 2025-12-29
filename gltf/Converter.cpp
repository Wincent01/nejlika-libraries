#include "Converter.hpp"

#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>

#include "NiNode.hpp"
#include "NiTriShape.hpp"
#include "NiTriStrips.hpp"
#include "NiAVObject.hpp"
#include "NiTriShapeData.hpp"
#include "NiTriStripsData.hpp"
#include "NiMaterialProperty.hpp"
#include "NiTexturingProperty.hpp"
#include "NiAlphaProperty.hpp"
#include "NiLODNode.hpp"
#include "NiLODData.hpp"
#include "NiRangeLODData.hpp"
#include "NiControllerSequence.hpp"
#include "NiTransformInterpolator.hpp"
#include "NiMaterialProperty.hpp"
#include "NiAlphaController.hpp"
#include "NiFloatInterpolator.hpp"
#include "NiTextureTransformController.hpp"

#include "Kfm.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Factory.hpp"

using namespace nejlika::geometry;

bool nejlika::geometry::Converter::LoadKfm(nejlika::Reader &reader, const std::string &path)
{
    nejlika::geometry::Kfm kfm;

    kfm.Read(reader, 0, 0, 0);

    const auto &nifVec = kfm.GetNIFFileName().GetValue();

    if (nifVec.empty())
    {
        throw std::runtime_error("NIF file name is empty");
    }

    std::string nifPath(nifVec.begin(), nifVec.end()); // Relative path

    // Replace all backslashes with forward slashes and make all lowercase
    std::replace(nifPath.begin(), nifPath.end(), '\\', '/');
    std::transform(nifPath.begin(), nifPath.end(), nifPath.begin(), ::tolower);

    std::filesystem::path parentPath = std::filesystem::path(path).parent_path();
    std::filesystem::path nifFullPath = parentPath / nifPath;

    nejlika::Reader nifReader(nifFullPath.string());

    LoadNif(nifReader, nifFullPath.string());

    // Load the KF files
    for (const auto &kf : kfm.GetAnimations())
    {
        const auto &kfVec = kf.GetKFFileName().GetValue();

        if (kfVec.empty())
        {
            continue;
        }

        std::string kfPath(kfVec.begin(), kfVec.end()); // Relative path

        // Replace all backslashes with forward slashes and make all lowercase
        std::replace(kfPath.begin(), kfPath.end(), '\\', '/');
        std::transform(kfPath.begin(), kfPath.end(), kfPath.begin(), ::tolower);

        std::filesystem::path kfFullPath = parentPath / kfPath;

        nejlika::Reader kfReader(kfFullPath.string());

        if (!LoadKf(kfReader, kfFullPath.string()))
        {
            std::cout << "Failed to load KF file: " << kfFullPath.string() << std::endl;
        }
    }

    return true;
}

bool nejlika::geometry::Converter::LoadNif(nejlika::Reader &reader, const std::string &path)
{
    m_NifPath = path;

    m_Header.Read(reader, 0, 0, 0);

    // std::cout << header.GetHeaderString() << std::endl;

    const auto &version = m_Header.GetVersion();
    const auto &blockTypes = m_Header.GetBlockTypes();
    const auto &userVersion = m_Header.GetUserVersion();
    const auto &blockTypeIndex = m_Header.GetBlockTypeIndex();
    const auto &numBlocks = m_Header.GetNumBlocks();
    const auto &blockSizes = m_Header.GetBlockSize();

    m_Blocks.clear();
    m_BlockNames.clear();

    m_Blocks.reserve(numBlocks);
    m_BlockNames.reserve(numBlocks);

    for (uint32_t i = 0; i < numBlocks; i++)
    {
        size_t blockTypePos = blockTypeIndex[i];

        if (blockTypePos >= blockTypes.size() || blockTypePos < 0)
        {
            // Increase the read head by the block size
            reader.SetReadHead(reader.GetReadHead() + blockSizes[i]);

            continue;
        }

        const auto &blockType = blockTypes[blockTypePos];
        std::string blockName(blockType.GetValue().begin(), blockType.GetValue().end());
        auto *block = nejlika::geometry::Factory::Create(blockName);

        if (!block)
        {
            std::cout << "Failed to create block: " << blockName << std::endl;

            // Increase the read head by the block size
            reader.SetReadHead(reader.GetReadHead() + blockSizes[i]);
            continue;
        }

        size_t startHead = reader.GetReadHead();
        try
        {
            block->Read(reader, version, userVersion, 0);
            size_t endHead = reader.GetReadHead();

            uint32_t blockSize = endHead - startHead;
            if (blockSize != blockSizes[i])
            {
                std::cout << "Block size mismatch: " << blockName << " expected " << blockSizes[i] << " got " << blockSize << std::endl;
            }

            m_Blocks.push_back(block);
            m_BlockNames[block] = blockName;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to read block: " << blockName << " " << e.what() << std::endl;
            delete block;
        }
        reader.SetReadHead(startHead + blockSizes[i]);
    }

    return true;
}

bool nejlika::geometry::Converter::LoadKf(nejlika::Reader &reader, const std::string &path)
{
    Header header;

    header.Read(reader, 0, 0, 0);

    // std::cout << header.GetHeaderString() << std::endl;

    const auto &version = header.GetVersion();
    const auto &blockTypes = header.GetBlockTypes();
    const auto &userVersion = header.GetUserVersion();
    const auto &blockTypeIndex = header.GetBlockTypeIndex();
    const auto &numBlocks = header.GetNumBlocks();
    const auto &blockSizes = header.GetBlockSize();

    if (numBlocks != blockSizes.size() || numBlocks != blockTypeIndex.size())
    {
        std::cout << "KF file block count mismatch" << std::endl;
        return false;
    }

    std::vector<nejlika::geometry::Construct *> blocks;
    std::unordered_map<nejlika::geometry::Construct *, std::string> blockNames;

    blocks.reserve(numBlocks);
    blockNames.reserve(numBlocks);

    for (uint32_t i = 0; i < numBlocks; i++)
    {
        size_t blockTypePos = blockTypeIndex[i];

        if (blockTypePos >= blockTypes.size() || blockTypePos < 0)
        {
            // Increase the read head by the block size
            reader.SetReadHead(reader.GetReadHead() + blockSizes[i]);

            continue;
        }

        const auto &blockType = blockTypes[blockTypePos];
        std::string blockName(blockType.GetValue().begin(), blockType.GetValue().end());
        auto *block = nejlika::geometry::Factory::Create(blockName);

        if (!block)
        {
            std::cout << "Failed to create block: " << blockName << std::endl;

            // Increase the read head by the block size
            reader.SetReadHead(reader.GetReadHead() + blockSizes[i]);
            continue;
        }

        size_t startHead = reader.GetReadHead();
        try
        {
            block->Read(reader, version, userVersion, 0);
            size_t endHead = reader.GetReadHead();

            uint32_t blockSize = endHead - startHead;
            if (blockSize != blockSizes[i])
            {
                std::cout << "Block size mismatch: " << blockName << " expected " << blockSizes[i] << " got " << blockSize << std::endl;
            }

            blocks.push_back(block);
            blockNames[block] = blockName;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to read block: " << blockName << " " << e.what() << std::endl;
            delete block;
        }
        reader.SetReadHead(startHead + blockSizes[i]);
    }

    m_AnimationMap[path] = std::make_pair(header, blocks);

    return true;
}

void nejlika::geometry::Converter::ExportGLTF(std::stringstream &writer)
{
    tinygltf::Model model;

    // Create a root node
    tinygltf::Node root;
    root.name = "Root";

    // Add a scene
    tinygltf::Scene scene;

    // Create a buffer
    nejlika::Writer buffer;

    // First and foremost, allocate an index for each node recursively
    model.nodes.reserve(m_Blocks.size() + 1);
    model.nodes.push_back(root);

    std::unordered_set<NiAVObject *> sceneNodeCandidates;
    std::unordered_set<NiAVObject *> nonSceneNodes;

    for (auto *block : m_Blocks)
    {
        auto *node = dynamic_cast<NiAVObject *>(block);

        if (!node)
        {
            continue;
        }

        AllocateNodeIndices(node, model, buffer);

        sceneNodeCandidates.insert(node);

        if (NiNode *niNode = dynamic_cast<NiNode *>(block))
        {
            for (const auto &child : niNode->GetChildren())
            {
                nonSceneNodes.insert(child.Query(m_Blocks));
            }
        }
    }

    for (auto *node : sceneNodeCandidates)
    {
        if (nonSceneNodes.find(node) == nonSceneNodes.end())
        {
            root.children.push_back(m_NodeMap[node]);
        }
    }

    // Create the heirarchy
    for (auto *block : sceneNodeCandidates)
    {
        NiNode *node = dynamic_cast<NiNode *>(block);

        if (!node)
        {
            continue;
        }

        const std::string &type = m_BlockNames[node];

        ExportGLTFHeirarchy(node, type, model, buffer, 0, 0, false);
    }

    int32_t rootNodeIndex = 0;
    model.nodes[rootNodeIndex] = root;

    scene.nodes.push_back(rootNodeIndex);
    model.scenes.push_back(scene);

    for (const auto &[path, blocks] : m_AnimationMap)
    {
        ExportAnimation(path, blocks.first, blocks.second, model, buffer);
    }

    tinygltf::Buffer gltfBuffer;
    gltfBuffer.data.assign(buffer.GetBuffer().begin(), buffer.GetBuffer().begin() + buffer.GetWriteHead());
    model.buffers.push_back(gltfBuffer);

    // Export the model to the writer
    // Fist, create a byte stream
    tinygltf::TinyGLTF gltf;

    bool result = gltf.WriteGltfSceneToStream(&model, writer, true, false);

    if (!result)
    {
        throw std::runtime_error("Failed to write GLTF to stream");
    }
}

void nejlika::geometry::Converter::Cleanup()
{
    for (auto *block : m_Blocks)
    {
        delete block;
    }

    m_Blocks.clear();
    m_BlockNames.clear();
}

nejlika::geometry::Converter::~Converter()
{
    Cleanup();
}

int32_t nejlika::geometry::Converter::ExportGLTFHeirarchy(NiAVObject *node, const std::string &type, tinygltf::Model &model, nejlika::Writer &buffer, int32_t childIndex, int32_t levelOfDetail, bool hasLOD)
{
    if (m_ExportedNodes.find(node) != m_ExportedNodes.end())
    {
        return m_NodeMap[node];
    }

    m_ExportedNodes.insert(node);

    if (hasLOD && childIndex > levelOfDetail)
    {
        return -1;
    }

    tinygltf::Node gltfNode;

    if (node->GetName().GetIndex() != 0xFFFFFFFF)
    {
        const auto &nameVector = m_Header.GetStrings()[node->GetName().GetIndex()].GetValue();
        gltfNode.name = std::string(nameVector.begin(), nameVector.end());
    }
    else
    {
        gltfNode.name = type;
    }

    ExportNodeTransformations(node, model, buffer, gltfNode);

    if (auto *niTriShape = dynamic_cast<NiTriShape *>(node))
    {
        gltfNode.mesh = ExportNiTriShape(niTriShape, model, buffer, gltfNode);
    }
    else if (auto *niTriStrips = dynamic_cast<NiTriStrips *>(node))
    {
        gltfNode.mesh = ExportNiTriStrips(niTriStrips, model, buffer, gltfNode);
    }

    auto *niNode = dynamic_cast<NiNode *>(node);

    auto *lodNode = dynamic_cast<NiLODNode *>(node);

    hasLOD = false;

    if (lodNode != nullptr)
    {
        if (auto *rangeData = dynamic_cast<NiRangeLODData *>(lodNode->GetLODLevelData().Query(m_Blocks)))
        {
            hasLOD = true;
        }
    }

    if (niNode != nullptr)
    {
        int32_t childPos = 0;

        for (const auto &child : niNode->GetChildren())
        {
            NiAVObject *childNode = child.Query(m_Blocks);

            if (!childNode)
            {
                continue;
            }

            m_ParentMap[childNode] = niNode;

            int32_t childIndex = ExportGLTFHeirarchy(childNode, m_BlockNames[childNode], model, buffer, childPos, levelOfDetail, hasLOD);

            if (childIndex != -1)
            {
                gltfNode.children.push_back(childIndex);
            }

            childPos++;
        }
    }

    int32_t nodeIndex = m_NodeMap[node];

    model.nodes[nodeIndex] = gltfNode;

    return nodeIndex;
}

void nejlika::geometry::Converter::AllocateNodeIndices(NiAVObject *node, tinygltf::Model &model, nejlika::Writer &buffer)
{
    if (m_NodeMap.find(node) != m_NodeMap.end())
    {
        return;
    }

    tinygltf::Node gltfNode;

    if (node->GetName().GetIndex() != 0xFFFFFFFF)
    {
        const auto &nameVector = m_Header.GetStrings()[node->GetName().GetIndex()].GetValue();
        gltfNode.name = std::string(nameVector.begin(), nameVector.end());
    }
    else
    {
        gltfNode.name = "Node";
    }

    ExportNodeTransformations(node, model, buffer, gltfNode);

    int32_t nodeIndex = model.nodes.size();

    model.nodes.push_back(gltfNode);

    m_NodeMap.insert({node, nodeIndex});

    /*
    auto* niNode = dynamic_cast<NiNode*>(node);

    if (niNode != nullptr)
    {
        for (const auto& child : niNode->GetChildren())
        {
            NiAVObject* childNode = child.Query(m_Blocks);

            if (!childNode)
            {
                continue;
            }

            AllocateNodeIndices(childNode, model, buffer);
        }
    }*/
}

std::vector<double> nejlika::geometry::Converter::RotationMatrixToQuaternion(const std::array<std::array<float, 3>, 3> &matrix)
{
    std::vector<double> q(4);

    double trace = matrix[0][0] + matrix[1][1] + matrix[2][2]; // Trace of the matrix
    if (trace > 0.0)
    {
        double s = std::sqrt(trace + 1.0) * 2.0; // s = 4 * q[3]
        q[3] = 0.25 * s;
        q[0] = (matrix[2][1] - matrix[1][2]) / s;
        q[1] = (matrix[0][2] - matrix[2][0]) / s;
        q[2] = (matrix[1][0] - matrix[0][1]) / s;
    }
    else if ((matrix[0][0] > matrix[1][1]) && (matrix[0][0] > matrix[2][2]))
    {
        double s = std::sqrt(1.0 + matrix[0][0] - matrix[1][1] - matrix[2][2]) * 2.0; // s = 4 * q[0]
        q[3] = (matrix[2][1] - matrix[1][2]) / s;
        q[0] = 0.25 * s;
        q[1] = (matrix[0][1] + matrix[1][0]) / s;
        q[2] = (matrix[0][2] + matrix[2][0]) / s;
    }
    else if (matrix[1][1] > matrix[2][2])
    {
        double s = std::sqrt(1.0 + matrix[1][1] - matrix[0][0] - matrix[2][2]) * 2.0; // s = 4 * q[1]
        q[3] = (matrix[0][2] - matrix[2][0]) / s;
        q[0] = (matrix[0][1] + matrix[1][0]) / s;
        q[1] = 0.25 * s;
        q[2] = (matrix[1][2] + matrix[2][1]) / s;
    }
    else
    {
        double s = std::sqrt(1.0 + matrix[2][2] - matrix[0][0] - matrix[1][1]) * 2.0; // s = 4 * q[2]
        q[3] = (matrix[1][0] - matrix[0][1]) / s;
        q[0] = (matrix[0][2] + matrix[2][0]) / s;
        q[1] = (matrix[1][2] + matrix[2][1]) / s;
        q[2] = 0.25 * s;
    }

    return q;
}

int32_t nejlika::geometry::Converter::ExportGLTFVertices(const std::vector<nejlika::geometry::Vector3> &vertices, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    std::vector<float> minValue = {std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};
    std::vector<float> maxValue = {std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min()};

    for (const auto &vertex : vertices)
    {
        buffer.Write(vertex.Getx());
        buffer.Write(vertex.Gety());
        buffer.Write(vertex.Getz());

        minValue[0] = std::min(minValue[0], vertex.Getx());
        minValue[1] = std::min(minValue[1], vertex.Gety());
        minValue[2] = std::min(minValue[2], vertex.Getz());

        maxValue[0] = std::max(maxValue[0], vertex.Getx());
        maxValue[1] = std::max(maxValue[1], vertex.Gety());
        maxValue[2] = std::max(maxValue[2], vertex.Getz());
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = vertices.size();
    accessor.type = TINYGLTF_TYPE_VEC3;
    accessor.minValues = {minValue[0], minValue[1], minValue[2]};
    accessor.maxValues = {maxValue[0], maxValue[1], maxValue[2]};
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t nejlika::geometry::Converter::ExportGLTFIndices(const std::vector<uint16_t> &indices, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto &index : indices)
    {
        buffer.Write(index);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT;
    accessor.count = indices.size();
    accessor.type = TINYGLTF_TYPE_SCALAR;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t nejlika::geometry::Converter::ExportGLTFIndices(const std::vector<Triangle> &indices, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto &triangle : indices)
    {
        buffer.Write(static_cast<uint16_t>(triangle.Getv1()));
        buffer.Write(static_cast<uint16_t>(triangle.Getv2()));
        buffer.Write(static_cast<uint16_t>(triangle.Getv3()));
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT;
    accessor.count = indices.size() * 3;
    accessor.type = TINYGLTF_TYPE_SCALAR;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t nejlika::geometry::Converter::ExportGLTFNormals(const std::vector<nejlika::geometry::Vector3> &normals, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto &normal : normals)
    {
        float x = normal.Getx();
        float y = normal.Gety();
        float z = normal.Getz();
        float len = std::sqrt(x * x + y * y + z * z);
        if (len > 0.0f)
        {
            x /= len;
            y /= len;
            z /= len;
        }
        buffer.Write(x);
        buffer.Write(y);
        buffer.Write(z);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = normals.size();
    accessor.type = TINYGLTF_TYPE_VEC3;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t nejlika::geometry::Converter::ExportGLTFUVs(const std::vector<nejlika::geometry::TexCoord> &uvs, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto &uv : uvs)
    {
        buffer.Write(uv.Getu());
        buffer.Write(uv.Getv());
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = uvs.size();
    accessor.type = TINYGLTF_TYPE_VEC2;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t nejlika::geometry::Converter::ExportGLTFColors(const std::vector<nejlika::geometry::Color4> &colors, tinygltf::Model &model, nejlika::Writer &buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto &color : colors)
    {
        buffer.Write(color.Getr());
        buffer.Write(color.Getg());
        buffer.Write(color.Getb());
        buffer.Write(color.Geta());
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = colors.size();
    accessor.type = TINYGLTF_TYPE_VEC4;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

void nejlika::geometry::Converter::ExportNiTriBasedGeomData(const NiTriBasedGeomData *data, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Primitive &primitive)
{
    if (data->GetHasVertices())
    {
        primitive.attributes["POSITION"] = ExportGLTFVertices(data->GetVertices(), model, buffer);
    }

    if (data->GetHasNormals())
    {
        primitive.attributes["NORMAL"] = ExportGLTFNormals(data->GetNormals(), model, buffer);
    }

    if (data->GetHasUV() || data->GetUVSets().size() > 0)
    {
        primitive.attributes["TEXCOORD_0"] = ExportGLTFUVs(data->GetUVSets()[0], model, buffer);
    }

    if (data->GetHasVertexColors())
    {
        primitive.attributes["COLOR_0"] = ExportGLTFColors(data->GetVertexColors(), model, buffer);
    }
}

void nejlika::geometry::Converter::ExportNiTriShapeData(const NiTriShapeData *data, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Primitive &primitive)
{
    if (data->GetHasTriangles())
    {
        primitive.indices = ExportGLTFIndices(data->GetTriangles(), model, buffer);
    }

    ExportNiTriBasedGeomData(data, model, buffer, primitive);
}

void nejlika::geometry::Converter::ExportNiTriStripsData(const NiTriStripsData *data, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Primitive &primitive)
{
    if (data->GetHasPoints())
    {
        std::vector<uint16_t> indices;
        indices.reserve(data->GetPoints().size() * 3);

        for (const auto &strip : data->GetPoints())
        {
            int32_t index = 1;

            bool flip = false;

            while (index + 1 < strip.size())
            {
                if (!flip)
                {
                    indices.push_back(strip[index - 1]);
                    indices.push_back(strip[index]);
                    indices.push_back(strip[index + 1]);
                }
                else
                {
                    indices.push_back(strip[index + 1]);
                    indices.push_back(strip[index]);
                    indices.push_back(strip[index - 1]);
                }

                flip = !flip;

                index++;
            }
        }

        primitive.indices = ExportGLTFIndices(indices, model, buffer);
    }

    ExportNiTriBasedGeomData(data, model, buffer, primitive);
}

void nejlika::geometry::Converter::ExportMaterial(const NiAVObject *node, tinygltf::Model &model, tinygltf::Primitive &primitive, nejlika::Writer &buffer, const std::vector<Vector3> &vertices)
{
    bool hasMaterial = false;

    int32_t materialIndex = model.materials.size();

    tinygltf::Material material;
    material.name = "Material";
    material.pbrMetallicRoughness.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
    material.pbrMetallicRoughness.baseColorTexture.index = -1;
    material.pbrMetallicRoughness.metallicFactor = 0.0f;
    material.pbrMetallicRoughness.roughnessFactor = 0.0f;
    material.alphaMode = "OPAQUE";
    material.doubleSided = true;

    for (const auto &propertyPtr : node->GetProperties())
    {
        auto *property = propertyPtr.Query(m_Blocks);

        if (!property)
        {
            continue;
        }

        std::string name = m_BlockNames[property];

        if (auto *niAlphaProperty = dynamic_cast<NiAlphaProperty *>(property))
        {
            material.alphaCutoff = niAlphaProperty->GetThreshold();
            hasMaterial = true;
        }
        else if (auto *niMaterialProperty = dynamic_cast<NiMaterialProperty *>(property))
        {
            const auto &ambient = niMaterialProperty->GetAmbientColor();
            const auto &diffuse = niMaterialProperty->GetDiffuseColor();
            const auto &specular = niMaterialProperty->GetSpecularColor();
            const auto &emissive = niMaterialProperty->GetEmissiveColor();
            const auto &shininess = niMaterialProperty->GetGlossiness();
            const auto &alpha = niMaterialProperty->GetAlpha();

            if (diffuse.Getr() == 0 && diffuse.Getg() == 0 && diffuse.Getb() == 0)
            {
                material.pbrMetallicRoughness.baseColorFactor = {1, 1, 1, alpha};
            }
            else
            {
                // Base color and alpha
                material.pbrMetallicRoughness.baseColorFactor = {diffuse.Getr(), diffuse.Getg(), diffuse.Getb(), alpha};
            }

            // Metallic and roughness from shininess
            material.pbrMetallicRoughness.metallicFactor = 0.0f;
            material.pbrMetallicRoughness.roughnessFactor = 1.0f - shininess / 128.0f;

            // Emissive color
            // material.emissiveFactor = { emissive.Getr(), emissive.Getg(), emissive.Getb() };

            // Alpha mode
            material.alphaMode = (alpha < 1.0f) ? "BLEND" : "OPAQUE";

            // Double-sided setting
            material.doubleSided = true;

            hasMaterial = true;

            if (auto *niTimeController = niMaterialProperty->GetController().Query(m_Blocks))
            {
                if (auto *niAlphaController = dynamic_cast<NiAlphaController *>(niTimeController))
                {
                    auto *niFloatInterpolator = dynamic_cast<NiFloatInterpolator *>(niAlphaController->GetInterpolator().Query(m_Blocks));

                    if (!niFloatInterpolator)
                    {
                        continue;
                    }

                    auto *alphaData = dynamic_cast<NiFloatData *>(niFloatInterpolator->GetData().Query(m_Blocks));

                    if (!alphaData)
                    {
                        continue;
                    }

                    m_OnAnimationExport.push_back(
                        [this, alphaData, niAlphaController, materialIndex, diffuse](tinygltf::Model &model, tinygltf::Animation &animation, nejlika::Writer &buffer)
                        {
                            std::vector<float> times;
                            std::vector<float> values;

                            for (const auto &key : alphaData->GetData().GetKeys())
                            {
                                times.push_back(key.GetTime());
                                values.push_back(diffuse.Getr());
                                values.push_back(diffuse.Getg());
                                values.push_back(diffuse.Getb());
                                values.push_back(key.GetValue());
                            }

                            // Write time buffer
                            int32_t timeBufferStart = buffer.GetWriteHead();
                            for (const auto &time : times)
                                buffer.Write(time);
                            AlignBuffer(buffer);
                            int32_t timeBufferEnd = buffer.GetWriteHead();

                            tinygltf::BufferView timeBufferView;
                            timeBufferView.buffer = 0;
                            timeBufferView.byteOffset = timeBufferStart;
                            timeBufferView.byteLength = timeBufferEnd - timeBufferStart;
                            model.bufferViews.push_back(timeBufferView);
                            int32_t timeBufferIndex = model.bufferViews.size() - 1;

                            tinygltf::Accessor timeAccessor;
                            timeAccessor.bufferView = timeBufferIndex;
                            timeAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                            timeAccessor.count = times.size();
                            timeAccessor.type = TINYGLTF_TYPE_SCALAR;
                            timeAccessor.minValues = {*std::min_element(times.begin(), times.end())};
                            timeAccessor.maxValues = {*std::max_element(times.begin(), times.end())};
                            model.accessors.push_back(timeAccessor);
                            int32_t timeAccessorIndex = model.accessors.size() - 1;

                            // Write value buffer
                            int32_t valueBufferStart = buffer.GetWriteHead();
                            for (const auto &value : values)
                                buffer.Write(value);
                            AlignBuffer(buffer);
                            int32_t valueBufferEnd = buffer.GetWriteHead();

                            tinygltf::BufferView valueBufferView;
                            valueBufferView.buffer = 0;
                            valueBufferView.byteOffset = valueBufferStart;
                            valueBufferView.byteLength = valueBufferEnd - valueBufferStart;
                            model.bufferViews.push_back(valueBufferView);
                            int32_t valueBufferIndex = model.bufferViews.size() - 1;

                            tinygltf::Accessor valueAccessor;
                            valueAccessor.bufferView = valueBufferIndex;
                            valueAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                            valueAccessor.count = values.size() / 4;
                            valueAccessor.type = TINYGLTF_TYPE_VEC4;
                            model.accessors.push_back(valueAccessor);
                            int32_t valueAccessorIndex = model.accessors.size() - 1;

                            // Use KHR_animation_pointer to animate the alpha value
                            tinygltf::AnimationChannel channel;
                            channel.sampler = animation.samplers.size();
                            channel.target_path = "pointer";
                            channel.target_extensions["KHR_animation_pointer"] = tinygltf::Value({{"pointer", tinygltf::Value("/materials/" + std::to_string(materialIndex) + "/pbrMetallicRoughness/baseColorFactor")}});

                            const auto &extensionsUsedIt = std::find(model.extensionsUsed.begin(), model.extensionsUsed.end(), "KHR_animation_pointer");
                            if (extensionsUsedIt == model.extensionsUsed.end())
                                model.extensionsUsed.push_back("KHR_animation_pointer");

                            tinygltf::AnimationSampler sampler;
                            sampler.input = timeAccessorIndex;
                            sampler.output = valueAccessorIndex;
                            sampler.interpolation = "LINEAR";

                            animation.channels.push_back(channel);
                            animation.samplers.push_back(sampler);
                        });
                }
            }
        }
        else if (auto *niTexturingProperty = dynamic_cast<NiTexturingProperty *>(property))
        {
            if (!niTexturingProperty->GetHasBaseTexture())
            {
                continue;
            }

            auto *niTextureTransformController = dynamic_cast<NiTextureTransformController *>(niTexturingProperty->GetController().Query(m_Blocks));

            if (niTextureTransformController != nullptr)
            {
                if (niTextureTransformController->GetOperation() == TT_TRANSLATE_V)
                {
                    auto *nextController = dynamic_cast<NiTextureTransformController *>(niTextureTransformController->GetNextController().Query(m_Blocks));

                    if (nextController != nullptr)
                    {

                        auto *vInterpolator = dynamic_cast<NiFloatInterpolator *>(niTextureTransformController->GetInterpolator().Query(m_Blocks));
                        auto *vData = vInterpolator == nullptr ? nullptr : dynamic_cast<NiFloatData *>(vInterpolator->GetData().Query(m_Blocks));
                        const std::vector<Key<float>> vKey = vData == nullptr ? std::vector<Key<float>>{} : vData->GetData().GetKeys();
                        auto *uInterpolator = dynamic_cast<NiFloatInterpolator *>(nextController->GetInterpolator().Query(m_Blocks));
                        auto *uData = uInterpolator == nullptr ? nullptr : dynamic_cast<NiFloatData *>(uInterpolator->GetData().Query(m_Blocks));
                        const std::vector<Key<float>> uKey = uData == nullptr ? std::vector<Key<float>>{} : uData->GetData().GetKeys();

                        m_OnAnimationExport.push_back(
                            [this, uKey, vKey, materialIndex](tinygltf::Model &model, tinygltf::Animation &animation, nejlika::Writer &buffer)
                            {
                                std::vector<float> times;
                                std::vector<float> values;

                                // u and v may have different key counts, use interpolation to match the key count
                                std::set<float> timeSet;
                                for (const auto &key : uKey)
                                {
                                    timeSet.insert(key.GetTime());
                                }

                                for (const auto &key : vKey)
                                {
                                    timeSet.insert(key.GetTime());
                                }

                                for (const auto &time : timeSet)
                                {
                                    times.push_back(time);

                                    float uValue = 0.0f;
                                    float vValue = 0.0f;

                                    // Interpolate u
                                    if (uKey.size() > 0)
                                    {
                                        for (size_t i = 0; i < uKey.size() - 1; i++)
                                        {
                                            if (time >= uKey[i].GetTime() && time <= uKey[i + 1].GetTime())
                                            {
                                                float t = (time - uKey[i].GetTime()) / (uKey[i + 1].GetTime() - uKey[i].GetTime());
                                                uValue = uKey[i].GetValue() + t * (uKey[i + 1].GetValue() - uKey[i].GetValue());
                                                break;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        uValue = 0.0f;
                                    }

                                    // Interpolate v
                                    if (vKey.size() > 0)
                                    {
                                        for (size_t i = 0; i < vKey.size() - 1; i++)
                                        {
                                            if (time >= vKey[i].GetTime() && time <= vKey[i + 1].GetTime())
                                            {
                                                float t = (time - vKey[i].GetTime()) / (vKey[i + 1].GetTime() - vKey[i].GetTime());
                                                vValue = vKey[i].GetValue() + t * (vKey[i + 1].GetValue() - vKey[i].GetValue());
                                                break;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        vValue = 0.0f;
                                    }

                                    values.push_back(uValue);
                                    values.push_back(vValue);
                                }

                                if (times.size() == 0)
                                {
                                    return;
                                }

                                // Write time buffer
                                int32_t timeBufferStart = buffer.GetWriteHead();
                                for (const auto &time : times)
                                    buffer.Write(time);
                                AlignBuffer(buffer);
                                int32_t timeBufferEnd = buffer.GetWriteHead();

                                tinygltf::BufferView timeBufferView;
                                timeBufferView.buffer = 0;
                                timeBufferView.byteOffset = timeBufferStart;
                                timeBufferView.byteLength = timeBufferEnd - timeBufferStart;
                                model.bufferViews.push_back(timeBufferView);
                                int32_t timeBufferIndex = model.bufferViews.size() - 1;

                                tinygltf::Accessor timeAccessor;
                                timeAccessor.bufferView = timeBufferIndex;
                                timeAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                                timeAccessor.count = times.size();
                                timeAccessor.type = TINYGLTF_TYPE_SCALAR;
                                timeAccessor.minValues = {*std::min_element(times.begin(), times.end())};
                                timeAccessor.maxValues = {*std::max_element(times.begin(), times.end())};
                                model.accessors.push_back(timeAccessor);
                                int32_t timeAccessorIndex = model.accessors.size() - 1;

                                // Write value buffer
                                int32_t valueBufferStart = buffer.GetWriteHead();
                                for (const auto &value : values)
                                    buffer.Write(value);
                                AlignBuffer(buffer);
                                int32_t valueBufferEnd = buffer.GetWriteHead();

                                tinygltf::BufferView valueBufferView;
                                valueBufferView.buffer = 0;
                                valueBufferView.byteOffset = valueBufferStart;
                                valueBufferView.byteLength = valueBufferEnd - valueBufferStart;
                                model.bufferViews.push_back(valueBufferView);
                                int32_t valueBufferIndex = model.bufferViews.size() - 1;

                                tinygltf::Accessor valueAccessor;
                                valueAccessor.bufferView = valueBufferIndex;
                                valueAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                                valueAccessor.count = values.size() / 2;
                                valueAccessor.type = TINYGLTF_TYPE_VEC2;
                                model.accessors.push_back(valueAccessor);
                                int32_t valueAccessorIndex = model.accessors.size() - 1;

                                // Use KHR_animation_pointer to animate the UV values
                                tinygltf::AnimationChannel channel;
                                channel.sampler = animation.samplers.size();
                                channel.target_path = "pointer";
                                channel.target_extensions["KHR_animation_pointer"] = tinygltf::Value({{"pointer", tinygltf::Value("/materials/" + std::to_string(materialIndex) + "/pbrMetallicRoughness/baseColorTexture/extensions/KHR_texture_transform/offset")}});

                                const auto &extensionsUsedIt = std::find(model.extensionsUsed.begin(), model.extensionsUsed.end(), "KHR_animation_pointer");
                                if (extensionsUsedIt == model.extensionsUsed.end())
                                    model.extensionsUsed.push_back("KHR_animation_pointer");

                                tinygltf::AnimationSampler sampler;
                                sampler.input = timeAccessorIndex;
                                sampler.output = valueAccessorIndex;
                                sampler.interpolation = "LINEAR";

                                animation.channels.push_back(channel);
                                animation.samplers.push_back(sampler);
                            });
                    }
                }
            }

            const auto &niTexture = niTexturingProperty->GetBaseTexture();

            const auto &tiling = niTexture.GetTiling(); // For example 100, 100

            // Add texture transform extension
            material.pbrMetallicRoughness.baseColorTexture.extensions["KHR_texture_transform"] = tinygltf::Value({{"offset", tinygltf::Value(std::vector<tinygltf::Value>{
                                                                                                                                 {tinygltf::Value(0.0f)},
                                                                                                                                 {tinygltf::Value(0.0f)}})},
                                                                                                                  {"scale", tinygltf::Value(std::vector<tinygltf::Value>{
                                                                                                                                {tinygltf::Value(niTexture.GetHasTextureTransform() ? tiling.Getu() : 1.0f)},
                                                                                                                                {tinygltf::Value(niTexture.GetHasTextureTransform() ? tiling.Getv() : 1.0f)}})}});

            const auto &extensionsUsedIt = std::find(model.extensionsUsed.begin(), model.extensionsUsed.end(), "KHR_texture_transform");
            if (extensionsUsedIt == model.extensionsUsed.end())
                model.extensionsUsed.push_back("KHR_texture_transform");

            if (auto *niSourceTexture = niTexture.GetSource().Query(m_Blocks))
            {
                std::string textureName = GetNifString(niSourceTexture->GetFileName().GetIndex());

                // Make all lowercase
                std::transform(textureName.begin(), textureName.end(), textureName.begin(), ::tolower);

                std::filesystem::path texturePath =
                    std::filesystem::path(m_NifPath).parent_path() /
                    textureName;

                const auto &cacheIt = m_TextureCache.find(texturePath.string());

                if (cacheIt != m_TextureCache.end())
                {
                    material.pbrMetallicRoughness.baseColorTexture.index = cacheIt->second;
                    hasMaterial = true;
                    continue;
                }

                // Check if file exists
                if (!std::filesystem::exists(texturePath))
                {
                    std::cout << "Texture not found: " << texturePath << std::endl;
                    continue;
                }

                uint32_t textureIndex = model.textures.size();
                uint32_t imageIndex = model.images.size();

                tinygltf::Texture texture;
                texture.source = imageIndex;
                model.textures.push_back(texture);

                const auto pair = ConvertDDSToPNG(texturePath.string(), buffer);
                int32_t bufferViewIndex = model.bufferViews.size();

                tinygltf::BufferView bufferView;
                bufferView.buffer = 0;
                bufferView.byteOffset = pair.first;
                bufferView.byteLength = pair.second - pair.first;
                bufferView.byteStride = 0;
                bufferView.target = 0;
                bufferView.name = texturePath.filename().string();

                model.bufferViews.push_back(bufferView);

                tinygltf::Image image;
                image.bufferView = bufferViewIndex;
                image.name = texturePath.filename().string();
                image.mimeType = "image/png";
                model.images.push_back(image);

                int32_t materialIndex = model.materials.size();

                material.pbrMetallicRoughness.baseColorTexture.index = textureIndex;

                m_TextureCache[texturePath.string()] = textureIndex;

                hasMaterial = true;
            }
        }
    }

    // Add material to model
    model.materials.push_back(material);

    primitive.material = materialIndex;
}

int32_t nejlika::geometry::Converter::ExportNiTriShape(const NiTriShape *shape, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Node &gltfNode)
{
    auto *data = shape->GetData().Query(m_Blocks);

    if (!data)
    {
        return -1;

        throw std::runtime_error("Failed to find data for NiTriShape");
    }

    auto *niTriShapeData = dynamic_cast<NiTriShapeData *>(data);

    if (!niTriShapeData)
    {
        return -1;

        throw std::runtime_error("Failed to cast data to NiTriShapeData");
    }

    tinygltf::Primitive primitive;
    primitive.mode = TINYGLTF_MODE_TRIANGLES;

    ExportNiTriShapeData(niTriShapeData, model, buffer, primitive);

    ExportMaterial(shape, model, primitive, buffer, niTriShapeData->GetVertices());

    tinygltf::Mesh mesh;

    if (auto *skinInstance = shape->GetSkinInstance().Query(m_Blocks))
    {
        auto *rootNode = skinInstance->GetSkeletonRoot().Query(m_Blocks);

        if (auto *skinData = skinInstance->GetData().Query(m_Blocks))
        {
            const auto &bones = skinData->GetBoneList();

            if (auto *skinPartition = skinInstance->GetSkinPartition().Query(m_Blocks))
            {
                const auto &blocks = skinPartition->GetSkinPartitionBlocks();

                std::vector<std::array<uint8_t, 4>> jointsBuffer; // For JOINTS_0 (unsigned int, 4 components)
                std::vector<std::array<float, 4>> weightsBuffer;  // For WEIGHTS_0 (float, 4 components)
                jointsBuffer.resize(niTriShapeData->GetNumVertices());
                weightsBuffer.resize(niTriShapeData->GetNumVertices());

                // Fill with a 1 to indicate no bone
                for (auto &joint : jointsBuffer)
                {
                    joint = {0, 0, 0, 0};
                }

                for (auto &weight : weightsBuffer)
                {
                    weight = {1.0f, 0.0f, 0.0f, 0.0f};
                }

                for (const auto &partition : blocks)
                {
                    const auto &vertexMap = partition.GetVertexMap();
                    const auto numWeightsPerVertex = partition.GetNumWeightsPerVertex();

                    for (size_t v = 0; v < partition.GetVertexWeights().size(); v++)
                    {
                        uint16_t vertexIndex = vertexMap[v];

                        std::array<uint8_t, 4> joints = {0, 0, 0, 0};
                        std::array<float, 4> weights = {0.0f, 0.0f, 0.0f, 0.0f};

                        for (size_t w = 0; w < numWeightsPerVertex && w < 4; w++) // Limit to 4
                        {
                            const auto &boneIndex = partition.GetBoneIndices()[v][w];
                            const auto &vertexWeight = partition.GetVertexWeights()[v][w];

                            if (boneIndex < bones.size())
                            {
                                joints[w] = static_cast<uint8_t>(partition.GetBones()[boneIndex]);
                                weights[w] = vertexWeight;
                            }
                        }

                        // Normalize weights
                        /*float weightSum = std::accumulate(weights.begin(), weights.end(), 0.0f);
                        if (weightSum > 0.0f)
                        {
                            for (auto& w : weights)
                                w /= weightSum;
                        }*/

                        jointsBuffer[vertexIndex] = joints;
                        weightsBuffer[vertexIndex] = weights;
                    }
                }

                // Add JOINTS_0 to the model
                int32_t jointsBufferViewIndex = model.bufferViews.size();

                tinygltf::BufferView jointsBufferView;
                jointsBufferView.buffer = 0;
                jointsBufferView.byteOffset = buffer.GetWriteHead();

                for (const auto &joint : jointsBuffer)
                {
                    for (const auto &j : joint)
                    {
                        buffer.Write(j);
                    }
                }

                AlignBuffer(buffer);

                jointsBufferView.byteLength = buffer.GetWriteHead() - jointsBufferView.byteOffset;
                jointsBufferView.byteStride = 0;
                jointsBufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
                model.bufferViews.push_back(jointsBufferView);

                tinygltf::Accessor jointsAccessor;
                jointsAccessor.bufferView = jointsBufferViewIndex;
                jointsAccessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE;
                jointsAccessor.count = jointsBuffer.size();
                jointsAccessor.type = TINYGLTF_TYPE_VEC4;
                jointsAccessor.normalized = false;
                model.accessors.push_back(jointsAccessor);
                primitive.attributes["JOINTS_0"] = model.accessors.size() - 1;

                // Add WEIGHTS_0 to the model
                int32_t weightsBufferViewIndex = model.bufferViews.size();

                tinygltf::BufferView weightsBufferView;
                weightsBufferView.buffer = 0;
                weightsBufferView.byteOffset = buffer.GetWriteHead();

                for (const auto &weight : weightsBuffer)
                {
                    for (const auto &w : weight)
                    {
                        buffer.Write(w);
                    }
                }

                AlignBuffer(buffer);

                weightsBufferView.byteLength = buffer.GetWriteHead() - weightsBufferView.byteOffset;
                weightsBufferView.byteStride = 0;
                weightsBufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
                model.bufferViews.push_back(weightsBufferView);

                tinygltf::Accessor weightsAccessor;
                weightsAccessor.bufferView = weightsBufferViewIndex;
                weightsAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                weightsAccessor.count = weightsBuffer.size();
                weightsAccessor.type = TINYGLTF_TYPE_VEC4;
                weightsAccessor.normalized = false; // Weights are not normalized
                model.accessors.push_back(weightsAccessor);
                primitive.attributes["WEIGHTS_0"] = model.accessors.size() - 1;

                // Add inverse bind matrices
                std::vector<float> inverseBindMatrices;
                inverseBindMatrices.reserve(bones.size() * 16);

                int32_t i = 0;
                for (const auto &bone : bones)
                {
                    auto *node = skinInstance->GetBones()[i].Query(m_Blocks);
                    ++i;

                    // Construct the bind matrix
                    const auto &translation = bone.GetSkinTransform().GetTranslation();
                    const auto &rotation = bone.GetSkinTransform().GetRotation();
                    const auto &scale = bone.GetSkinTransform().GetScale();

                    glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(translation.Getx(), translation.Gety(), translation.Getz()));

                    // Convert rotation matrix to quaternion
                    glm::mat3 rotationMatrix = glm::mat3(
                        rotation.Getm11(), rotation.Getm12(), rotation.Getm13(),
                        rotation.Getm21(), rotation.Getm22(), rotation.Getm23(),
                        rotation.Getm31(), rotation.Getm32(), rotation.Getm33());

                    glm::quat q = glm::quat_cast(rotationMatrix);

                    glm::mat4 R = glm::mat4_cast(q);

                    glm::mat4 S = glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, scale));

                    glm::mat4 bindMatrix = T * R * S;

                    // glm::mat4 bindMatrix = ComputeGlobalTransform(node);

                    // Compute the inverse bind matrix
                    glm::mat4 inverseBindMatrix = bindMatrix; // glm::inverse(bindMatrix);

                    // Store in column-major order
                    for (int col = 0; col < 4; ++col)
                    {
                        for (int row = 0; row < 4; ++row)
                        {
                            inverseBindMatrices.push_back(inverseBindMatrix[col][row]);
                        }
                    }
                }

                int32_t inverseBindMatricesBufferViewIndex = model.bufferViews.size();

                tinygltf::BufferView inverseBindMatricesBufferView;
                inverseBindMatricesBufferView.buffer = 0;
                inverseBindMatricesBufferView.byteOffset = buffer.GetWriteHead();

                for (const auto &matrix : inverseBindMatrices)
                {
                    buffer.Write(matrix);
                }

                AlignBuffer(buffer);

                inverseBindMatricesBufferView.byteLength = buffer.GetWriteHead() - inverseBindMatricesBufferView.byteOffset;
                inverseBindMatricesBufferView.byteStride = 0;
                inverseBindMatricesBufferView.target = 0;
                model.bufferViews.push_back(inverseBindMatricesBufferView);

                tinygltf::Accessor inverseBindMatricesAccessor;
                inverseBindMatricesAccessor.bufferView = inverseBindMatricesBufferViewIndex;
                inverseBindMatricesAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
                inverseBindMatricesAccessor.count = bones.size();
                inverseBindMatricesAccessor.type = TINYGLTF_TYPE_MAT4;
                inverseBindMatricesAccessor.normalized = false;
                model.accessors.push_back(inverseBindMatricesAccessor);

                // Add skin
                tinygltf::Skin skin;

                skin.inverseBindMatrices = model.accessors.size() - 1;
                std::vector<int> joints;
                std::vector<NiNode *> jointsNiAVObjects;
                for (int i = 0; i < bones.size(); i++)
                {
                    auto *node = skinInstance->GetBones()[i].Query(m_Blocks);
                    joints.push_back(m_NodeMap[node]);
                    jointsNiAVObjects.push_back(dynamic_cast<NiNode *>(node));
                }
                skin.joints = joints;
                auto *skeletonNode = FindClosestCommonParent(rootNode, jointsNiAVObjects);
                skin.skeleton = skeletonNode == nullptr ? m_NodeMap[rootNode] : m_NodeMap[skeletonNode];
                model.skins.push_back(skin);

                gltfNode.skin = model.skins.size() - 1;
            }
        }
    }

    int32_t meshIndex = model.meshes.size();

    mesh.primitives.push_back(primitive);
    model.meshes.push_back(mesh);

    return meshIndex;
}

int32_t nejlika::geometry::Converter::ExportNiTriStrips(const NiTriStrips *strips, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Node &gltfNode)
{
    auto *data = strips->GetData().Query(m_Blocks);

    if (!data)
    {
        return -1;

        throw std::runtime_error("Failed to find data for NiTriStrips");
    }

    auto *niTriStripsData = dynamic_cast<NiTriStripsData *>(data);

    if (!niTriStripsData)
    {
        return -1;

        throw std::runtime_error("Failed to cast data to NiTriStripsData");
    }

    tinygltf::Primitive primitive;
    primitive.mode = TINYGLTF_MODE_TRIANGLES;

    ExportNiTriStripsData(niTriStripsData, model, buffer, primitive);

    ExportMaterial(strips, model, primitive, buffer, niTriStripsData->GetVertices());

    int32_t meshIndex = model.meshes.size();

    tinygltf::Mesh mesh;
    mesh.primitives.push_back(primitive);
    model.meshes.push_back(mesh);

    return meshIndex;
}

void nejlika::geometry::Converter::ExportNodeTransformations(const NiAVObject *node, tinygltf::Model &model, nejlika::Writer &buffer, tinygltf::Node &gltfNode)
{
    const auto &translation = node->GetTranslation();
    const auto &rotation = node->GetRotation();
    const auto &scale = node->GetScale();

    gltfNode.translation = {translation.Getx(), translation.Gety(), translation.Getz()};
    gltfNode.scale = {scale, scale, scale};

    /*std::array<std::array<float, 3>, 3> array;
    array[0][0] = rotation.Getm11();
    array[0][1] = rotation.Getm12();
    array[0][2] = rotation.Getm13();
    array[1][0] = rotation.Getm21();
    array[1][1] = rotation.Getm22();
    array[1][2] = rotation.Getm23();
    array[2][0] = rotation.Getm31();
    array[2][1] = rotation.Getm32();
    array[2][2] = rotation.Getm33();
    gltfNode.rotation = RotationMatrixToQuaternion(array);*/

    // Use glm to convert rotation matrix to quaternion
    glm::mat3 rotationMatrix = {
        {rotation.Getm11(), rotation.Getm12(), rotation.Getm13()},
        {rotation.Getm21(), rotation.Getm22(), rotation.Getm23()},
        {rotation.Getm31(), rotation.Getm32(), rotation.Getm33()}};

    glm::quat quaternion = glm::quat_cast(rotationMatrix);
    gltfNode.rotation = {quaternion.x, quaternion.y, quaternion.z, quaternion.w};
}

void nejlika::geometry::Converter::ExportAnimation(const std::string &name, const nejlika::geometry::Header &header, const std::vector<nejlika::geometry::Construct *> &blocks, tinygltf::Model &model, nejlika::Writer &buffer)
{
    std::map<int32_t, KeyframeSet> keyframeMap; // Map of node index to combined keyframe data

    // Stage 1: Collect and merge keyframe data
    for (auto *block : blocks)
    {
        if (NiControllerSequence *sequence = dynamic_cast<NiControllerSequence *>(block))
        {
            for (const auto &controllerBlock : sequence->GetControlledBlocks())
            {
                int32_t nodeNameIndex = controllerBlock.GetNodeName().GetIndex();
                if (nodeNameIndex >= header.GetStrings().size())
                    continue;

                const auto &nodeName = GetNifString(header, nodeNameIndex);

                // Find the corresponding node in the model
                auto nodeIt = std::find_if(model.nodes.begin(), model.nodes.end(),
                                           [&nodeName](const tinygltf::Node &node)
                                           { return node.name == nodeName; });
                if (nodeIt == model.nodes.end())
                    continue;

                int32_t nodeIndex = std::distance(model.nodes.begin(), nodeIt);
                auto *interpolator = controllerBlock.GetInterpolator().Query(blocks);
                if (!interpolator)
                    continue;

                if (NiTransformInterpolator *transformInterpolator = dynamic_cast<NiTransformInterpolator *>(interpolator))
                {
                    NiTransformData *data = transformInterpolator->GetData().Query(blocks);
                    if (!data)
                        continue;

                    auto &keyframes = keyframeMap[nodeIndex];

                    // Collect translations
                    for (const auto &key : data->GetTranslations().GetKeys())
                    {
                        float time = key.GetTime();
                        const auto &value = key.GetValue();
                        keyframes.translations[time] = {value.Getx(), value.Gety(), value.Getz()};
                    }

                    // Collect rotations
                    for (const auto &key : data->GetQuaternionKeys())
                    {
                        float time = key.GetTime();
                        const auto &value = key.GetValue();
                        keyframes.rotations[time] = {value.Getx(), value.Gety(), value.Getz(), value.Getw()};
                    }

                    // Collect scales
                    for (const auto &key : data->GetScales().GetKeys())
                    {
                        float time = key.GetTime();
                        float scaleValue = key.GetValue();
                        keyframes.scales[time] = {scaleValue, scaleValue, scaleValue};
                    }
                }
            }
        }
    }

    // Stage 2: Write combined data to glTF
    tinygltf::Animation animation;
    animation.name = std::filesystem::path(name).filename().string();

    for (const auto &[nodeIndex, keyframes] : keyframeMap)
    {
        // Prepare buffers
        std::set<float> translationTimes, rotationTimes, scaleTimes;
        std::vector<float> translations, rotations, scales;

        // Collect times and values
        for (const auto &[time, value] : keyframes.translations)
        {
            translationTimes.insert(time);
            translations.push_back(value[0]);
            translations.push_back(value[1]);
            translations.push_back(value[2]);
        }

        for (const auto &[time, value] : keyframes.rotations)
        {
            rotationTimes.insert(time);
            rotations.push_back(value[0]);
            rotations.push_back(value[1]);
            rotations.push_back(value[2]);
            rotations.push_back(value[3]);
        }

        for (const auto &[time, value] : keyframes.scales)
        {
            scaleTimes.insert(time);
            scales.push_back(value[0]);
            scales.push_back(value[1]);
            scales.push_back(value[2]);
        }

        // Convert sets to vectors
        std::vector<float> translationTimesVec(translationTimes.begin(), translationTimes.end());
        std::vector<float> rotationTimesVec(rotationTimes.begin(), rotationTimes.end());
        std::vector<float> scaleTimesVec(scaleTimes.begin(), scaleTimes.end());

        // Write translation channel
        if (!translations.empty())
        {
            WriteAnimationData(buffer, model, animation, nodeIndex, "translation", {translationTimesVec, translations, 3});
        }

        // Write rotation channel
        if (!rotations.empty())
        {
            WriteAnimationData(buffer, model, animation, nodeIndex, "rotation", {rotationTimesVec, rotations, 4});
        }

        // Write scale channel
        if (!scales.empty())
        {
            WriteAnimationData(buffer, model, animation, nodeIndex, "scale", {scaleTimesVec, scales, 3});
        }
    }

    for (const auto &extension : m_OnAnimationExport)
    {
        extension(model, animation, buffer);
    }

    model.animations.push_back(animation);
}

void nejlika::geometry::Converter::WriteAnimationData(
    nejlika::Writer &buffer, tinygltf::Model &model, tinygltf::Animation &animation,
    int32_t nodeIndex, const std::string &targetPath, const KeyframeData &data)
{
    const auto &[times, values, components] = data;

    // Write time buffer
    int32_t timeBufferStart = buffer.GetWriteHead();
    for (const auto &time : times)
        buffer.Write(time);
    AlignBuffer(buffer);
    int32_t timeBufferEnd = buffer.GetWriteHead();

    tinygltf::BufferView timeBufferView;
    timeBufferView.buffer = 0;
    timeBufferView.byteOffset = timeBufferStart;
    timeBufferView.byteLength = timeBufferEnd - timeBufferStart;
    model.bufferViews.push_back(timeBufferView);
    int32_t timeBufferIndex = model.bufferViews.size() - 1;

    tinygltf::Accessor timeAccessor;
    timeAccessor.bufferView = timeBufferIndex;
    timeAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    timeAccessor.count = times.size();
    timeAccessor.type = TINYGLTF_TYPE_SCALAR;
    timeAccessor.minValues = {*std::min_element(times.begin(), times.end())};
    timeAccessor.maxValues = {*std::max_element(times.begin(), times.end())};
    model.accessors.push_back(timeAccessor);
    int32_t timeAccessorIndex = model.accessors.size() - 1;

    // Write value buffer
    int32_t valueBufferStart = buffer.GetWriteHead();
    for (const auto &value : values)
        buffer.Write(value);
    AlignBuffer(buffer);
    int32_t valueBufferEnd = buffer.GetWriteHead();

    tinygltf::BufferView valueBufferView;
    valueBufferView.buffer = 0;
    valueBufferView.byteOffset = valueBufferStart;
    valueBufferView.byteLength = valueBufferEnd - valueBufferStart;
    model.bufferViews.push_back(valueBufferView);
    int32_t valueBufferIndex = model.bufferViews.size() - 1;

    tinygltf::Accessor valueAccessor;
    valueAccessor.bufferView = valueBufferIndex;
    valueAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    valueAccessor.count = values.size() / components;
    valueAccessor.type = (components == 3 ? TINYGLTF_TYPE_VEC3 : TINYGLTF_TYPE_VEC4);
    model.accessors.push_back(valueAccessor);
    int32_t valueAccessorIndex = model.accessors.size() - 1;

    // Create sampler and channel
    tinygltf::AnimationSampler sampler;
    sampler.input = timeAccessorIndex;
    sampler.output = valueAccessorIndex;
    sampler.interpolation = "LINEAR";
    animation.samplers.push_back(sampler);

    tinygltf::AnimationChannel channel;
    channel.sampler = animation.samplers.size() - 1;
    channel.target_node = nodeIndex;
    channel.target_path = targetPath;
    animation.channels.push_back(channel);
}

std::pair<int32_t, int32_t> nejlika::geometry::Converter::ConvertDDSToPNG(const std::string &ddsPath, nejlika::Writer &buffer)
{
    // Use "convert" to convert the DDS to PNG in memory
    std::string command = "convert " + ddsPath + " png:-";

    FILE *pipe = popen(command.c_str(), "r");

    if (!pipe)
    {
        throw std::runtime_error("Failed to open pipe to convert command");
    }

    int32_t start = buffer.GetWriteHead();

    while (!feof(pipe))
    {
        uint8_t buff[4096];
        size_t bytesRead = fread(buff, 1, sizeof(buff), pipe);

        if (bytesRead > 0)
        {
            for (size_t i = 0; i < bytesRead; i++)
            {
                buffer.Write<uint8_t>(buff[i]);
            }
        }
    }

    pclose(pipe);

    AlignBuffer(buffer);

    int32_t end = buffer.GetWriteHead();

    return {start, end};
}

void nejlika::geometry::Converter::AlignBuffer(nejlika::Writer &buffer)
{
    while (buffer.GetWriteHead() % 4 != 0)
    {
        buffer.Write(static_cast<uint8_t>(0));
    }
}

NiNode *nejlika::geometry::Converter::FindClosestCommonParent(NiNode *root, std::vector<NiNode *> nodes)
{
    // Base case: if the root is null or if the root itself is one of the nodes
    if (!root || std::find(nodes.begin(), nodes.end(), root) != nodes.end())
        return root;

    // Check children for potential common parent
    const auto &children = root->GetChildren();
    NiNode *commonParent = nullptr;

    int count = 0;
    for (auto child : children)
    {
        NiAVObject *childNode = child.Query(m_Blocks);

        if (!childNode)
        {
            continue;
        }

        if (NiNode *childNiNode = dynamic_cast<NiNode *>(childNode))
        {
            NiNode *childResult = FindClosestCommonParent(childNiNode, nodes);
            if (childResult)
            {
                commonParent = childResult; // Update common parent if one was found
                ++count;
            }
        }
    }

    // If more than one child contains part of the nodes, this root is the common parent
    if (count > 1)
        return root;

    // If exactly one child contains all the nodes, return that child as the common parent
    return commonParent;
}

std::string nejlika::geometry::Converter::GetNifString(uint32_t index) const
{
    if (index >= m_Header.GetStrings().size())
    {
        return "";
    }

    const auto &strings = m_Header.GetStrings();

    const auto &string = strings[index].GetValue();

    return std::string(string.begin(), string.end());
}

std::string nejlika::geometry::Converter::GetNifString(const nejlika::geometry::Header &header, uint32_t index) const
{
    if (index >= header.GetStrings().size())
    {
        return "";
    }

    const auto &strings = header.GetStrings();

    const auto &string = strings[index].GetValue();

    return std::string(string.begin(), string.end());
}

glm::mat4 nejlika::geometry::Converter::ComputeGlobalTransform(NiAVObject *node)
{
    glm::mat4 transform = glm::mat4(1.0f);

    while (node)
    {
        const auto &translation = node->GetTranslation();
        const auto &rotation = node->GetRotation();
        const auto &scale = node->GetScale();

        glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(translation.Getx(), translation.Gety(), translation.Getz()));

        // Convert rotation matrix to quaternion
        /*std::array<std::array<float, 3>, 3> rotationMatrix = {
            { { rotation.Getm11(), rotation.Getm12(), rotation.Getm13() },
              { rotation.Getm21(), rotation.Getm22(), rotation.Getm23() },
              { rotation.Getm31(), rotation.Getm32(), rotation.Getm33() } }
        };

        std::vector<double> quaternion = RotationMatrixToQuaternion(rotationMatrix);

        glm::mat4 R = glm::mat4_cast(glm::quat(quaternion[3], quaternion[0], quaternion[1], quaternion[2]));*/

        glm::mat3 rotationMatrix = glm::mat3(
            rotation.Getm11(), rotation.Getm12(), rotation.Getm13(),
            rotation.Getm21(), rotation.Getm22(), rotation.Getm23(),
            rotation.Getm31(), rotation.Getm32(), rotation.Getm33());

        glm::quat q = glm::quat_cast(rotationMatrix);
        glm::mat4 R = glm::mat4_cast(q);

        glm::mat4 S = glm::scale(glm::mat4(1.0f), glm::vec3(scale, scale, scale));

        transform = T * R * S * transform;

        const auto &parentIt = m_ParentMap.find(node);

        if (parentIt == m_ParentMap.end())
        {
            break;
        }

        node = parentIt->second;
    }

    return transform;
}
