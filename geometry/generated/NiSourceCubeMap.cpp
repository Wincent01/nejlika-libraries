#include "NiSourceCubeMap.hpp"

using namespace nejlika::geometry;

void NiSourceCubeMap::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSourceTexture::Read(reader, version, user, arg);

}

void NiSourceCubeMap::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSourceTexture::Write(writer, version, user, arg);

}
