#include "bhkPCollisionObject.hpp"

using namespace nejlika::geometry;

void bhkPCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkNiCollisionObject::Read(reader, version, user, arg);

}

void bhkPCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkNiCollisionObject::Write(writer, version, user, arg);

}
