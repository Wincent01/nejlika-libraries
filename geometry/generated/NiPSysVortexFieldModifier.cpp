#include "NiPSysVortexFieldModifier.hpp"

using namespace nejlika::geometry;

void NiPSysVortexFieldModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysFieldModifier::Read(reader, version, user, arg);

    m_Direction.Read(reader, version, user, 0);

}

void NiPSysVortexFieldModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysFieldModifier::Write(writer, version, user, arg);

    m_Direction.Write(writer, version, user, 0);

}
