#include "NiBSplineTransformInterpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineTransformInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplineInterpolator::Read(reader, version, user, arg);

    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_Scale = reader.Read<float>();

    m_TranslationOffset = reader.Read<uint>();

    m_RotationOffset = reader.Read<uint>();

    m_ScaleOffset = reader.Read<uint>();

}

void NiBSplineTransformInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplineInterpolator::Write(writer, version, user, arg);

    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    writer.Write(m_Scale);

    writer.Write(m_TranslationOffset);

    writer.Write(m_RotationOffset);

    writer.Write(m_ScaleOffset);

}
