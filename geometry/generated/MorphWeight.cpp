#include "MorphWeight.hpp"

using namespace nejlika::geometry;

void MorphWeight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Interpolator.Read(reader, version, user, 0);

    m_Weight = reader.Read<float>();

}

void MorphWeight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Interpolator.Write(writer, version, user, 0);

    writer.Write(m_Weight);

}
