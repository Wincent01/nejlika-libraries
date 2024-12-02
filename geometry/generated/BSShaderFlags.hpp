#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Shader Property Flags
 *         
 */
enum BSShaderFlags : uint
{
    /**
     * Enables Specularity
     */
    SF_Specular = 0,
    /**
     * Required For Skinned Meshes
     */
    SF_Skinned = 1,
    /**
     * Lowddetail (seems to use standard diff/norm/spec shader)
     */
    SF_LowDetail = 2,
    /**
     * Vertex Alpha
     */
    SF_Vertex_Alpha = 3,
    /**
     * Unknown
     */
    SF_Unknown_1 = 4,
    /**
     * Single Pass
     */
    SF_Single_Pass = 5,
    /**
     * Unknown
     */
    SF_Empty = 6,
    /**
     * Environment mapping (uses Envmap Scale)
     */
    SF_Environment_Mapping = 7,
    /**
     * Alpha Texture Requires NiAlphaProperty to Enable
     */
    SF_Alpha_Texture = 8,
    /**
     * Unknown
     */
    SF_Unknown_2 = 9,
    /**
     * FaceGen
     */
    SF_FaceGen = 10,
    /**
     * Parallax
     */
    SF_Parallax_Shader_Index_15 = 11,
    /**
     * Unknown/Crash
     */
    SF_Unknown_3 = 12,
    /**
     * Non-Projective Shadows
     */
    SF_Non_Projective_Shadows = 13,
    /**
     * Unknown/Crash
     */
    SF_Unknown_4 = 14,
    /**
     * Refraction (switches on refraction power)
     */
    SF_Refraction = 15,
    /**
     * Fire Refraction (switches on refraction power/period)
     */
    SF_Fire_Refraction = 16,
    /**
     * Eye Environment Mapping (does not use envmap light fade or envmap scale)
     */
    SF_Eye_Environment_Mapping = 17,
    /**
     * Hair
     */
    SF_Hair = 18,
    /**
     * Dynamic Alpha
     */
    SF_Dynamic_Alpha = 19,
    /**
     * Localmap Hide Secret
     */
    SF_Localmap_Hide_Secret = 20,
    /**
     * Window Environment Mapping
     */
    SF_Window_Environment_Mapping = 21,
    /**
     * Tree Billboard
     */
    SF_Tree_Billboard = 22,
    /**
     * Shadow Frustum
     */
    SF_Shadow_Frustum = 23,
    /**
     * Multiple Textures (base diff/norm become null)
     */
    SF_Multiple_Textures = 24,
    /**
     * usually seen w/texture animation
     */
    SF_Remappable_Textures = 25,
    /**
     * Decal
     */
    SF_Decal_Single_Pass = 26,
    /**
     * Dynamic Decal
     */
    SF_Dynamic_Decal_Single_Pass = 27,
    /**
     * Parallax Occlusion
     */
    SF_Parallax_Occulsion = 28,
    /**
     * External Emittance
     */
    SF_External_Emittance = 29,
    /**
     * Shadow Map
     */
    SF_Shadow_Map = 30,
    /**
     * ZBuffer Test (1=on)
     */
    SF_ZBuffer_Test = 31,
};

}
