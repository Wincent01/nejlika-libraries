#include "PathKeyValuePairs.hpp"

nejlika::world::PathKeyValuePairs::PathKeyValuePairs(const PathKeyValuePairs &other)
{
    for (const auto &pair : other.m_KeyValuePairs)
    {
        m_KeyValuePairs.emplace(pair.first, pair.second);
    }
}

nejlika::world::PathKeyValuePairs::PathKeyValuePairs(nejlika::Reader &io, version version)
{
    uint32_t num = io.Read<uint32_t>();

    for (size_t i = 0; i < num; i++)
    {
        str16 key = io.ReadString16<uint8_t>();
        str16 value = io.ReadString16<uint8_t>();

        m_KeyValuePairs.emplace(key, value);
    }
}

void nejlika::world::PathKeyValuePairs::Save(nejlika::Writer &io, version version) const
{
    io.Write<uint32_t>(m_KeyValuePairs.size());

    for (const auto &pair : m_KeyValuePairs)
    {
        io.WriteString16<uint8_t>(pair.first);
        io.WriteString16<uint8_t>(pair.second);
    }
}

const std::map<str16, str16> &nejlika::world::PathKeyValuePairs::GetKeyValuePairs() const
{
    return m_KeyValuePairs;
}

nejlika::world::PathKeyValuePairs::~PathKeyValuePairs()
{
}
