#include "NiScreenElements.hpp"

using namespace nejlika::geometry;

void NiScreenElements::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriShape::Read(reader, version, user, arg);

}

void NiScreenElements::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriShape::Write(writer, version, user, arg);

}
