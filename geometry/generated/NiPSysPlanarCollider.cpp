#include "NiPSysPlanarCollider.hpp"

using namespace nejlika::geometry;

void NiPSysPlanarCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysCollider::Read(reader, version, user, arg);

    m_Width = reader.Read<float>();

    m_Height = reader.Read<float>();

    m_XAxis.Read(reader, version, user, 0);

    m_YAxis.Read(reader, version, user, 0);

}

void NiPSysPlanarCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysCollider::Write(writer, version, user, arg);

    writer.Write(m_Width);

    writer.Write(m_Height);

    m_XAxis.Write(writer, version, user, 0);

    m_YAxis.Write(writer, version, user, 0);

}
