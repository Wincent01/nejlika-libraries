#include "TerrainFoliage.hpp"

using namespace nejlika::world;

TerrainFoliage::TerrainFoliage(nejlika::Reader& io)
{
    m_Type = io.Read<uint32_t>();

    m_Scale = io.Read<float>();

    m_Position = io.Read<vector3>();

    m_Rotation = io.Read<vector3>();

    m_Color = io.Read<color4>();
}

void TerrainFoliage::Save(nejlika::Writer& io) const
{
    io.Write(m_Type);

    io.Write(m_Scale);

    io.Write(m_Position);

    io.Write(m_Rotation);

    io.Write(m_Color);
}

uint32_t TerrainFoliage::GetType() const
{
    return m_Type;
}

float TerrainFoliage::GetScale() const
{
    return m_Scale;
}

const vector3& TerrainFoliage::GetPosition() const
{
    return m_Position;
}

const vector3& TerrainFoliage::GetRotation() const
{
    return m_Rotation;
}

const color4& TerrainFoliage::GetColor() const
{
    return m_Color;
}

void TerrainFoliage::SetType(uint32_t type)
{
    m_Type = type;
}

void TerrainFoliage::SetScale(float scale)
{
    m_Scale = scale;
}

void TerrainFoliage::SetPosition(const vector3& position)
{
    m_Position = position;
}

void TerrainFoliage::SetRotation(const vector3& rotation)
{
    m_Rotation = rotation;
}

void TerrainFoliage::SetColor(const color4& color)
{
    m_Color = color;
}

TerrainFoliage::~TerrainFoliage()
{
}