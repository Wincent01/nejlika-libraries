#include "NiPSysTurbulenceFieldModifier.hpp"

using namespace nejlika::geometry;

void NiPSysTurbulenceFieldModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysFieldModifier::Read(reader, version, user, arg);

    m_Frequency = reader.Read<float>();

}

void NiPSysTurbulenceFieldModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysFieldModifier::Write(writer, version, user, arg);

    writer.Write(m_Frequency);

}