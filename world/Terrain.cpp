#include "Terrain.hpp"

#include <sstream>

using namespace nejlika::world;

Terrain::Terrain(nejlika::Reader& io)
{
    // Assert that the magic (first three bytes) is 0x20/0x1F 0x00 0x00
    m_Version = io.Read<uint8_t>();
    if ((m_Version != 0x20 && m_Version != 0x1F) || io.Read<uint8_t>() != 0x00 || io.Read<uint8_t>() != 0x00)
    {
        std::stringstream ss;

        ss << "Invalid terrain version: " << m_Version;

        throw std::runtime_error(ss.str());
    }

    int32_t totalChunks = io.Read<int32_t>();

    m_Width = io.Read<int32_t>();
    m_Height = io.Read<int32_t>();

    // Assert that the total number of chunks is equal to the width * height
    if (totalChunks != m_Width * m_Height)
    {
        std::stringstream ss;

        ss << "Invalid terrain size: " << totalChunks << " != " << m_Width << " * " << m_Height;

        throw std::runtime_error(ss.str());
    }

    m_Chunks.reserve(totalChunks);

    for (int32_t i = 0; i < totalChunks; i++)
    {
        m_Chunks.emplace_back(io, m_Version);
    }
}

void Terrain::Save(nejlika::Writer& io) const
{
    io.Write<uint8_t>(static_cast<uint8_t>(m_Version));
    io.Write<uint8_t>(0x00);
    io.Write<uint8_t>(0x00);

    if (m_Chunks.size() != m_Width * m_Height)
    {
        throw std::runtime_error("Invalid terrain size");
    }

    io.Write<int32_t>(m_Chunks.size());

    io.Write<int32_t>(m_Width);
    io.Write<int32_t>(m_Height);

    for (const auto& chunk : m_Chunks)
    {
        chunk.Save(io, m_Version);
    }
}

const std::vector<TerrainChunk>& Terrain::GetChunks() const
{
    return m_Chunks;
}

const TerrainChunk& nejlika::world::Terrain::GetChunk(int32_t x, int32_t y) const
{
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
    {
        throw std::out_of_range("Chunk coordinates out of range");
    }

    return m_Chunks[y * m_Width + x];
}

TerrainChunk& nejlika::world::Terrain::GetChunk(int32_t x, int32_t y)
{
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
    {
        throw std::out_of_range("Chunk coordinates out of range");
    }

    return m_Chunks[y * m_Width + x];
}

int32_t Terrain::GetVersion() const
{
    return m_Version;
}

int32_t Terrain::GetWidth() const
{
    return m_Width;
}

int32_t Terrain::GetHeight() const
{
    return m_Height;
}

void Terrain::SetChunks(const std::vector<TerrainChunk>& chunks)
{
    m_Chunks = chunks;
}

void Terrain::SetVersion(int32_t version)
{
    m_Version = version;
}

void Terrain::SetWidth(int32_t width)
{
    m_Width = width;
}

void Terrain::SetHeight(int32_t height)
{
    m_Height = height;
}

void nejlika::world::Terrain::AllocateChunks(int32_t width, int32_t height)
{
    m_Width = width;
    m_Height = height;
    m_Chunks.resize(width * height);
}

Terrain::~Terrain()
{
    m_Chunks.clear();
}