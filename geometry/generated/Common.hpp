#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "Pointer.hpp"

namespace nejlika::geometry {

typedef uint8_t byte;
typedef uint32_t StringIndex;
typedef uint32_t StringOffset;
typedef std::string HeaderString;
typedef std::string LineString;
typedef uint16_t Flags;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint16_t BlockTypeIndex;
typedef uint32_t FileVersion;
typedef uint ulittle32;

#define VERSION_NUMBER(a, b, c, d) ((a << 24) | (b << 16) | (c << 8) | d)


}
