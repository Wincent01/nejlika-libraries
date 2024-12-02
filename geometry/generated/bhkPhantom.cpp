#include "bhkPhantom.hpp"

using namespace nejlika::geometry;

void bhkPhantom::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkWorldObject::Read(reader, version, user, arg);

}

void bhkPhantom::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkWorldObject::Write(writer, version, user, arg);

}
