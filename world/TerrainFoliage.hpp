#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"

namespace nejlika::world {

class TerrainFoliage
{
public:
    TerrainFoliage() = default;

    TerrainFoliage(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    uint32_t GetType() const;

    float GetScale() const;

    const vector3& GetPosition() const;

    const vector3& GetRotation() const;

    const color4& GetColor() const;

    void SetType(uint32_t type);

    void SetScale(float scale);

    void SetPosition(const vector3& position);

    void SetRotation(const vector3& rotation);

    void SetColor(const color4& color);

    ~TerrainFoliage();

private:
    uint32_t m_Type = 0;

    float m_Scale = 0;

    vector3 m_Position;

    vector3 m_Rotation;

    color4 m_Color;
};


}
