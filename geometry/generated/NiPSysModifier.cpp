#include "NiPSysModifier.hpp"

using namespace nejlika::geometry;

void NiPSysModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_Order = reader.Read<uint>();

    m_Target.Read(reader, version, user, 0);

    m_Active = reader.Read<bool>();

}

void NiPSysModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    writer.Write(m_Order);

    m_Target.Write(writer, version, user, 0);

    writer.Write(m_Active);

}
