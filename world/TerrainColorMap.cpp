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

TerrainColorMap::~TerrainColorMap()
{
    m_ColorMap.clear();
}