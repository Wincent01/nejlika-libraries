#include "SkinWeight.hpp"

using namespace nejlika::geometry;

void SkinWeight::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Index = reader.Read<ushort>();

    m_Weight = reader.Read<float>();

}

void SkinWeight::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Index);

    writer.Write(m_Weight);

}
