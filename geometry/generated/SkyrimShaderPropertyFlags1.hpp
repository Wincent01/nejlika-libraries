#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Skyrim Shader Property Flags 1
 *         
 */
enum SkyrimShaderPropertyFlags1 : uint
{
    /**
     * Enables Specularity
     */
    SLSF1_Specular = 0,
    /**
     * Required For Skinned Meshes.
     */
    SLSF1_Skinned = 1,
    /**
     * Unknown
     */
    SLSF1_Temp_Refraction = 2,
    /**
     * Enables using alpha component of vertex colors.
     */
    SLSF1_Vertex_Alpha = 3,
    /**
     * in EffectShaderProperty
     */
    SLSF1_Greyscale_To_PaletteColor = 4,
    /**
     * in EffectShaderProperty
     */
    SLSF1_Greyscale_To_PaletteAlpha = 5,
    /**
     * Use Falloff value in EffectShaderProperty
     */
    SLSF1_Use_Falloff = 6,
    /**
     * Environment mapping (uses Envmap Scale).
     */
    SLSF1_Environment_Mapping = 7,
    /**
     * Object can recieve shadows.
     */
    SLSF1_Recieve_Shadows = 8,
    /**
     * Can cast shadows
     */
    SLSF1_Cast_Shadows = 9,
    /**
     * Use a face detail map in the 4th texture slot.
     */
    SLSF1_Facegen_Detail_Map = 10,
    /**
     * Unused?
     */
    SLSF1_Parallax = 11,
    /**
     * Use Model space normals and an external Specular Map.
     */
    SLSF1_Model_Space_Normals = 12,
    /**
     * Unknown.
     */
    SLSF1_Non_Projective_Shadows = 13,
    /**
     * Unknown.
     */
    SLSF1_Landscape = 14,
    /**
     * Use normal map for refraction effect.
     */
    SLSF1_Refraction = 15,
    SLSF1_Fire_Refraction = 16,
    /**
     * Eye Environment Mapping (Must use the Eye shader and the model must be skinned)
     */
    SLSF1_Eye_Environment_Mapping = 17,
    /**
     * Keeps from going too bright under lights (hair shader only)
     */
    SLSF1_Hair_Soft_Lighting = 18,
    SLSF1_Screendoor_Alpha_Fade = 19,
    /**
     * Object and anything it is positioned above will not render on local map view.
     */
    SLSF1_Localmap_Hide_Secret = 20,
    /**
     * Use tintmask for Face.
     */
    SLSF1_FaceGen_RGB_Tint = 21,
    /**
     * Provides its own emittance color. (will not absorb light/ambient color?)
     */
    SLSF1_Own_Emit = 22,
    /**
     * Used for decalling?
     */
    SLSF1_Projected_UV = 23,
    SLSF1_Multiple_Textures = 24,
    SLSF1_Remappable_Textures = 25,
    SLSF1_Decal = 26,
    SLSF1_Dynamic_Decal = 27,
    SLSF1_Parallax_Occlusion = 28,
    SLSF1_External_Emittance = 29,
    SLSF1_Soft_Effect = 30,
    /**
     * ZBuffer Test (1=on)
     */
    SLSF1_ZBuffer_Test = 31,
};

}
