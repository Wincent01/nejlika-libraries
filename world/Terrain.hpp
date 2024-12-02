#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"
#include "TerrainChunk.hpp"

namespace nejlika::world {

class Terrain
{
public:
    Terrain() = default;

    Terrain(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const std::vector<TerrainChunk>& GetChunks() const;

    int32_t GetVersion() const;

    int32_t GetWidth() const;

    int32_t GetHeight() const;

    void SetChunks(const std::vector<TerrainChunk>& chunks);

    void SetVersion(int32_t version);

    void SetWidth(int32_t width);

    void SetHeight(int32_t height);

    ~Terrain();

private:
    std::vector<TerrainChunk> m_Chunks;

    int32_t m_Version = 0x20;

    int32_t m_Width = 0;

    int32_t m_Height = 0;
};


}
