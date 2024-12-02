#include "NiBSplineInterpolator.hpp"

using namespace nejlika::geometry;

void NiBSplineInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpolator::Read(reader, version, user, arg);

    m_StartTime = reader.Read<float>();

    m_StopTime = reader.Read<float>();

    m_SplineData.Read(reader, version, user, 0);

    m_BasisData.Read(reader, version, user, 0);

}

void NiBSplineInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpolator::Write(writer, version, user, arg);

    writer.Write(m_StartTime);

    writer.Write(m_StopTime);

    m_SplineData.Write(writer, version, user, 0);

    m_BasisData.Write(writer, version, user, 0);

}
