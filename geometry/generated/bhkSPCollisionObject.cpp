#include "bhkSPCollisionObject.hpp"

using namespace nejlika::geometry;

void bhkSPCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkPCollisionObject::Read(reader, version, user, arg);

}

void bhkSPCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkPCollisionObject::Write(writer, version, user, arg);

}
