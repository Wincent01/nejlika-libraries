#pragma once

#include <cstdint>
#include <string>

namespace nejlika::geometry {

/**
 * 
 *         Values for configuring the shader type in a BSLightingShaderProperty
 *         
 */
enum BSLightingShaderPropertyShaderType : uint
{
    Default = 0,
    /**
     * Enables EnvMap Mask(TS6), EnvMap Scale
     */
    EnvironmentMap = 1,
    /**
     * Enables Glow(TS3)
     */
    GlowShader = 2,
    /**
     * Enables Height(TS4)
     */
    Heightmap = 3,
    /**
     * Enables SubSurface(TS3), Detail(TS4), Tint(TS7)
     */
    FaceTint = 4,
    /**
     * Enables Skin Tint Color
     */
    SkinTint = 5,
    /**
     * Enables Hair Tint Color
     */
    HairTint = 6,
    /**
     * Enables Height(TS4), Max Passes, Scale.  Unused?
     */
    ParallaxOccMaterial = 7,
    WorldMultitexture = 8,
    WorldMap1 = 9,
    Unknown10 = 10,
    /**
     * Enables EnvMap Mask(TS6), Layer(TS7), Parallax Layer Thickness, Parallax Refraction Scale, Parallax Inner Layer U Scale, Parallax Inner Layer V Scale, EnvMap Scale
     */
    MultiLayerParallax = 11,
    Unknown12 = 12,
    WorldMap2 = 13,
    /**
     * Enables SparkleParams
     */
    SparkleSnow = 14,
    WorldMap3 = 15,
    /**
     * Enables EnvMap Mask(TS6), Eye EnvMap Scale
     */
    EyeEnvmap = 16,
    Unknown17 = 17,
    WorldMap4 = 18,
    WorldLODMultitexture = 19,
};

}
