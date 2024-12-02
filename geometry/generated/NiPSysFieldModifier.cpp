#include "NiPSysFieldModifier.hpp"

using namespace nejlika::geometry;

void NiPSysFieldModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_FieldObject.Read(reader, version, user, 0);

    m_Magnitude = reader.Read<float>();

    m_Attenuation = reader.Read<float>();

    m_UseMaxDistance = reader.Read<bool>();

    m_MaxDistance = reader.Read<float>();

}

void NiPSysFieldModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    m_FieldObject.Write(writer, version, user, 0);

    writer.Write(m_Magnitude);

    writer.Write(m_Attenuation);

    writer.Write(m_UseMaxDistance);

    writer.Write(m_MaxDistance);

}
