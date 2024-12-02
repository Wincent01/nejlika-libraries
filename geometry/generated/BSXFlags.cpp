#include "BSXFlags.hpp"

using namespace nejlika::geometry;

void BSXFlags::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiIntegerExtraData::Read(reader, version, user, arg);

}

void BSXFlags::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiIntegerExtraData::Write(writer, version, user, arg);

}
