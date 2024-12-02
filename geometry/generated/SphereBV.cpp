#include "SphereBV.hpp"

using namespace nejlika::geometry;

void SphereBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Center.Read(reader, version, user, 0);

    m_Radius = reader.Read<float>();

}

void SphereBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Center.Write(writer, version, user, 0);

    writer.Write(m_Radius);

}
