#include "BSEffectShaderPropertyFloatController.hpp"

using namespace nejlika::geometry;

void BSEffectShaderPropertyFloatController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

    m_TypeOfControlledVariable = reader.Read<EffectShaderControlledVariable>();

}

void BSEffectShaderPropertyFloatController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

    writer.Write(m_TypeOfControlledVariable);

}