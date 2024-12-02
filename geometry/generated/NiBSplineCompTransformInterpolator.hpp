#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBSplineTransformInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An interpolator for storing transform keyframes via a compressed
 *         B-spline (that is, using shorts rather than floats in the B-spline
 *         data).
 *         
 */
class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
protected:
    /**
     * Translation Bias
     */
    float m_TranslationBias;
    /**
     * Translation Multiplier
     */
    float m_TranslationMultiplier;
    /**
     * Rotation Bias
     */
    float m_RotationBias;
    /**
     * Rotation Multiplier
     */
    float m_RotationMultiplier;
    /**
     * Scale Bias
     */
    float m_ScaleBias;
    /**
     * Scale Multiplier
     */
    float m_ScaleMultiplier;

public:
    const float& GetTranslationBias() const { return m_TranslationBias; }
    float& GetTranslationBias() { return m_TranslationBias; }
    void SetTranslationBias(const float& value) { m_TranslationBias = value; }

    const float& GetTranslationMultiplier() const { return m_TranslationMultiplier; }
    float& GetTranslationMultiplier() { return m_TranslationMultiplier; }
    void SetTranslationMultiplier(const float& value) { m_TranslationMultiplier = value; }

    const float& GetRotationBias() const { return m_RotationBias; }
    float& GetRotationBias() { return m_RotationBias; }
    void SetRotationBias(const float& value) { m_RotationBias = value; }

    const float& GetRotationMultiplier() const { return m_RotationMultiplier; }
    float& GetRotationMultiplier() { return m_RotationMultiplier; }
    void SetRotationMultiplier(const float& value) { m_RotationMultiplier = value; }

    const float& GetScaleBias() const { return m_ScaleBias; }
    float& GetScaleBias() { return m_ScaleBias; }
    void SetScaleBias(const float& value) { m_ScaleBias = value; }

    const float& GetScaleMultiplier() const { return m_ScaleMultiplier; }
    float& GetScaleMultiplier() { return m_ScaleMultiplier; }
    void SetScaleMultiplier(const float& value) { m_ScaleMultiplier = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
