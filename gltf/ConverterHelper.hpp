#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <filesystem>

#include <Writer.hpp>
#include <Reader.hpp>

#include <glm/glm.hpp>

#include <numerics.hpp>

#include "gltf.h"

namespace nejlika::geometry {

class ConverterHelper
{
public:
    typedef enum {
        PIXELFORMAT_UNCOMPRESSED_GRAYSCALE = 1, // 8 bit per pixel (no alpha)
        PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA,    // 8*2 bpp (2 channels)
        PIXELFORMAT_UNCOMPRESSED_R5G6B5,        // 16 bpp
        PIXELFORMAT_UNCOMPRESSED_R8G8B8,        // 24 bpp
        PIXELFORMAT_UNCOMPRESSED_R5G5B5A1,      // 16 bpp (1 bit alpha)
        PIXELFORMAT_UNCOMPRESSED_R4G4B4A4,      // 16 bpp (4 bit alpha)
        PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,      // 32 bpp
        PIXELFORMAT_UNCOMPRESSED_R32,           // 32 bpp (1 channel - float)
        PIXELFORMAT_UNCOMPRESSED_R32G32B32,     // 32*3 bpp (3 channels - float)
        PIXELFORMAT_UNCOMPRESSED_R32G32B32A32,  // 32*4 bpp (4 channels - float)
        PIXELFORMAT_UNCOMPRESSED_R16,           // 16 bpp (1 channel - half float)
        PIXELFORMAT_UNCOMPRESSED_R16G16B16,     // 16*3 bpp (3 channels - half float)
        PIXELFORMAT_UNCOMPRESSED_R16G16B16A16,  // 16*4 bpp (4 channels - half float)
        PIXELFORMAT_COMPRESSED_DXT1_RGB,        // 4 bpp (no alpha)
        PIXELFORMAT_COMPRESSED_DXT1_RGBA,       // 4 bpp (1 bit alpha)
        PIXELFORMAT_COMPRESSED_DXT3_RGBA,       // 8 bpp
        PIXELFORMAT_COMPRESSED_DXT5_RGBA,       // 8 bpp
        PIXELFORMAT_COMPRESSED_ETC1_RGB,        // 4 bpp
        PIXELFORMAT_COMPRESSED_ETC2_RGB,        // 4 bpp
        PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA,   // 8 bpp
        PIXELFORMAT_COMPRESSED_PVRT_RGB,        // 4 bpp
        PIXELFORMAT_COMPRESSED_PVRT_RGBA,       // 4 bpp
        PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA,   // 8 bpp
        PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA    // 2 bpp
    } PixelFormat;

    static int32_t ExportGLTFVertices(const std::vector<glm::vec3>& vertices, tinygltf::Model& model, nejlika::Writer& buffer);

    static int32_t ExportGLTFIndices(const std::vector<uint16_t>& indices, tinygltf::Model& model, nejlika::Writer& buffer);

    static int32_t ExportGLTFNormals(const std::vector<glm::vec3>& normals, tinygltf::Model& model, nejlika::Writer& buffer);

    static int32_t ExportGLTFUVs(const std::vector<glm::vec2>& uvs, tinygltf::Model& model, nejlika::Writer& buffer);

    static int32_t ExportGLTFColors(const std::vector<glm::vec4>& colors, tinygltf::Model& model, nejlika::Writer& buffer);

    static void AlignBuffer(nejlika::Writer& buffer);

    static void* LoadDDSFromMsemory(const unsigned char *file_data, unsigned int file_size, int *width, int *height, int *format, int *mips);

    static bool ConvertDDSToPNG(
        const std::vector<uint8_t>& ddsData,
        std::vector<uint8_t>& pngData
    );

    static bool ConvertDDSToPNG(
        const std::vector<uint8_t>& ddsData,
        const std::filesystem::path& path
    );

    static bool MapToPNG(
        const std::vector<float>& heightMap,
        int width, int height, 
        float minVal, float maxVal,
        std::vector<uint8_t>& pngData
    );

    static bool MapToPNG(
        const std::vector<float>& heightMap,
        int width, int height, 
        float minVal, float maxVal,
        const std::filesystem::path& path
    );

    static bool MapToPNG(
        const std::vector<uint8_t>& data,
        int width, int height,
        const std::filesystem::path& path
    );

    static bool ColorMapToPNG(
        const std::vector<color4>& colorMap,
        int width, int height,
        const std::filesystem::path& path
    );

    static std::filesystem::path GenerateRandomPath(
        const std::filesystem::path& directory,
        const std::string& extension
    );
};

}