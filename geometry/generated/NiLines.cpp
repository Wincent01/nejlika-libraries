#include "NiLines.hpp"

using namespace nejlika::geometry;

void NiLines::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriBasedGeom::Read(reader, version, user, arg);

}

void NiLines::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriBasedGeom::Write(writer, version, user, arg);

}
