#include "RenderAttribute.hpp"

using namespace nejlika::world;

nejlika::world::RenderAttribute::RenderAttribute(nejlika::Reader &io)
{
    char name[64];

    for (uint32_t i = 0; i < 64; ++i) {
        name[i] = io.Read<char>();
    }

    m_Name = std::string(name);

    m_Number = io.Read<uint32_t>();

    m_IsColor = io.Read<bool>();

    // Assert that number is 4
    if (m_Number != 4) {
        throw std::runtime_error("Number is not 4");
    }

    for (uint32_t i = 0; i < m_Number; ++i) {
        m_Values.push_back(io.Read<float>());
    }
}

void nejlika::world::RenderAttribute::Save(nejlika::Writer &io) const
{
    for (uint32_t i = 0; i < 64; ++i) {
        io.Write<char>(m_Name[i]);
    }

    io.Write(m_Number);

    io.Write(m_IsColor);

    for (const float &value : m_Values) {
        io.Write(value);
    }
}

const std::string &nejlika::world::RenderAttribute::GetName() const
{
    return m_Name;
}

uint32_t nejlika::world::RenderAttribute::GetNumber() const
{
    return m_Number;
}

bool nejlika::world::RenderAttribute::IsColor() const
{
    return m_IsColor;
}

const std::vector<float> &nejlika::world::RenderAttribute::GetValues() const
{
    return m_Values;
}

nejlika::world::RenderAttribute::~RenderAttribute()
{
}
