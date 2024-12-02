#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

enum EndianType : byte
{
    /**
     * The numbers are stored in big endian format, such as those used by PowerPC Mac processors.
     */
    ENDIAN_BIG = 0,
    /**
     * The numbers are stored in little endian format, such as those used by Intel and AMD x86 processors.
     */
    ENDIAN_LITTLE = 1,
};

}
