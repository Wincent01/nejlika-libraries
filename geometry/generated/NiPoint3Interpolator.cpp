#include "NiPoint3Interpolator.hpp"

using namespace nejlika::geometry;

void NiPoint3Interpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyBasedInterpolator::Read(reader, version, user, arg);

    m_Point3Value.Read(reader, version, user, 0);

    m_Data.Read(reader, version, user, 0);

}

void NiPoint3Interpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyBasedInterpolator::Write(writer, version, user, arg);

    m_Point3Value.Write(writer, version, user, 0);

    m_Data.Write(writer, version, user, 0);

}
