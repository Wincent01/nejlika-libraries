#pragma once

#include <cstdint>

#include <Reader.hpp>
#include <Writer.hpp>

namespace nejlika::geometry {

class Construct
{
public:
    virtual void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg) = 0;

    virtual void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const = 0;

    virtual ~Construct() = default;
};

}