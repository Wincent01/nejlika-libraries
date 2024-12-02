#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "NiBSplineInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An interpolator for storing transform keyframes via a B-spline.
 *         
 */
class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
protected:
    /**
     * Base translation when translate curve not defined.
     */
    Vector3 m_Translation;
    /**
     * Base rotation when rotation curve not defined.
     */
    Quaternion m_Rotation;
    /**
     * Base scale when scale curve not defined.
     */
    float m_Scale;
    /**
     * Starting offset for the translation data. (USHRT_MAX for no data.)
     */
    uint m_TranslationOffset;
    /**
     * Starting offset for the rotation data. (USHRT_MAX for no data.)
     */
    uint m_RotationOffset;
    /**
     * Starting offset for the scale data. (USHRT_MAX for no data.)
     */
    uint m_ScaleOffset;

public:
    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Quaternion& GetRotation() const { return m_Rotation; }
    Quaternion& GetRotation() { return m_Rotation; }
    void SetRotation(const Quaternion& value) { m_Rotation = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const uint& GetTranslationOffset() const { return m_TranslationOffset; }
    uint& GetTranslationOffset() { return m_TranslationOffset; }
    void SetTranslationOffset(const uint& value) { m_TranslationOffset = value; }

    const uint& GetRotationOffset() const { return m_RotationOffset; }
    uint& GetRotationOffset() { return m_RotationOffset; }
    void SetRotationOffset(const uint& value) { m_RotationOffset = value; }

    const uint& GetScaleOffset() const { return m_ScaleOffset; }
    uint& GetScaleOffset() { return m_ScaleOffset; }
    void SetScaleOffset(const uint& value) { m_ScaleOffset = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
