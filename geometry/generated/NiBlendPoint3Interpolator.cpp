#include "NiBlendPoint3Interpolator.hpp"

using namespace nejlika::geometry;

void NiBlendPoint3Interpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiBlendInterpolator::Read(reader, version, user, arg);

    m_PointValue.Read(reader, version, user, 0);

}

void NiBlendPoint3Interpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiBlendInterpolator::Write(writer, version, user, arg);

    m_PointValue.Write(writer, version, user, 0);

}
