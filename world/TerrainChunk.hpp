#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"
#include "TerrainHeightMap.hpp"
#include "TerrainColorMap.hpp"
#include "TerrainDirectDrawSurface.hpp"
#include "TerrainFoliage.hpp"

namespace nejlika::world
{

class TerrainChunk
{
public:
    TerrainChunk() = default;

    TerrainChunk(nejlika::Reader& io, int32_t version);

    void Save(nejlika::Writer& io, int32_t version) const;

    // Getters and setters
    int32_t GetIndex() const;
    const TerrainHeightMap& GetHeightMap() const;
    const TerrainColorMap& GetColorMap() const;
    const TerrainDirectDrawSurface& GetLightMap() const;
    const TerrainColorMap& GetTextureMap() const;
    uint8_t GetTextureSetting() const;
    const TerrainDirectDrawSurface& GetBlendMap() const;
    const std::vector<TerrainFoliage>& GetFoliage() const;
    const std::vector<uint8_t>& GetSceneData() const;
    const std::vector<uint16_t>& GetMeshVertexUsage() const;
    const std::vector<uint16_t>& GetMeshVertexSize() const;
    const std::vector<std::vector<uint16_t>>& GetMeshTriangles() const;

    TerrainHeightMap& GetHeightMap();
    TerrainColorMap& GetColorMap();
    TerrainDirectDrawSurface& GetLightMap();
    TerrainColorMap& GetTextureMap();
    TerrainDirectDrawSurface& GetBlendMap();
    std::vector<TerrainFoliage>& GetFoliage();
    std::vector<uint8_t>& GetSceneData();
    std::vector<uint16_t>& GetMeshVertexUsage();
    std::vector<uint16_t>& GetMeshVertexSize();
    std::vector<std::vector<uint16_t>>& GetMeshTriangles();

    void SetIndex(int32_t index);
    void SetHeightMap(const TerrainHeightMap& heightMap);
    void SetColorMap(const TerrainColorMap& colorMap);
    void SetLightMap(const TerrainDirectDrawSurface& lightMap);
    void SetTextureMap(const TerrainColorMap& textureMap);
    void SetTextureSetting(uint8_t textureSetting);
    void SetBlendMap(const TerrainDirectDrawSurface& blendMap);
    void SetFoliage(const std::vector<TerrainFoliage>& foliage);
    void SetSceneData(const std::vector<uint8_t>& sceneData);
    void SetMeshVertexUsage(const std::vector<uint16_t>& meshVertexUsage);
    void SetMeshVertexSize(const std::vector<uint16_t>& meshVertexSize);
    void SetMeshTriangles(const std::vector<std::vector<uint16_t>>& meshTriangles);

    ~TerrainChunk();

private:
    int32_t m_Index = 0;

    TerrainHeightMap m_HeightMap;

    TerrainColorMap m_ColorMap;

    TerrainDirectDrawSurface m_LightMap;

    TerrainColorMap m_TextureMap;

    uint8_t m_TextureSetting = 0;

    TerrainDirectDrawSurface m_BlendMap;

    std::vector<TerrainFoliage> m_Foliage;

    std::vector<uint8_t> m_SceneData;

    std::vector<uint16_t> m_MeshVertexUsage;

    std::vector<uint16_t> m_MeshVertexSize;

    std::vector<std::vector<uint16_t>> m_MeshTriangles;
};

} // namespace nejlika::world
