#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <unordered_map>

#include "Reader.hpp"
#include "Writer.hpp"

#include "numerics.hpp"

namespace nejlika::world {

class TerrainDirectDrawSurface
{
public:
    TerrainDirectDrawSurface() = default;

    TerrainDirectDrawSurface(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const std::vector<uint8_t>& GetData() const;

    void SetData(const std::vector<uint8_t>& data);

    ~TerrainDirectDrawSurface();

private:
    std::vector<uint8_t> m_Data;
};


}
