#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Matrix33.hpp"
#include "Vector3.hpp"
#include "TexFilterMode.hpp"
#include "TexClampMode.hpp"
#include "EffectType.hpp"
#include "CoordGenType.hpp"
#include "NiImage.hpp"
#include "NiSourceTexture.hpp"
#include "Vector3.hpp"
#include "NiDynamicEffect.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Enables environment mapping. Should be in both the children list and effects list of the NiTriShape object. For Morrowind: the bump map can be used to bump the environment map (note that the bump map is ignored if no NiTextureEffect object is present).
 *         
 */
class NiTextureEffect : public NiDynamicEffect
{
protected:
    /**
     * Model projection matrix.  Always identity?
     */
    Matrix33 m_ModelProjectionMatrix;
    /**
     * Model projection transform.  Always (0,0,0)?
     */
    Vector3 m_ModelProjectionTransform;
    /**
     * Texture Filtering mode.
     */
    TexFilterMode m_TextureFiltering;
    /**
     * Texture Clamp mode.
     */
    TexClampMode m_TextureClamping;
    short m_Unknown;
    /**
     * The type of effect that the texture is used for.
     */
    EffectType m_TextureType;
    /**
     * The method that will be used to generate UV coordinates for the texture effect.
     */
    CoordGenType m_CoordinateGenerationType;
    /**
     * Image index.
     */
    Pointer<class NiImage*> m_Image;
    /**
     * Source texture index.
     */
    Pointer<class NiSourceTexture*> m_SourceTexture;
    /**
     * Determines whether a clipping plane is used.  0 means that a plane is not used.
     */
    byte m_ClippingPlane;
    /**
     * Unknown: (1,0,0)?
     */
    Vector3 m_UnknownVector;
    /**
     * Unknown. 0?
     */
    float m_UnknownFloat;
    /**
     * 0?
     */
    short m_PS2L;
    /**
     * -75?
     */
    short m_PS2K;
    /**
     * Unknown: 0.
     */
    ushort m_UnknownShort;

public:
    const Matrix33& GetModelProjectionMatrix() const { return m_ModelProjectionMatrix; }
    Matrix33& GetModelProjectionMatrix() { return m_ModelProjectionMatrix; }
    void SetModelProjectionMatrix(const Matrix33& value) { m_ModelProjectionMatrix = value; }

    const Vector3& GetModelProjectionTransform() const { return m_ModelProjectionTransform; }
    Vector3& GetModelProjectionTransform() { return m_ModelProjectionTransform; }
    void SetModelProjectionTransform(const Vector3& value) { m_ModelProjectionTransform = value; }

    const TexFilterMode& GetTextureFiltering() const { return m_TextureFiltering; }
    TexFilterMode& GetTextureFiltering() { return m_TextureFiltering; }
    void SetTextureFiltering(const TexFilterMode& value) { m_TextureFiltering = value; }

    const TexClampMode& GetTextureClamping() const { return m_TextureClamping; }
    TexClampMode& GetTextureClamping() { return m_TextureClamping; }
    void SetTextureClamping(const TexClampMode& value) { m_TextureClamping = value; }

    const short& GetUnknown() const { return m_Unknown; }
    short& GetUnknown() { return m_Unknown; }
    void SetUnknown(const short& value) { m_Unknown = value; }

    const EffectType& GetTextureType() const { return m_TextureType; }
    EffectType& GetTextureType() { return m_TextureType; }
    void SetTextureType(const EffectType& value) { m_TextureType = value; }

    const CoordGenType& GetCoordinateGenerationType() const { return m_CoordinateGenerationType; }
    CoordGenType& GetCoordinateGenerationType() { return m_CoordinateGenerationType; }
    void SetCoordinateGenerationType(const CoordGenType& value) { m_CoordinateGenerationType = value; }

    const Pointer<class NiImage*>& GetImage() const { return m_Image; }
    Pointer<class NiImage*>& GetImage() { return m_Image; }
    void SetImage(const Pointer<class NiImage*>& value) { m_Image = value; }

    const Pointer<class NiSourceTexture*>& GetSourceTexture() const { return m_SourceTexture; }
    Pointer<class NiSourceTexture*>& GetSourceTexture() { return m_SourceTexture; }
    void SetSourceTexture(const Pointer<class NiSourceTexture*>& value) { m_SourceTexture = value; }

    const byte& GetClippingPlane() const { return m_ClippingPlane; }
    byte& GetClippingPlane() { return m_ClippingPlane; }
    void SetClippingPlane(const byte& value) { m_ClippingPlane = value; }

    const Vector3& GetUnknownVector() const { return m_UnknownVector; }
    Vector3& GetUnknownVector() { return m_UnknownVector; }
    void SetUnknownVector(const Vector3& value) { m_UnknownVector = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const short& GetPS2L() const { return m_PS2L; }
    short& GetPS2L() { return m_PS2L; }
    void SetPS2L(const short& value) { m_PS2L = value; }

    const short& GetPS2K() const { return m_PS2K; }
    short& GetPS2K() { return m_PS2K; }
    void SetPS2K(const short& value) { m_PS2K = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
