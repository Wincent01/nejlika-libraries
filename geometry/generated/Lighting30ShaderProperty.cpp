#include "Lighting30ShaderProperty.hpp"

using namespace nejlika::geometry;

void Lighting30ShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderPPLightingProperty::Read(reader, version, user, arg);

}

void Lighting30ShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderPPLightingProperty::Write(writer, version, user, arg);

}
