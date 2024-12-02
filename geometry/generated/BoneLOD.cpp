#include "BoneLOD.hpp"

using namespace nejlika::geometry;

void BoneLOD::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Distance = reader.Read<uint>();

    m_BoneName.Read(reader, version, user, 0);

}

void BoneLOD::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Distance);

    m_BoneName.Write(writer, version, user, 0);

}
