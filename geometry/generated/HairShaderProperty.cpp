#include "HairShaderProperty.hpp"

using namespace nejlika::geometry;

void HairShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderProperty::Read(reader, version, user, arg);

}

void HairShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderProperty::Write(writer, version, user, arg);

}
