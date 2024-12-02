#include "CapsuleBV.hpp"

using namespace nejlika::geometry;

void CapsuleBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Center.Read(reader, version, user, 0);

    m_Origin.Read(reader, version, user, 0);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

}

void CapsuleBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Center.Write(writer, version, user, 0);

    m_Origin.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

}
