#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"

namespace nejlika::world
{

class TerrainColorMap
{
public:
    TerrainColorMap() = default;

    TerrainColorMap(nejlika::Reader& io, int32_t size);

    void Save(nejlika::Writer& io) const;

    const std::vector<color4>& GetColorMap() const;

    uint32_t GetColorMapResolution() const;

    void SetColorMap(const std::vector<color4>& colorMap);

    void AllocateColorMap(uint32_t size);

    void SetColorMapValue(uint32_t x, uint32_t y, const color4& color);

    const color4& GetColorMapValue(uint32_t x, uint32_t y) const;

    ~TerrainColorMap();

private:
    std::vector<color4> m_ColorMap;
};

} // namespace nejlika::world
