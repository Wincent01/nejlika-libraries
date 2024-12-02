#include "bhkStiffSpringConstraint.hpp"

using namespace nejlika::geometry;

void bhkStiffSpringConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_PivotA.Read(reader, version, user, 0);

    m_PivotB.Read(reader, version, user, 0);

    m_Length = reader.Read<float>();

}

void bhkStiffSpringConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    m_PivotA.Write(writer, version, user, 0);

    m_PivotB.Write(writer, version, user, 0);

    writer.Write(m_Length);

}
