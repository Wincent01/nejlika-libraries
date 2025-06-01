#include "ConverterHelper.hpp"

#include <limits>
#include "stb_image.h"
#include "stb_image_write.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <iostream>
#include <sstream>
#include <fstream>

using namespace nejlika::geometry;

int32_t ConverterHelper::ExportGLTFVertices(const std::vector<glm::vec3>& vertices, tinygltf::Model& model, nejlika::Writer& buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    std::vector<float> minValue = { std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max() };
    std::vector<float> maxValue = { std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min() };

    for (const auto& vertex : vertices)
    {
        buffer.Write<float>(vertex.x);
        buffer.Write<float>(vertex.y);
        buffer.Write<float>(vertex.z);

        minValue[0] = std::min(minValue[0], vertex.x);
        minValue[1] = std::min(minValue[1], vertex.y);
        minValue[2] = std::min(minValue[2], vertex.z);

        maxValue[0] = std::max(maxValue[0], vertex.x);
        maxValue[1] = std::max(maxValue[1], vertex.y);
        maxValue[2] = std::max(maxValue[2], vertex.z);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = vertices.size();
    accessor.type = TINYGLTF_TYPE_VEC3;
    accessor.minValues = { minValue[0], minValue[1], minValue[2] };
    accessor.maxValues = { maxValue[0], maxValue[1], maxValue[2] };
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t ConverterHelper::ExportGLTFIndices(const std::vector<uint16_t>& indices, tinygltf::Model& model, nejlika::Writer& buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto& index : indices)
    {
        buffer.Write<uint16_t>(index);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT;
    accessor.count = indices.size();
    accessor.type = TINYGLTF_TYPE_SCALAR;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t ConverterHelper::ExportGLTFNormals(const std::vector<glm::vec3>& normals, tinygltf::Model& model, nejlika::Writer& buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto& normal : normals)
    {
        buffer.Write<float>(normal.x);
        buffer.Write<float>(normal.y);
        buffer.Write<float>(normal.z);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = normals.size();
    accessor.type = TINYGLTF_TYPE_VEC3;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

int32_t ConverterHelper::ExportGLTFUVs(const std::vector<glm::vec2>& uvs, tinygltf::Model& model, nejlika::Writer& buffer)
{
    int32_t bufferViewStart = buffer.GetWriteHead();

    for (const auto& uv : uvs)
    {
        buffer.Write<float>(uv.x);
        buffer.Write<float>(uv.y);
    }

    // Make sure the buffer is aligned to 4 bytes
    AlignBuffer(buffer);

    int32_t bufferViewEnd = buffer.GetWriteHead();

    int32_t accessorIndex = model.accessors.size();

    tinygltf::Accessor accessor;
    accessor.bufferView = model.bufferViews.size();
    accessor.byteOffset = 0;
    accessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
    accessor.count = uvs.size();
    accessor.type = TINYGLTF_TYPE_VEC2;
    model.accessors.push_back(accessor);

    tinygltf::BufferView bufferView;
    bufferView.buffer = 0;
    bufferView.byteOffset = bufferViewStart;
    bufferView.byteLength = bufferViewEnd - bufferViewStart;
    bufferView.byteStride = 0;
    bufferView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    model.bufferViews.push_back(bufferView);

    return accessorIndex;
}

void ConverterHelper::AlignBuffer(nejlika::Writer& buffer)
{
    while (buffer.GetWriteHead() % 4 != 0)
    {
        buffer.Write<uint8_t>(0);
    }
}

void *nejlika::geometry::ConverterHelper::LoadDDSFromMsemory(const unsigned char *file_data, unsigned int file_size, int *width, int *height, int *format, int *mips)
{
    void *image_data = NULL;        // Image data pointer
    int image_pixel_size = 0;       // Image pixel size

    unsigned char *file_data_ptr = (unsigned char *)file_data;

    // Required extension:
    // GL_EXT_texture_compression_s3tc

    // Supported tokens (defined by extensions)
    // GL_COMPRESSED_RGB_S3TC_DXT1_EXT      0x83F0
    // GL_COMPRESSED_RGBA_S3TC_DXT1_EXT     0x83F1
    // GL_COMPRESSED_RGBA_S3TC_DXT3_EXT     0x83F2
    // GL_COMPRESSED_RGBA_S3TC_DXT5_EXT     0x83F3

    #define FOURCC_DXT1 0x31545844  // Equivalent to "DXT1" in ASCII
    #define FOURCC_DXT3 0x33545844  // Equivalent to "DXT3" in ASCII
    #define FOURCC_DXT5 0x35545844  // Equivalent to "DXT5" in ASCII
    #define LOG(...) printf(__VA_ARGS__)
    #define RL_MALLOC(sz) malloc(sz)

    // DDS Pixel Format
    typedef struct {
        unsigned int size;
        unsigned int flags;
        unsigned int fourcc;
        unsigned int rgb_bit_count;
        unsigned int r_bit_mask;
        unsigned int g_bit_mask;
        unsigned int b_bit_mask;
        unsigned int a_bit_mask;
    } dds_pixel_format;

    // DDS Header (124 bytes)
    typedef struct {
        unsigned int size;
        unsigned int flags;
        unsigned int height;
        unsigned int width;
        unsigned int pitch_or_linear_size;
        unsigned int depth;
        unsigned int mipmap_count;
        unsigned int reserved1[11];
        dds_pixel_format ddspf;
        unsigned int caps;
        unsigned int caps2;
        unsigned int caps3;
        unsigned int caps4;
        unsigned int reserved2;
    } dds_header;

    if (file_data_ptr != NULL)
    {
        // Verify the type of file
        unsigned char *dds_header_id = file_data_ptr;
        file_data_ptr += 4;

        if ((dds_header_id[0] != 'D') || (dds_header_id[1] != 'D') || (dds_header_id[2] != 'S') || (dds_header_id[3] != ' '))
        {
            LOG("WARNING: IMAGE: DDS file data not valid");
        }
        else
        {
            dds_header *header = (dds_header *)file_data_ptr;

            file_data_ptr += sizeof(dds_header);        // Skip header

            *width = header->width;
            *height = header->height;

            if (*width % 4 != 0) LOG("WARNING: IMAGE: DDS file width must be multiple of 4. Image will not display correctly");
            if (*height % 4 != 0) LOG("WARNING: IMAGE: DDS file height must be multiple of 4. Image will not display correctly");

            image_pixel_size = header->width*header->height;

            if (header->mipmap_count == 0) *mips = 1;   // Parameter not used
            else *mips = header->mipmap_count;

            if (header->ddspf.rgb_bit_count == 16)      // 16bit mode, no compressed
            {
                if (header->ddspf.flags == 0x40)        // No alpha channel
                {
                    int data_size = image_pixel_size*sizeof(unsigned short);
                    if (header->mipmap_count > 1) data_size = data_size + data_size / 3;
                    image_data = RL_MALLOC(data_size);

                    memcpy(image_data, file_data_ptr, data_size);

                    *format = PIXELFORMAT_UNCOMPRESSED_R5G6B5;
                }
                else if (header->ddspf.flags == 0x41)           // With alpha channel
                {
                    if (header->ddspf.a_bit_mask == 0x8000)     // 1bit alpha
                    {
                        int data_size = image_pixel_size*sizeof(unsigned short);
                        if (header->mipmap_count > 1) data_size = data_size + data_size / 3;
                        image_data = RL_MALLOC(data_size);

                        memcpy(image_data, file_data_ptr, data_size);

                        unsigned char alpha = 0;

                        // NOTE: Data comes as A1R5G5B5, it must be reordered to R5G5B5A1
                        for (int i = 0; i < image_pixel_size; i++)
                        {
                            alpha = ((unsigned short *)image_data)[i] >> 15;
                            ((unsigned short *)image_data)[i] = ((unsigned short *)image_data)[i] << 1;
                            ((unsigned short *)image_data)[i] += alpha;
                        }

                        *format = PIXELFORMAT_UNCOMPRESSED_R5G5B5A1;
                    }
                    else if (header->ddspf.a_bit_mask == 0xf000)   // 4bit alpha
                    {
                        int data_size = image_pixel_size*sizeof(unsigned short);
                        if (header->mipmap_count > 1) data_size = data_size + data_size / 3;
                        image_data = RL_MALLOC(data_size);

                        memcpy(image_data, file_data_ptr, data_size);

                        unsigned char alpha = 0;

                        // NOTE: Data comes as A4R4G4B4, it must be reordered R4G4B4A4
                        for (int i = 0; i < image_pixel_size; i++)
                        {
                            alpha = ((unsigned short *)image_data)[i] >> 12;
                            ((unsigned short *)image_data)[i] = ((unsigned short *)image_data)[i] << 4;
                            ((unsigned short *)image_data)[i] += alpha;
                        }

                        *format = PIXELFORMAT_UNCOMPRESSED_R4G4B4A4;
                    }
                }
            }
            else if ((header->ddspf.flags == 0x40) && (header->ddspf.rgb_bit_count == 24))   // DDS_RGB, no compressed
            {
                int data_size = image_pixel_size*3*sizeof(unsigned char);
                if (header->mipmap_count > 1) data_size = data_size + data_size / 3;
                image_data = RL_MALLOC(data_size);

                memcpy(image_data, file_data_ptr, data_size);

                *format = PIXELFORMAT_UNCOMPRESSED_R8G8B8;
            }
            else if ((header->ddspf.flags == 0x41) && (header->ddspf.rgb_bit_count == 32)) // DDS_RGBA, no compressed
            {
                int data_size = image_pixel_size*4*sizeof(unsigned char);
                if (header->mipmap_count > 1) data_size = data_size + data_size / 3;
                image_data = RL_MALLOC(data_size);

                memcpy(image_data, file_data_ptr, data_size);

                unsigned char blue = 0;

                // NOTE: Data comes as A8R8G8B8, it must be reordered R8G8B8A8 (view next comment)
                // DirecX understand ARGB as a 32bit DWORD but the actual memory byte alignment is BGRA
                // So, we must realign B8G8R8A8 to R8G8B8A8
                for (int i = 0; i < image_pixel_size*4; i += 4)
                {
                    blue = ((unsigned char *)image_data)[i];
                    ((unsigned char *)image_data)[i] = ((unsigned char *)image_data)[i + 2];
                    ((unsigned char *)image_data)[i + 2] = blue;
                }

                *format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
            }
            else if (((header->ddspf.flags == 0x04) || (header->ddspf.flags == 0x05)) && (header->ddspf.fourcc > 0)) // Compressed
            {
                int data_size = 0;

                // Calculate data size, including all mipmaps
                if (header->mipmap_count > 1) data_size = header->pitch_or_linear_size + header->pitch_or_linear_size / 3;
                else data_size = header->pitch_or_linear_size;

                image_data = RL_MALLOC(data_size*sizeof(unsigned char));

                memcpy(image_data, file_data_ptr, data_size);

                switch (header->ddspf.fourcc)
                {
                    case FOURCC_DXT1:
                    {
                        if (header->ddspf.flags == 0x04) *format = PIXELFORMAT_COMPRESSED_DXT1_RGB;
                        else *format = PIXELFORMAT_COMPRESSED_DXT1_RGBA;
                    } break;
                    case FOURCC_DXT3: *format = PIXELFORMAT_COMPRESSED_DXT3_RGBA; break;
                    case FOURCC_DXT5: *format = PIXELFORMAT_COMPRESSED_DXT5_RGBA; break;
                    default: break;
                }
            }
        }
    }

    return image_data;
}

namespace
{

void WriteToMemory(void* context, void* data, int size) {
    std::vector<unsigned char>* buffer = reinterpret_cast<std::vector<unsigned char>*>(context);
    buffer->insert(buffer->end(), (unsigned char*)data, (unsigned char*)data + size);
}

}

bool ConverterHelper::ConvertDDSToPNG(const std::vector<uint8_t>& ddsData, std::vector<uint8_t>& pngData)
{
    throw std::runtime_error("Not implemented.");
}

bool nejlika::geometry::ConverterHelper::ConvertDDSToPNG(const std::vector<uint8_t> &ddsData, const std::filesystem::path &path)
{
    // Build the ImageMagick `convert` command
    // Write the DDS data to a temporary file
    // Execute the command
    std::string tempPath = GenerateRandomPath(std::filesystem::temp_directory_path(), ".dds").string();

    std::ofstream tempFile(tempPath, std::ios::binary);
    if (!tempFile.is_open()) {
        throw std::runtime_error("Failed to open temporary file for writing.");
    }

    tempFile.write(reinterpret_cast<const char*>(ddsData.data()), ddsData.size());

    tempFile.close();

    std::string command = "convert " + tempPath + " " + path.string();

    int result = std::system(command.c_str());

    if (result != 0) {
        throw std::runtime_error("Failed to convert DDS to PNG.");
    }

    // Remove the temporary file
    std::remove(tempPath.c_str());

    return true;
}

bool ConverterHelper::MapToPNG(
    const std::vector<float>& heightMap, int width, int height, 
    float minVal, float maxVal, std::vector<uint8_t>& pngData
) {
    if (width * height != heightMap.size()) {
        throw std::runtime_error("Heightmap size does not match dimensions.");
    }

    // Normalize the heightmap to 0-255
    std::vector<unsigned char> grayscale(heightMap.size());
    float range = maxVal - minVal;

    for (size_t i = 0; i < heightMap.size(); ++i) {
        // Clamp values to the min and max range
        float normalized = (heightMap[i] - minVal) / range;
        normalized = std::clamp(normalized, 0.0f, 1.0f);
        grayscale[i] = static_cast<unsigned char>(std::round(normalized * 255));
    }

    // Write PNG to memory
    pngData.clear();
    auto writeToMemory = [](void* context, void* data, int size) {
        auto* buffer = reinterpret_cast<std::vector<unsigned char>*>(context);
        buffer->insert(buffer->end(), (unsigned char*)data, (unsigned char*)data + size);
    };

    if (!stbi_write_png_to_func(writeToMemory, &pngData, width, height, 1, grayscale.data(), width)) {
        throw std::runtime_error("Failed to encode PNG.");
    }

    return true;
}

bool nejlika::geometry::ConverterHelper::MapToPNG(const std::vector<float> &heightMap, int width, int height, float minVal, float maxVal, const std::filesystem::path &path)
{
    if (width * height != heightMap.size()) {
        throw std::runtime_error("Heightmap size does not match dimensions.");
    }

    // Ensure the output directory exists
    try {
        std::filesystem::create_directories(path.parent_path());
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to create output directory: " + std::string(e.what()));
    }

    // Normalize the heightmap to 0-255
    std::vector<unsigned char> grayscale(heightMap.size());
    float range = maxVal - minVal;

    for (size_t i = 0; i < heightMap.size(); ++i) {
        float normalized = (heightMap[i] - minVal) / range;
        normalized = std::clamp(normalized, 0.0f, 1.0f);
        grayscale[i] = static_cast<unsigned char>(std::round(normalized * 255));
    }

    // Write PNG to file
    int success = stbi_write_png(path.string().c_str(), width, height, 1, grayscale.data(), width);
    if (!success) {
        throw std::runtime_error("Failed to write PNG to file at: " + path.string());
    }

    return true;
}

bool nejlika::geometry::ConverterHelper::MapToPNG(const std::vector<uint8_t> &data, int width, int height, const std::filesystem::path &path)
{
    if (width * height != data.size()) {
        throw std::runtime_error("Data size does not match dimensions.");
    }

    // Ensure the output directory exists
    try {
        std::filesystem::create_directories(path.parent_path());
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to create output directory: " + std::string(e.what()));
    }

    // Write PNG to file
    int success = stbi_write_png(path.string().c_str(), width, height, 1, data.data(), width);
    if (!success) {
        throw std::runtime_error("Failed to write PNG to file at: " + path.string());
    }

    return true;
}

bool nejlika::geometry::ConverterHelper::ColorMapToPNG(const std::vector<color4> &colorMap, int width, int height, const std::filesystem::path &path)
{
    if (width * height != colorMap.size()) {
        throw std::runtime_error("Color map size does not match dimensions.");
    }
    
    /*
    struct color4
    {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        uint8_t a = 0;
    };
    */

    std::vector<unsigned char> rgba(colorMap.size() * 4);

    for (size_t i = 0; i < colorMap.size(); ++i) {
        rgba[i * 4 + 0] = colorMap[i].r;
        rgba[i * 4 + 1] = colorMap[i].g;
        rgba[i * 4 + 2] = colorMap[i].b;
        rgba[i * 4 + 3] = colorMap[i].a;
    }

    if (!stbi_write_png(path.string().c_str(), width, height, 4, rgba.data(), width * 4)) {
        throw std::runtime_error("Failed to write PNG to file.");
    }

    return true;
}

std::filesystem::path nejlika::geometry::ConverterHelper::GenerateRandomPath(const std::filesystem::path &directory, const std::string &extension)
{
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::string filename = boost::uuids::to_string(uuid) + extension;
    return directory / filename;
}
