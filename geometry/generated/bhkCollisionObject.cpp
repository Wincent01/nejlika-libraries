#include "bhkCollisionObject.hpp"

using namespace nejlika::geometry;

void bhkCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkNiCollisionObject::Read(reader, version, user, arg);

}

void bhkCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkNiCollisionObject::Write(writer, version, user, arg);

}
