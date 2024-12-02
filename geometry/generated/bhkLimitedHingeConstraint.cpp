#include "bhkLimitedHingeConstraint.hpp"

using namespace nejlika::geometry;

void bhkLimitedHingeConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_LimitedHinge.Read(reader, version, user, 0);

}

void bhkLimitedHingeConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    m_LimitedHinge.Write(writer, version, user, 0);

}
