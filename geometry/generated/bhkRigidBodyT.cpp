#include "bhkRigidBodyT.hpp"

using namespace nejlika::geometry;

void bhkRigidBodyT::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkRigidBody::Read(reader, version, user, arg);

}

void bhkRigidBodyT::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkRigidBody::Write(writer, version, user, arg);

}
