#include "bhkHingeConstraint.hpp"

using namespace nejlika::geometry;

void bhkHingeConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_Hinge.Read(reader, version, user, 0);

}

void bhkHingeConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    m_Hinge.Write(writer, version, user, 0);

}
