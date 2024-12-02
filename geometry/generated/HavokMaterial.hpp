#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         A material, used by havok shape objects.
 *         
 */
enum HavokMaterial : uint
{
    /**
     * Stone
     */
    HAV_MAT_STONE = 0,
    /**
     * Cloth
     */
    HAV_MAT_CLOTH = 1,
    /**
     * Dirt
     */
    HAV_MAT_DIRT = 2,
    /**
     * Glass
     */
    HAV_MAT_GLASS = 3,
    /**
     * Grass
     */
    HAV_MAT_GRASS = 4,
    /**
     * Metal
     */
    HAV_MAT_METAL = 5,
    /**
     * Organic
     */
    HAV_MAT_ORGANIC = 6,
    /**
     * Skin
     */
    HAV_MAT_SKIN = 7,
    /**
     * Water
     */
    HAV_MAT_WATER = 8,
    /**
     * Wood
     */
    HAV_MAT_WOOD = 9,
    /**
     * Heavy Stone
     */
    HAV_MAT_HEAVY_STONE = 10,
    /**
     * Heavy Metal
     */
    HAV_MAT_HEAVY_METAL = 11,
    /**
     * Heavy Wood
     */
    HAV_MAT_HEAVY_WOOD = 12,
    /**
     * Chain
     */
    HAV_MAT_CHAIN = 13,
    /**
     * Snow
     */
    HAV_MAT_SNOW = 14,
    /**
     * Stone Stairs
     */
    HAV_MAT_STONE_STAIRS = 15,
    /**
     * Cloth Stairs
     */
    HAV_MAT_CLOTH_STAIRS = 16,
    /**
     * Dirt Stairs
     */
    HAV_MAT_DIRT_STAIRS = 17,
    /**
     * Glass Stairs
     */
    HAV_MAT_GLASS_STAIRS = 18,
    /**
     * Grass Stairs
     */
    HAV_MAT_GRASS_STAIRS = 19,
    /**
     * Metal Stairs
     */
    HAV_MAT_METAL_STAIRS = 20,
    /**
     * Organic Stairs
     */
    HAV_MAT_ORGANIC_STAIRS = 21,
    /**
     * Skin Stairs
     */
    HAV_MAT_SKIN_STAIRS = 22,
    /**
     * Water Stairs
     */
    HAV_MAT_WATER_STAIRS = 23,
    /**
     * Wood Stairs
     */
    HAV_MAT_WOOD_STAIRS = 24,
    /**
     * Heavy Stone Stairs
     */
    HAV_MAT_HEAVY_STONE_STAIRS = 25,
    /**
     * Heavy Metal Stairs
     */
    HAV_MAT_HEAVY_METAL_STAIRS = 26,
    /**
     * Heavy Wood Stairs
     */
    HAV_MAT_HEAVY_WOOD_STAIRS = 27,
    /**
     * Chain Stairs
     */
    HAV_MAT_CHAIN_STAIRS = 28,
    /**
     * Snow Stairs
     */
    HAV_MAT_SNOW_STAIRS = 29,
    /**
     * Elevator
     */
    HAV_MAT_ELEVATOR = 30,
    /**
     * Rubber
     */
    HAV_MAT_RUBBER = 31,
};

}
