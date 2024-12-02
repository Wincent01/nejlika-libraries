#include "NiBSplineCompFloatInterpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineCompFloatInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplineFloatInterpolator::Read(reader, version, user, arg);

    m_Base = reader.Read<float>();

    m_Offset = reader.Read<uint>();

    m_Bias = reader.Read<float>();

    m_Multiplier = reader.Read<float>();

}

void NiBSplineCompFloatInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplineFloatInterpolator::Write(writer, version, user, arg);

    writer.Write(m_Base);

    writer.Write(m_Offset);

    writer.Write(m_Bias);

    writer.Write(m_Multiplier);

}
