#include "bhkShapePhantom.hpp"

using namespace nejlika::geometry;

void bhkShapePhantom::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkPhantom::Read(reader, version, user, arg);

}

void bhkShapePhantom::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkPhantom::Write(writer, version, user, arg);

}
