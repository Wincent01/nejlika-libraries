#include "bhkSphereShape.hpp"

using namespace nejlika::geometry;

void bhkSphereShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConvexShape::Read(reader, version, user, arg);

}

void bhkSphereShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConvexShape::Write(writer, version, user, arg);

}
