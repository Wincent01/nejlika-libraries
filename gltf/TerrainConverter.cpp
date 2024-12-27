#include "TerrainConverter.hpp"

#include "ConverterHelper.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/constants.hpp>

using namespace nejlika::geometry;

void TerrainConverter::LoadRaw(nejlika::Reader &reader, const std::string &path)
{
    m_Terrain = nejlika::world::Terrain(reader);
}

void nejlika::geometry::TerrainConverter::ExportGLTF(std::stringstream& writer)
{
    tinygltf::Model model;

    // Create a root node
    tinygltf::Node root;
    root.name = "Root";

    constexpr float centerX = 204.8f / 2.0f;
    constexpr float centerY = 204.8f / 2.0f;
    
    root.translation = { centerX, 0.0f, centerY };
    
    float angle = glm::radians(90.0f);
    glm::vec3 axis(0.0f, 1.0f, 0.0f);
    glm::quat rotation = glm::angleAxis(angle, axis);

    root.rotation = { rotation.x, rotation.y, rotation.z, rotation.w };

    // Scale x scale by -1 to flip the terrain
    root.scale = { -1.0f, 1.0f, 1.0f };

    // Add a scene
    tinygltf::Scene scene;

    // Create a buffer
    nejlika::Writer buffer;

    for (const auto& chunk : m_Terrain.GetChunks())
    {
        int32_t index = ExportChunk(chunk, model, buffer);

        root.children.push_back(index);
    }
    
    tinygltf::Buffer gltfBuffer;
    gltfBuffer.data.assign(buffer.GetBuffer().begin(), buffer.GetBuffer().begin() + buffer.GetWriteHead());
    model.buffers.push_back(gltfBuffer);

    int32_t rootNodeIndex = model.nodes.size();

    model.nodes.push_back(root);

    scene.nodes.push_back(rootNodeIndex);
    model.scenes.push_back(scene);

    // Export the model to the writer
    // Fist, create a byte stream
    tinygltf::TinyGLTF gltf;
    
    bool result = gltf.WriteGltfSceneToStream(&model, writer, true, false);

    if (!result)
    {
        throw std::runtime_error("Failed to write GLTF to stream");
    }
}

void nejlika::geometry::TerrainConverter::ExportChunkGLTF(std::stringstream &writer, const nejlika::world::TerrainChunk &chunk)
{
    tinygltf::Model model;

    // Create a root node
    tinygltf::Node root;
    root.name = "Root";

    constexpr float centerX = 204.8f / 2.0f;
    constexpr float centerY = 204.8f / 2.0f;

    root.translation = { centerX, 0.0f, centerY };

    float angle = glm::radians(90.0f);
    glm::vec3 axis(0.0f, 1.0f, 0.0f);
    glm::quat rotation = glm::angleAxis(angle, axis);

    root.rotation = { rotation.x, rotation.y, rotation.z, rotation.w };

    // Scale x scale by -1 to flip the terrain
    root.scale = { -1.0f, 1.0f, 1.0f };

    // Add a scene
    tinygltf::Scene scene;

    // Create a buffer
    nejlika::Writer buffer;

    int32_t index = ExportChunk(chunk, model, buffer);

    root.children.push_back(index);

    tinygltf::Buffer gltfBuffer;
    gltfBuffer.data.assign(buffer.GetBuffer().begin(), buffer.GetBuffer().begin() + buffer.GetWriteHead());
    model.buffers.push_back(gltfBuffer);

    int32_t rootNodeIndex = model.nodes.size();

    model.nodes.push_back(root);

    scene.nodes.push_back(rootNodeIndex);
    model.scenes.push_back(scene);

    // Export the model to the writer
    // Fist, create a byte stream
    tinygltf::TinyGLTF gltf;

    bool result = gltf.WriteGltfSceneToStream(&model, writer, true, false);

    if (!result)
    {
        throw std::runtime_error("Failed to write GLTF to stream");
    }
}

boost::json::object nejlika::geometry::TerrainConverter::ExportMaterialDetails(const std::filesystem::path& path, const std::filesystem::path& systemPath, const std::filesystem::path& uriPath)
{
    boost::json::object materialDetails;
    
    materialDetails["width"] = m_Terrain.GetWidth();
    materialDetails["height"] = m_Terrain.GetHeight();
    
    boost::json::array chunks;

    try {
        for (const auto& chunk : m_Terrain.GetChunks())
        {
            chunks.emplace_back(ExportChunkMaterialDetails(path, systemPath, uriPath, chunk));
        }
    }
    catch (const std::runtime_error& e)
    {
        throw std::runtime_error("Failed to export chunk material details: " + std::string(e.what()));
    }

    materialDetails["chunks"] = chunks;

    return materialDetails;
}

boost::json::object nejlika::geometry::TerrainConverter::ExportChunkMaterialDetails(const std::filesystem::path& path, const std::filesystem::path& systemPath, const std::filesystem::path& uriPath, const nejlika::world::TerrainChunk &chunk)
{
    boost::json::object chunkDetails;

    const auto& heightmap = chunk.GetHeightMap();
    const auto width = heightmap.GetWidth();
    const auto height = heightmap.GetHeight();

    float minVal = std::numeric_limits<float>::max();
    float maxVal = std::numeric_limits<float>::min();

    for (const auto& height : heightmap.GetHeightMap())
    {
        minVal = std::min(minVal, height);
        maxVal = std::max(maxVal, height);
    }

    const auto heightMapPath = ConverterHelper::GenerateRandomPath(path, ".png");

    ConverterHelper::MapToPNG(heightmap.GetHeightMap(), width, height, minVal, maxVal, systemPath / heightMapPath);

    boost::json::object heightMap;
    heightMap["path"] = (uriPath / heightMapPath).string();
    heightMap["min"] = minVal;
    heightMap["max"] = maxVal;
    heightMap["width"] = width;
    heightMap["height"] = height;
    heightMap["scale"] = heightmap.GetScaleFactor();
    
    boost::json::array translation;
    translation.push_back(heightmap.GetPositionX());
    translation.push_back(heightmap.GetPositionY());

    heightMap["translation"] = translation;

    chunkDetails["heightmap"] = heightMap;

    boost::json::object texturing;

    const auto textureMapPath = ConverterHelper::GenerateRandomPath(path, ".png");

    const auto textureMap = chunk.GetTextureMap();

    ConverterHelper::ColorMapToPNG(textureMap.GetColorMap(), textureMap.GetColorMapResolution(), textureMap.GetColorMapResolution(), systemPath / textureMapPath);

    texturing["path"] = (uriPath / textureMapPath).string();

    texturing["setting"] = chunk.GetTextureSetting();

    boost::json::array texturePallet;

    for (const auto& palletIndex : heightmap.GetTexturePallet())
    {
        texturePallet.push_back(palletIndex);
    }

    texturing["pallet"] = texturePallet;

    chunkDetails["texturing"] = texturing;

    boost::json::object colorTints;

    const auto colorMapPath = ConverterHelper::GenerateRandomPath(path, ".png");

    const auto colorMap = chunk.GetColorMap();

    ConverterHelper::ColorMapToPNG(colorMap.GetColorMap(), colorMap.GetColorMapResolution(), colorMap.GetColorMapResolution(), systemPath / colorMapPath);

    colorTints["path"] = (uriPath / colorMapPath).string();

    chunkDetails["colors"] = colorTints;

    boost::json::object blendMap;

    const auto blendMapPath = ConverterHelper::GenerateRandomPath(path, ".png");

    const auto blendMapData = chunk.GetBlendMap();

    ConverterHelper::ConvertDDSToPNG(blendMapData.GetData(), systemPath / blendMapPath);

    blendMap["path"] = (uriPath / blendMapPath).string();

    chunkDetails["blendmap"] = blendMap;

    boost::json::object lightMap;

    const auto lightMapPath = ConverterHelper::GenerateRandomPath(path, ".png");

    const auto lightMapData = chunk.GetLightMap();

    ConverterHelper::ConvertDDSToPNG(lightMapData.GetData(), systemPath / lightMapPath);

    lightMap["path"] = (uriPath / lightMapPath).string();

    chunkDetails["lightmap"] = lightMap;

    return chunkDetails;
}

void nejlika::geometry::TerrainConverter::Cleanup()
{
}

nejlika::geometry::TerrainConverter::~TerrainConverter()
{
}

int32_t nejlika::geometry::TerrainConverter::ExportChunk(const nejlika::world::TerrainChunk& chunk, tinygltf::Model& model, nejlika::Writer& buffer)
{
    int32_t nodeIndex = model.nodes.size();

    tinygltf::Node gltfNode;
    gltfNode.name = "Chunk";

    tinygltf::Mesh mesh;
    mesh.name = "Mesh";

    tinygltf::Primitive primitive;

    constexpr float scale = 3.2f;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<uint16_t> indices;

    const auto& heightmap = chunk.GetHeightMap();
    const auto width = heightmap.GetWidth();
    const auto height = heightmap.GetHeight();

    const float centerX = (width - 1) / 2.0f;
    const float centerY = (height - 1) / 2.0f;

    // Reserve space for better performance
    vertices.reserve(width * height);
    normals.resize(width * height, glm::vec3(0.0f));
    uvs.reserve(width * height);
    indices.reserve((width - 1) * (height - 1) * 6);

    // Generate vertices and UVs
    for (int32_t y = 0; y < height; y++) {
        for (int32_t x = 0; x < width; x++) {
            float vertexHeight = heightmap.GetHeightMap()[x + y * width];
            glm::vec3 position((x - centerX) * scale, vertexHeight, (y - centerY) * scale);

            vertices.push_back(position);
            uvs.emplace_back(x / static_cast<float>(width - 1), y / static_cast<float>(height - 1));
        }
    }

    // Generate indices and normals
    for (uint16_t y = 0; y < height - 1; y++) {
        for (uint16_t x = 0; x < width - 1; x++) {
            uint16_t topLeft = x + y * width;
            uint16_t topRight = topLeft + 1;
            uint16_t bottomLeft = x + (y + 1) * width;
            uint16_t bottomRight = bottomLeft + 1;

            // Add indices for two triangles
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);

            // Calculate normals for the two triangles
            glm::vec3 normal1 = glm::normalize(glm::cross(vertices[bottomLeft] - vertices[topLeft], vertices[topRight] - vertices[topLeft]));
            glm::vec3 normal2 = glm::normalize(glm::cross(vertices[bottomRight] - vertices[bottomLeft], vertices[topRight] - vertices[bottomLeft]));

            // Accumulate normals for each vertex
            for (auto idx : {topLeft, bottomLeft, topRight}) {
                normals[idx] += normal1;
            }
            for (auto idx : {topRight, bottomLeft, bottomRight}) {
                normals[idx] += normal2;
            }
        }
    }

    // Normalize accumulated normals
    for (auto& normal : normals) {
        normal = glm::normalize(normal);
    }

    // Export vertices
    int32_t vertexAccessorIndex = ConverterHelper::ExportGLTFVertices(vertices, model, buffer);
    int32_t normalAccessorIndex = ConverterHelper::ExportGLTFNormals(normals, model, buffer);
    int32_t uvAccessorIndex = ConverterHelper::ExportGLTFUVs(uvs, model, buffer);
    int32_t indexAccessorIndex = ConverterHelper::ExportGLTFIndices(indices, model, buffer);

    primitive.attributes["POSITION"] = vertexAccessorIndex;
    primitive.attributes["NORMAL"] = normalAccessorIndex;
    primitive.attributes["TEXCOORD_0"] = uvAccessorIndex;
    primitive.indices = indexAccessorIndex;
    primitive.mode = TINYGLTF_MODE_TRIANGLES;

    mesh.primitives.push_back(primitive);

    int32_t meshIndex = model.meshes.size();

    model.meshes.push_back(mesh);
    
    gltfNode.mesh = meshIndex;
    gltfNode.translation = { heightmap.GetPositionY(), 0.0f, heightmap.GetPositionX() };

    model.nodes.push_back(gltfNode);

    return nodeIndex;
}
