#include "NiPSysAgeDeathModifier.hpp"

using namespace nejlika::geometry;

void NiPSysAgeDeathModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_SpawnOnDeath = reader.Read<bool>();

    m_SpawnModifier.Read(reader, version, user, 0);

}

void NiPSysAgeDeathModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_SpawnOnDeath);

    m_SpawnModifier.Write(writer, version, user, 0);

}
