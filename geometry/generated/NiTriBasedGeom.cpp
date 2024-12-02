#include "NiTriBasedGeom.hpp"

using namespace nejlika::geometry;

void NiTriBasedGeom::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiGeometry::Read(reader, version, user, arg);

}

void NiTriBasedGeom::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiGeometry::Write(writer, version, user, arg);

}
