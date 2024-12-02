#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "Path.hpp"

namespace nejlika::world
{

class PathInformation
{
public:
    PathInformation() = default;

    PathInformation(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    version GetPathVersion() const;

    std::vector<Path>& GetPaths();

    ~PathInformation();

private:
    version m_PathVersion;

    std::vector<Path> m_Paths;
};

}