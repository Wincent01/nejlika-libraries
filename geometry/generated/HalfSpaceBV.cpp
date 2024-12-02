#include "HalfSpaceBV.hpp"

using namespace nejlika::geometry;

void HalfSpaceBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Normal.Read(reader, version, user, 0);

    m_Center.Read(reader, version, user, 0);

    m_UnknownFloat1 = reader.Read<float>();

}

void HalfSpaceBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Normal.Write(writer, version, user, 0);

    m_Center.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat1);

}
