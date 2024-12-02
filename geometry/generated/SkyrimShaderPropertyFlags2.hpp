#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Skyrim Shader Property Flags 2
 *         
 */
enum SkyrimShaderPropertyFlags2 : uint
{
    /**
     * Enables writing to the Z-Buffer
     */
    SLSF2_ZBuffer_Write = 0,
    SLSF2_LOD_Landscape = 1,
    SLSF2_LOD_Objects = 2,
    SLSF2_No_Fade = 3,
    /**
     * Double-sided rendering.
     */
    SLSF2_Double_Sided = 4,
    /**
     * Has Vertex Colors.
     */
    SLSF2_Vertex_Colors = 5,
    /**
     * Use Glow Map in the third texture slot.
     */
    SLSF2_Glow_Map = 6,
    SLSF2_Assume_Shadowmask = 7,
    SLSF2_Packed_Tangent = 8,
    SLSF2_Multi_Index_Snow = 9,
    SLSF2_Vertex_Lighting = 10,
    SLSF2_Uniform_Scale = 11,
    SLSF2_Fit_Slope = 12,
    SLSF2_Billboard = 13,
    SLSF2_No_LOD_Land_Blend = 14,
    SLSF2_EnvMap_Light_Fade = 15,
    /**
     * Wireframe (Seems to only work on particles)
     */
    SLSF2_Wireframe = 16,
    /**
     * Used for blood decals on weapons.
     */
    SLSF2_Weapon_Blood = 17,
    /**
     * Similar to hide secret, but only for self?
     */
    SLSF2_Hide_On_Local_Map = 18,
    /**
     * Has Premultiplied Alpha
     */
    SLSF2_Premult_Alpha = 19,
    SLSF2_Cloud_LOD = 20,
    /**
     * Hair only?
     */
    SLSF2_Anisotropic_Lighting = 21,
    SLSF2_No_Transparency_Multisampling = 22,
    /**
     * Unused?
     */
    SLSF2_Unused01 = 23,
    /**
     * Use Multilayer (inner-layer) Map
     */
    SLSF2_Multi_Layer_Parallax = 24,
    /**
     * Use Soft Lighting Map
     */
    SLSF2_Soft_Lighting = 25,
    /**
     * Use Rim Lighting Map
     */
    SLSF2_Rim_Lighting = 26,
    /**
     * Use Back Lighting Map
     */
    SLSF2_Back_Lighting = 27,
    /**
     * Unused?
     */
    SLSF2_Unused02 = 28,
    /**
     * Enables Vertex Animation, Flutter Animation
     */
    SLSF2_Tree_Anim = 29,
    SLSF2_Effect_Lighting = 30,
    SLSF2_HD_LOD_Objects = 31,
};

}
