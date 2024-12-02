#include "NiBSplineCompTransformInterpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineCompTransformInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplineTransformInterpolator::Read(reader, version, user, arg);

    m_TranslationBias = reader.Read<float>();

    m_TranslationMultiplier = reader.Read<float>();

    m_RotationBias = reader.Read<float>();

    m_RotationMultiplier = reader.Read<float>();

    m_ScaleBias = reader.Read<float>();

    m_ScaleMultiplier = reader.Read<float>();

}

void NiBSplineCompTransformInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplineTransformInterpolator::Write(writer, version, user, arg);

    writer.Write(m_TranslationBias);

    writer.Write(m_TranslationMultiplier);

    writer.Write(m_RotationBias);

    writer.Write(m_RotationMultiplier);

    writer.Write(m_ScaleBias);

    writer.Write(m_ScaleMultiplier);

}
