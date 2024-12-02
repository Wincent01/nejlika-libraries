#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Determines how a data stream is used?
 *         
 */
enum DataStreamUsage : uint
{
    USAGE_VERTEX_INDEX = 0,
    USAGE_VERTEX = 1,
    USAGE_SHADER_CONSTANT = 2,
    USAGE_USER = 3,
};

}
