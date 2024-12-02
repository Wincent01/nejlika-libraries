#pragma once

#include <Writer.hpp>

namespace nejlika::world
{

class WorldSerialize
{
public:
    virtual void Save(nejlika::Writer& io, version version) const = 0;

    virtual ~WorldSerialize() = default;
};

}

