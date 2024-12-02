#include "NiTexture.hpp"

using namespace nejlika::geometry;

void NiTexture::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObjectNET::Read(reader, version, user, arg);

}

void NiTexture::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObjectNET::Write(writer, version, user, arg);

}
