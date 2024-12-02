#include "NiPSysSphericalCollider.hpp"

using namespace nejlika::geometry;

void NiPSysSphericalCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysCollider::Read(reader, version, user, arg);

    m_Radius = reader.Read<float>();

}

void NiPSysSphericalCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysCollider::Write(writer, version, user, arg);

    writer.Write(m_Radius);

}
