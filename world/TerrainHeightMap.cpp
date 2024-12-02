#include "TerrainHeightMap.hpp"

using namespace nejlika::world;

TerrainHeightMap::TerrainHeightMap(nejlika::Reader& io, int32_t version)
{
    m_Width = io.Read<uint32_t>();

    m_Height = io.Read<uint32_t>();

    m_PositionX = io.Read<float>();

    m_PositionY = io.Read<float>();

    if (version < 0x20)
    {
        m_ShaderId = io.Read<uint32_t>();
    }

    m_TexturePallet.resize(4);

    for (auto& texturePallet : m_TexturePallet)
    {
        texturePallet = io.Read<int32_t>();
    }

    m_ScaleFactor = io.Read<float>();

    m_HeightMap.resize(m_Width * m_Height);

    for (auto& heightMap : m_HeightMap)
    {
        heightMap = io.Read<float>();
    }
}

void TerrainHeightMap::Save(nejlika::Writer& io, int32_t version) const
{
    io.Write(m_Width);

    io.Write(m_Height);

    io.Write(m_PositionX);

    io.Write(m_PositionY);

    if (version < 0x20)
    {
        io.Write(m_ShaderId);
    }

    if (m_TexturePallet.size() != 4)
    {
        throw std::runtime_error("TerrainHeightMap::Save: m_TexturePallet.size() != 4");
    }

    for (const auto& texturePallet : m_TexturePallet)
    {
        io.Write(texturePallet);
    }

    io.Write(m_ScaleFactor);

    if (m_HeightMap.size() != m_Width * m_Height)
    {
        throw std::runtime_error("TerrainHeightMap::Save: m_HeightMap.size() != m_Width * m_Height");
    }

    for (const auto& heightMap : m_HeightMap)
    {
        io.Write(heightMap);
    }
}

// Getters
uint32_t TerrainHeightMap::GetWidth() const
{
    return m_Width;
}

uint32_t TerrainHeightMap::GetHeight() const
{
    return m_Height;
}

float TerrainHeightMap::GetPositionX() const
{
    return m_PositionX;
}

float TerrainHeightMap::GetPositionY() const
{
    return m_PositionY;
}

uint32_t TerrainHeightMap::GetShaderId() const
{
    return m_ShaderId;
}

const std::vector<int32_t>& TerrainHeightMap::GetTexturePallet() const
{
    return m_TexturePallet;
}

float TerrainHeightMap::GetScaleFactor() const
{
    return m_ScaleFactor;
}

const std::vector<float>& TerrainHeightMap::GetHeightMap() const
{
    return m_HeightMap;
}

// Setters
void TerrainHeightMap::SetWidth(uint32_t width)
{
    m_Width = width;
}

void TerrainHeightMap::SetHeight(uint32_t height)
{
    m_Height = height;
}

void TerrainHeightMap::SetPositionX(float positionX)
{
    m_PositionX = positionX;
}

void TerrainHeightMap::SetPositionY(float positionY)
{
    m_PositionY = positionY;
}

void TerrainHeightMap::SetShaderId(uint32_t shaderId)
{
    m_ShaderId = shaderId;
}

void TerrainHeightMap::SetTexturePallet(const std::vector<int32_t>& texturePallet)
{
    m_TexturePallet = texturePallet;
}

void TerrainHeightMap::SetScaleFactor(float scaleFactor)
{
    m_ScaleFactor = scaleFactor;
}

void TerrainHeightMap::SetHeightMap(const std::vector<float>& heightMap)
{
    m_HeightMap = heightMap;
}

TerrainHeightMap::~TerrainHeightMap()
{
    m_TexturePallet.clear();
    m_HeightMap.clear();
}
