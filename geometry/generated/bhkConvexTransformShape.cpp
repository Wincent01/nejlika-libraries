#include "bhkConvexTransformShape.hpp"

using namespace nejlika::geometry;

void bhkConvexTransformShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkTransformShape::Read(reader, version, user, arg);

}

void bhkConvexTransformShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkTransformShape::Write(writer, version, user, arg);

}
