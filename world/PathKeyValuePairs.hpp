#pragma once

#include <string>
#include <map>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"

namespace nejlika::world
{

class PathKeyValuePairs
{
public:
    PathKeyValuePairs() = default;

    PathKeyValuePairs(const PathKeyValuePairs& other);

    PathKeyValuePairs(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    const std::map<str16, str16>& GetKeyValuePairs() const;

    ~PathKeyValuePairs();

private:
    std::map<str16, str16> m_KeyValuePairs;
};

}