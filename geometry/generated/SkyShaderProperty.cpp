#include "SkyShaderProperty.hpp"

using namespace nejlika::geometry;

void SkyShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderProperty::Read(reader, version, user, arg);

    m_UnknownInt4 = reader.Read<int>();

    m_FileName.Read(reader, version, user, 0);

    m_UnknownInt5 = reader.Read<int>();

}

void SkyShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderProperty::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt4);

    m_FileName.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt5);

}
