#include "BSParentVelocityModifier.hpp"

using namespace nejlika::geometry;

void BSParentVelocityModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_Damping = reader.Read<float>();

}

void BSParentVelocityModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_Damping);

}
