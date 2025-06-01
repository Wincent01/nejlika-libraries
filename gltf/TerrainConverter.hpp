#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <filesystem>
#include <optional>

#include <glm/glm.hpp>
#include <boost/json.hpp>

#include "Terrain.hpp"

#include "gltf.h"

namespace nejlika::geometry {

class TerrainConverter
{
public:
    void LoadRaw(nejlika::Reader& reader, const std::string& path);

    void ExportGLTF(std::stringstream& writer);

    void ExportChunkGLTF(std::stringstream& writer, const nejlika::world::TerrainChunk& chunk);

    /**
     * @brief Export the material details of the terrain
     * 
     * This includes heightmap, color and texture maps.
     */
    boost::json::object ExportMaterialDetails(const std::filesystem::path& path, const std::filesystem::path& systemPath, const std::filesystem::path& uriPath);

    boost::json::object ExportChunkMaterialDetails(const std::filesystem::path& path, const std::filesystem::path& systemPath, const std::filesystem::path& uriPath, const nejlika::world::TerrainChunk& chunk);

    const nejlika::world::Terrain& GetTerrain() const { return m_Terrain; }

    void Cleanup();

    ~TerrainConverter();

private:
    int32_t ExportChunk(const nejlika::world::TerrainChunk& chunk, tinygltf::Model& model, nejlika::Writer& buffer);

    nejlika::world::Terrain m_Terrain;

    std::unordered_map<size_t, std::string> m_MapFilesCache;

    template <typename T>
    size_t ComputeMapHash(const std::vector<T>& map, size_t width, size_t height)
    {
        // Include the width and height in the hash
        size_t hash = std::hash<size_t>{}(width) ^ std::hash<size_t>{}(height);

        for (const auto& value : map)
        {
            hash ^= std::hash<T>{}(value) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }

        return hash;
    }
};

}