#include "bhkRagdollConstraint.hpp"

using namespace nejlika::geometry;

void bhkRagdollConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_Ragdoll.Read(reader, version, user, 0);

}

void bhkRagdollConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    m_Ragdoll.Write(writer, version, user, 0);

}
