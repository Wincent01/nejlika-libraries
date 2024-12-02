#include "bhkConvexShape.hpp"

using namespace nejlika::geometry;

void bhkConvexShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSphereRepShape::Read(reader, version, user, arg);

}

void bhkConvexShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSphereRepShape::Write(writer, version, user, arg);

}
