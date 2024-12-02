#include "TerrainDirectDrawSurface.hpp"

using namespace nejlika::world;

TerrainDirectDrawSurface::TerrainDirectDrawSurface(nejlika::Reader& io)
{
    m_Data.resize(io.Read<uint32_t>());

    for (auto& data : m_Data)
    {
        data = io.Read<uint8_t>();
    }
}

void TerrainDirectDrawSurface::Save(nejlika::Writer& io) const
{
    io.Write(static_cast<uint32_t>(m_Data.size()));

    for (const auto& data : m_Data)
    {
        io.Write(data);
    }
}

const std::vector<uint8_t>& TerrainDirectDrawSurface::GetData() const
{
    return m_Data;
}

void TerrainDirectDrawSurface::SetData(const std::vector<uint8_t>& data)
{
    m_Data = data;
}

TerrainDirectDrawSurface::~TerrainDirectDrawSurface()
{
    m_Data.clear();
}
