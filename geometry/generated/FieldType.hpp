#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         The force field's type.
 *         
 */
enum FieldType : uint
{
    /**
     * Wind (fixed direction)
     */
    FIELD_WIND = 0,
    /**
     * Point (fixed origin)
     */
    FIELD_POINT = 1,
};

}
