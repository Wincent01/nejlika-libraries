#include "NiPSysCollider.hpp"

using namespace nejlika::geometry;

void NiPSysCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Bounce = reader.Read<float>();

    m_SpawnOnCollide = reader.Read<bool>();

    m_DieOnCollide = reader.Read<bool>();

    m_SpawnModifier.Read(reader, version, user, 0);

    m_Parent.Read(reader, version, user, 0);

    m_NextCollider.Read(reader, version, user, 0);

    m_ColliderObject.Read(reader, version, user, 0);

}

void NiPSysCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_Bounce);

    writer.Write(m_SpawnOnCollide);

    writer.Write(m_DieOnCollide);

    m_SpawnModifier.Write(writer, version, user, 0);

    m_Parent.Write(writer, version, user, 0);

    m_NextCollider.Write(writer, version, user, 0);

    m_ColliderObject.Write(writer, version, user, 0);

}
