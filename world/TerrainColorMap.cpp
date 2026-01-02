#include "TerrainColorMap.hpp"

using namespace nejlika::world;

TerrainColorMap::TerrainColorMap(nejlika::Reader& io, int32_t size)
{
    m_ColorMap.resize(size * size);

    for (auto& color : m_ColorMap)
    {
        color = io.Read<color4>();
    }
}

void TerrainColorMap::Save(nejlika::Writer& io) const
{
    for (const auto& color : m_ColorMap)
    {
        io.Write(color);
    }
}

const std::vector<color4>& TerrainColorMap::GetColorMap() const
{
    return m_ColorMap;
}

uint32_t TerrainColorMap::GetColorMapResolution() const
{
    return static_cast<uint32_t>(std::sqrt(m_ColorMap.size()));
}

void TerrainColorMap::SetColorMap(const std::vector<color4>& colorMap)
{
    m_ColorMap = colorMap;
}

void nejlika::world::TerrainColorMap::AllocateColorMap(uint32_t size)
{
    m_ColorMap.resize(size * size);
}

void TerrainColorMap::SetColorMapValue(uint32_t x, uint32_t y, const color4& color)
{
    uint32_t resolution = GetColorMapResolution();

    if (x >= resolution || y >= resolution)
    {
        throw std::out_of_range("TerrainColorMap::SetColorMapValue: x or y out of range");
    }

    m_ColorMap[y * resolution + x] = color;
}

const color4& TerrainColorMap::GetColorMapValue(uint32_t x, uint32_t y) const
{
    uint32_t resolution = GetColorMapResolution();

    if (x >= resolution || y >= resolution)
    {
        throw std::out_of_range("TerrainColorMap::GetColorMapValue: x or y out of range");
    }

    return m_ColorMap[y * resolution + x];
}

TerrainColorMap::~TerrainColorMap()
{
    m_ColorMap.clear();
}