#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

namespace nejlika::world
{

class RenderAttribute
{
public:
    RenderAttribute() = default;

    RenderAttribute(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const std::string& GetName() const;

    uint32_t GetNumber() const;

    bool IsColor() const;

    const std::vector<float>& GetValues() const;

    ~RenderAttribute();

private:
    std::string m_Name;
    uint32_t m_Number;
    bool m_IsColor;
    std::vector<float> m_Values;
};

}