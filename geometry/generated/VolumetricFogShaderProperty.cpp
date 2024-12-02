#include "VolumetricFogShaderProperty.hpp"

using namespace nejlika::geometry;

void VolumetricFogShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderProperty::Read(reader, version, user, arg);

}

void VolumetricFogShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderProperty::Write(writer, version, user, arg);

}
