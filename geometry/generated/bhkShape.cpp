#include "bhkShape.hpp"

using namespace nejlika::geometry;

void bhkShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSerializable::Read(reader, version, user, arg);

}

void bhkShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSerializable::Write(writer, version, user, arg);

}
