#include "RenderTechnique.hpp"

using namespace nejlika::world;

nejlika::world::RenderTechnique::RenderTechnique(nejlika::Reader &io)
{
    const uint32_t attributeCount = io.Read<uint32_t>();

    if (attributeCount > 0) {
        char name[64];

        for (uint32_t i = 0; i < 64; ++i) {
            name[i] = io.Read<char>();
        }

        m_Name = std::string(name);
    }

    m_Attributes.reserve(attributeCount);

    for (uint32_t i = 0; i < attributeCount; ++i) {
        m_Attributes.push_back(RenderAttribute(io));
    }
}

void nejlika::world::RenderTechnique::Save(nejlika::Writer &io) const
{
    io.Write<uint32_t>(m_Attributes.size());

    if (m_Attributes.size() > 0) {
        for (uint32_t i = 0; i < 64; ++i) {
            io.Write<char>(m_Name[i]);
        }
    }

    for (const RenderAttribute &attribute : m_Attributes) {
        attribute.Save(io);
    }
}

const std::string &nejlika::world::RenderTechnique::GetName() const
{
    return m_Name;
}

const std::vector<nejlika::world::RenderAttribute> &nejlika::world::RenderTechnique::GetAttributes() const
{
    return m_Attributes;
}

nejlika::world::RenderTechnique::~RenderTechnique()
{
}