#include "BSLightingShaderPropertyColorController.hpp"

using namespace nejlika::geometry;

void BSLightingShaderPropertyColorController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

    m_TypeOfControlledColor = reader.Read<LightingShaderControlledColor>();

}

void BSLightingShaderPropertyColorController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

    writer.Write(m_TypeOfControlledColor);

}