#include "NiDirectionalLight.hpp"

using namespace nejlika::geometry;

void NiDirectionalLight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiLight::Read(reader, version, user, arg);

}

void NiDirectionalLight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiLight::Write(writer, version, user, arg);

}
