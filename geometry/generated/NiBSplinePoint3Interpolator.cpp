#include "NiBSplinePoint3Interpolator.hpp"

using namespace nejlika::geometry;

void NiBSplinePoint3Interpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBSplineInterpolator::Read(reader, version, user, arg);

    m_UnknownFloats.resize(6);
    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        m_UnknownFloats[i] = reader.Read<float>();
    }

}

void NiBSplinePoint3Interpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBSplineInterpolator::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        writer.Write(m_UnknownFloats[i]);
    }

}
