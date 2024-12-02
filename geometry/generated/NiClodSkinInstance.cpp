#include "NiClodSkinInstance.hpp"

using namespace nejlika::geometry;

void NiClodSkinInstance::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSkinInstance::Read(reader, version, user, arg);

}

void NiClodSkinInstance::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSkinInstance::Write(writer, version, user, arg);

}
