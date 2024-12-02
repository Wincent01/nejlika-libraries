#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         This enum contains the options for doing z buffer tests.
 *         
 */
enum ZCompareMode : uint
{
    /**
     * Test will allways succeed. The Z Buffer value is ignored.
     */
    ZCOMP_ALWAYS = 0,
    /**
     * The test will only succeed if the pixel is nearer than the previous pixel.
     */
    ZCOMP_LESS = 1,
    /**
     * Test will only succeed if the z value of the pixel to be drawn is equal to the value of the previous drawn pixel.
     */
    ZCOMP_EQUAL = 2,
    /**
     * Test will succeed if the z value of the pixel to be drawn is smaller than or equal to the value in the Z Buffer.
     */
    ZCOMP_LESS_EQUAL = 3,
    /**
     * Opposite of TEST_LESS.
     */
    ZCOMP_GREATER = 4,
    /**
     * Test will succeed if the z value of the pixel to be drawn is NOT equal to the value of the previously drawn pixel.
     */
    ZCOMP_NOT_EQUAL = 5,
    /**
     * Opposite of TEST_LESS_EQUAL.
     */
    ZCOMP_GREATER_EQUAL = 6,
    /**
     * Test will allways return false. Nothing is drawn at all.
     */
    ZCOMP_NEVER = 7,
};

}
