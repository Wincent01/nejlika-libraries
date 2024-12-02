#include "bhkSerializable.hpp"

using namespace nejlika::geometry;

void bhkSerializable::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkRefObject::Read(reader, version, user, arg);

}

void bhkSerializable::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkRefObject::Write(writer, version, user, arg);

}
