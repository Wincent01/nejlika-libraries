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

class TerrainHeightMap
{
public:
    TerrainHeightMap() = default;

    TerrainHeightMap(nejlika::Reader& io, int32_t version);

    void Save(nejlika::Writer& io, int32_t version) const;

    uint32_t GetWidth() const;

    uint32_t GetHeight() const;

    float GetPositionX() const;

    float GetPositionY() const;

    /**
     * @brief Get the shader id
     *
     * @return The shader id
     *
     * @note Only for older versions
     */
    uint32_t GetShaderId() const;

    float GetScaleFactor() const;

    const std::vector<int32_t>& GetTexturePallet() const;

    const std::vector<float>& GetHeightMap() const;

    void SetWidth(uint32_t width);

    void SetHeight(uint32_t height);

    void SetPositionX(float positionX);

    void SetPositionY(float positionY);

    void SetShaderId(uint32_t shaderId);

    void SetScaleFactor(float scaleFactor);

    void SetTexturePallet(const std::vector<int32_t>& texturePallet);

    void SetHeightMap(const std::vector<float>& heightMap);

    void AllocateHeightMap(uint32_t width, uint32_t height);

    void SetHeightMapValue(uint32_t x, uint32_t y, float height);

    float GetHeightMapValue(uint32_t x, uint32_t y) const;

    ~TerrainHeightMap();

private:
    uint32_t m_Width = 0;

    uint32_t m_Height = 0;

    float m_PositionX = 0.0f;

    float m_PositionY = 0.0f;

    uint32_t m_ShaderId = 0;

    float m_ScaleFactor = 3.2f;

    std::vector<int32_t> m_TexturePallet;

    std::vector<float> m_HeightMap;
};

} // namespace nejlika::world
