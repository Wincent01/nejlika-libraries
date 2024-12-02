#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines how the data stream is accessed?
 *         
 */
enum DataStreamAccess : uint
{
    CPURead = 0,
    CPUWriteStatic = 1,
    CPUWriteMutable = 2,
    CPUWriteVolatile = 3,
    GPURead = 4,
    GPUWrite = 5,
    CPUWriteStaticInititialized = 6,
};

}
