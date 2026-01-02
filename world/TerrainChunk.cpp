#include "TerrainChunk.hpp"

using namespace nejlika::world;

TerrainChunk::TerrainChunk(nejlika::Reader& io, int32_t version)
{
    m_Index = io.Read<int32_t>();

    m_HeightMap = TerrainHeightMap(io, version);

    if (version >= 0x20)
    {
        m_ColorMap = TerrainColorMap(io, io.Read<uint32_t>());
    }
    else
    {
        m_ColorMap = TerrainColorMap(io, m_HeightMap.GetWidth());
    }

    m_LightMap = TerrainDirectDrawSurface(io);

    if (version >= 0x20)
    {
        m_TextureMap = TerrainColorMap(io, io.Read<uint32_t>());
    }
    else
    {
        m_TextureMap = TerrainColorMap(io, m_HeightMap.GetWidth());
    }

    m_TextureSetting = io.Read<uint8_t>();

    m_BlendMap = TerrainDirectDrawSurface(io);

    m_Foliage.resize(io.Read<uint32_t>());

    for (auto& foliage : m_Foliage)
    {
        foliage = TerrainFoliage(io);
    }

    m_SceneData.resize(m_ColorMap.GetColorMap().size());

    for (auto& sceneData : m_SceneData)
    {
        sceneData = io.Read<uint8_t>();
    }

    m_MeshVertexUsage.resize(io.Read<uint32_t>());

    for (auto& vertexUsage : m_MeshVertexUsage)
    {
        vertexUsage = io.Read<uint16_t>();
    }

    if (m_MeshVertexUsage.empty())
    {
        return;
    }

    m_MeshVertexSize.resize(16);

    for (auto& vertexSize : m_MeshVertexSize)
    {
        vertexSize = io.Read<uint16_t>();
    }

    m_MeshTriangles.resize(16);

    for (auto& meshTriangle : m_MeshTriangles)
    {
        meshTriangle.resize(io.Read<uint16_t>());

        for (auto& triangle : meshTriangle)
        {
            triangle = io.Read<uint16_t>();
        }
    }
}

void TerrainChunk::Save(nejlika::Writer& io, int32_t version) const
{
    io.Write(m_Index);

    m_HeightMap.Save(io, version);

    if (version >= 0x20)
    {
        io.Write(static_cast<uint32_t>(m_ColorMap.GetColorMapResolution()));
    }
    else if (m_ColorMap.GetColorMapResolution() != m_HeightMap.GetWidth())
    {
        throw std::runtime_error("TerrainChunk::Save: m_ColorMap.GetColorMapResolution() != m_HeightMap.GetWidth()");
    }

    m_ColorMap.Save(io);

    m_LightMap.Save(io);

    if (version >= 0x20)
    {
        io.Write(static_cast<uint32_t>(m_TextureMap.GetColorMapResolution()));
    }
    else if (m_TextureMap.GetColorMapResolution() != m_HeightMap.GetWidth())
    {
        throw std::runtime_error("TerrainChunk::Save: m_TextureMap.GetColorMapResolution() != m_HeightMap.GetWidth()");
    }

    m_TextureMap.Save(io);

    io.Write(m_TextureSetting);

    m_BlendMap.Save(io);

    io.Write(static_cast<uint32_t>(m_Foliage.size()));

    for (const auto& foliage : m_Foliage)
    {
        foliage.Save(io);
    }

    if (m_SceneData.size() != m_ColorMap.GetColorMap().size())
    {
        throw std::runtime_error("TerrainChunk::Save: m_SceneData.size() != m_ColorMap.GetColorMap().size()");
    }

    for (const auto& sceneData : m_SceneData)
    {
        io.Write(sceneData);
    }

    io.Write(static_cast<uint32_t>(m_MeshVertexUsage.size()));

    for (const auto& vertexUsage : m_MeshVertexUsage)
    {
        io.Write(vertexUsage);
    }

    if (m_MeshVertexUsage.empty())
    {
        return;
    }

    if (m_MeshVertexSize.size() != 16)
    {
        throw std::runtime_error("TerrainChunk::Save: m_MeshVertexSize.size() != 16");
    }

    for (const auto& vertexSize : m_MeshVertexSize)
    {
        io.Write(vertexSize);
    }

    if (m_MeshTriangles.size() != 16)
    {
        throw std::runtime_error("TerrainChunk::Save: m_MeshTriangles.size() != 16");
    }

    for (const auto& meshTriangle : m_MeshTriangles)
    {
        io.Write(static_cast<uint16_t>(meshTriangle.size()));

        for (const auto& triangle : meshTriangle)
        {
            io.Write(triangle);
        }
    }
}

int32_t TerrainChunk::GetIndex() const
{
    return m_Index;
}

const TerrainHeightMap& TerrainChunk::GetHeightMap() const
{
    return m_HeightMap;
}

const TerrainColorMap& TerrainChunk::GetColorMap() const
{
    return m_ColorMap;
}

const TerrainDirectDrawSurface& TerrainChunk::GetLightMap() const
{
    return m_LightMap;
}

const TerrainColorMap& TerrainChunk::GetTextureMap() const
{
    return m_TextureMap;
}

uint8_t TerrainChunk::GetTextureSetting() const
{
    return m_TextureSetting;
}

const TerrainDirectDrawSurface& TerrainChunk::GetBlendMap() const
{
    return m_BlendMap;
}

const std::vector<TerrainFoliage>& TerrainChunk::GetFoliage() const
{
    return m_Foliage;
}

const std::vector<uint8_t>& TerrainChunk::GetSceneData() const
{
    return m_SceneData;
}

const std::vector<uint16_t>& TerrainChunk::GetMeshVertexUsage() const
{
    return m_MeshVertexUsage;
}

const std::vector<uint16_t>& TerrainChunk::GetMeshVertexSize() const
{
    return m_MeshVertexSize;
}

const std::vector<std::vector<uint16_t>>& TerrainChunk::GetMeshTriangles() const
{
    return m_MeshTriangles;
}

TerrainHeightMap& nejlika::world::TerrainChunk::GetHeightMap()
{
    return m_HeightMap;
}

TerrainColorMap& TerrainChunk::GetColorMap()
{
    return m_ColorMap;
}

TerrainDirectDrawSurface& TerrainChunk::GetLightMap()
{
    return m_LightMap;
}

TerrainColorMap& TerrainChunk::GetTextureMap()
{
    return m_TextureMap;
}

TerrainDirectDrawSurface& TerrainChunk::GetBlendMap()
{
    return m_BlendMap;
}

std::vector<TerrainFoliage>& TerrainChunk::GetFoliage()
{
    return m_Foliage;
}

std::vector<uint8_t>& TerrainChunk::GetSceneData()
{
    return m_SceneData;
}

std::vector<uint16_t>& TerrainChunk::GetMeshVertexUsage()
{
    return m_MeshVertexUsage;
}

std::vector<uint16_t>& TerrainChunk::GetMeshVertexSize()
{
    return m_MeshVertexSize;
}

std::vector<std::vector<uint16_t>>& TerrainChunk::GetMeshTriangles()
{
    return m_MeshTriangles;
}

void TerrainChunk::SetIndex(int32_t index)
{
    m_Index = index;
}

void TerrainChunk::SetHeightMap(const TerrainHeightMap& heightMap)
{
    m_HeightMap = heightMap;
}

void TerrainChunk::SetColorMap(const TerrainColorMap& colorMap)
{
    m_ColorMap = colorMap;
}

void TerrainChunk::SetLightMap(const TerrainDirectDrawSurface& lightMap)
{
    m_LightMap = lightMap;
}

void TerrainChunk::SetTextureMap(const TerrainColorMap& textureMap)
{
    m_TextureMap = textureMap;
}

void TerrainChunk::SetTextureSetting(uint8_t textureSetting)
{
    m_TextureSetting = textureSetting;
}

void TerrainChunk::SetBlendMap(const TerrainDirectDrawSurface& blendMap)
{
    m_BlendMap = blendMap;
}

void TerrainChunk::SetFoliage(const std::vector<TerrainFoliage>& foliage)
{
    m_Foliage = foliage;
}

void TerrainChunk::SetSceneData(const std::vector<uint8_t>& sceneData)
{
    m_SceneData = sceneData;
}

void TerrainChunk::SetMeshVertexUsage(const std::vector<uint16_t>& meshVertexUsage)
{
    m_MeshVertexUsage = meshVertexUsage;
}

void TerrainChunk::SetMeshVertexSize(const std::vector<uint16_t>& meshVertexSize)
{
    m_MeshVertexSize = meshVertexSize;
}

void TerrainChunk::SetMeshTriangles(const std::vector<std::vector<uint16_t>>& meshTriangles)
{
    m_MeshTriangles = meshTriangles;
}

TerrainChunk::~TerrainChunk()
{
    m_Foliage.clear();
    m_MeshVertexUsage.clear();
    m_MeshVertexSize.clear();
    m_MeshTriangles.clear();
}
