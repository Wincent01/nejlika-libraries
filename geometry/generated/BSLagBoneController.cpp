#include "BSLagBoneController.hpp"

using namespace nejlika::geometry;

void BSLagBoneController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_LinearVelocity = reader.Read<float>();

    m_LinearRotation = reader.Read<float>();

    m_MaximumDistance = reader.Read<float>();

}

void BSLagBoneController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_LinearVelocity);

    writer.Write(m_LinearRotation);

    writer.Write(m_MaximumDistance);

}
