#include "bhkShapeCollection.hpp"

using namespace nejlika::geometry;

void bhkShapeCollection::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShape::Read(reader, version, user, arg);

}

void bhkShapeCollection::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShape::Write(writer, version, user, arg);

}
